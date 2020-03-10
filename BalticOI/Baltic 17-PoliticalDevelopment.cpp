/*
        Baltic 17-PoliticalDevelopment

    Since the answer is guaranteed to be at most k, we can fix the vertex with the smallest degree from an optimal clique.
For a group of vertexes adjacent to the current vertex, we can run bruteforce to find for each of the cliques whether it is the optimal one.
In order to avoid TLE, I only check cliques which can actually modify the answer.

*/
#include<bits/stdc++.h>
#define god dimasi5eks
#pragma GCC optimize("O3")
#define fi first
#define se second
#define pb push_back
#define pf push_front
#define mod 1000000007
#define dancila 3.14159265359
#define eps 1e-9

// #define fisier 1

using namespace std;

typedef long long ll;


int n, m, k, gr[50002], viz[50002], scos[50002];
int ans = 1;
vector<int> v[50002];
bitset<50002> adj[50002]; // memory optimization

void tri(int nod)
{
    vector<int> vals;
    vals.pb(nod);
    for(int i = 0; i < v[nod].size(); ++i)
    {
        int vecin = v[nod][i];
        if(!scos[vecin])
            vals.pb(vecin);
    }
    for(int i = 1; i < (1<<vals.size()); ++i)
    {
        vector<int> cr;
        for(int j = 0; j < vals.size(); ++j)
            if(i & (1<<j))
                cr.pb(vals[j]);
        if(cr.size() <= ans)
            continue;
        bool ok = 1;
        for(int j = 0; ok && j < cr.size(); ++j)
            for(int x = j+1; ok && x < cr.size(); ++x)
                if(adj[cr[j]][cr[x]] == 0)
                    ok = 0;
        if(ok)
            ans = cr.size();
    }
}
int main()
{

    #ifdef fisier
        ifstream f("input.in");
        ofstream g("output.out");
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    for(int i = 1; i <= n; ++i)
    {
        int sz;
        cin >> sz;
        gr[i] = sz;
        for(; sz; --sz)
        {
            int vc;
            cin >> vc;
            ++vc;
            v[i].pb(vc);
            adj[i][vc] = 1;
        }
    }
    deque<int> d;
    for(int i = 1; i <= n; ++i)
        if(gr[i] < k)
            d.pb(i), viz[i] = 1;

    while(!d.empty())
    {
        int nod = d[0];
        d.pop_front();
        scos[nod] = 1;
        tri(nod);
        for(int i = 0; i < v[nod].size(); ++i)
        {
            int vecin = v[nod][i];
            --gr[vecin];
            if(gr[vecin] < k && !viz[vecin])
            {
                viz[vecin] = 1;
                d.pb(vecin);
            }
        }
    }
    cout << ans;
    return 0;
}
