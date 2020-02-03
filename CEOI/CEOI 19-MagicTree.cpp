/*
        CEOI 19-MagicTree

    Same solution as the official editorial(https://codeforces.com/blog/entry/68748), but for the simplicity of implementation
we are going to use maps in order to implement the solution.

    In order to speed up the runtime, we are going to use small-to-large trick for merging maps.

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

int n, q, k, nr, num[100002], pos[100002];

int zi[100002], value[100002];
vector<int> v[100002];
pair<int, int> p[100002];
map<int, ll> s[100002];
map<int, ll> ::iterator it, itf, its;
void dfs(int nod)
{
    num[nod] = 1;
    int vecin, sum;
    for(int i = 0; i < v[nod].size(); i++)
    {
        int vecin = v[nod][i];
        dfs(vecin);
        num[nod] += num[vecin];
        if(num[vecin] > num[pos[nod]])
            pos[nod] = vecin;
    }
    pos[nod] = pos[pos[nod]];
    if(v[nod].size() == 0)
        pos[nod] = ++nr;
    for(int i = 0; i < v[nod].size(); i++)
    {
        int vecin = pos[v[nod][i]];
        if(vecin != pos[nod])
            for(it = s[vecin].begin(); it != s[vecin].end(); it++)
                s[pos[nod]][it -> fi] += it -> se;
    }
    if(zi[nod] != 0)
    {
        s[pos[nod]][zi[nod]] += value[nod];
        ll sum = 0;
        it = s[pos[nod]].upper_bound(zi[nod]);
        itf = it;
        while(it != s[pos[nod]].end() && sum + it -> se <= value[nod])
        {
            sum += it -> se;
            it -> se = 0;
            its = it;
            it++;
        }
        if(it != s[pos[nod]].end())
            it -> se += sum - value[nod];
        if(it != itf)
            s[pos[nod]].erase(itf, its);
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

    cin >> n >> q >> k;
    for(int i = 2; i <= n; ++i)
    {
        int pi;
        cin >> pi;
        v[pi].pb(i);
    }
    for(int i = 1; i <= q; ++i)
    {
        int nod;
        cin >> nod;
        cin >> zi[nod] >> value[nod];
    }
    dfs(1);
    ll ans = 0;
    int x = pos[1];
    for(it = s[x].begin(); it != s[x].end(); ++it)
        ans += it -> se;
    cout << ans;
    return 0;
}
