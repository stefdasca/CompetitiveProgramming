#include<bits/stdc++.h>
#define god dimasi5eks
#pragma GCC optimize("O3")
#define fi first
#define se second
#define pb push_back
#define pf push_front
#define mod 1000000007

using namespace std;

typedef long long ll;

int n;

int N, nr, viz[2015], Q[2015];
vector < int > v[2015], tr[2015];

void dfs(int nod)
{
    viz[nod] = 1;
    for(int i = 0; i < v[nod].size(); ++i)
    {
        int vecin = v[nod][i];
        if(!viz[vecin])
            dfs(vecin);
    }
    Q[++nr] = nod;
}

void dfp(int nod)
{
    viz[nod] = 1;
    for(int i = 0; i < tr[nod].size(); ++i)
    {
        int vecin = tr[nod][i];
        if(!viz[vecin])
            dfp(vecin);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j)
        {
            int nr;
            cin >> nr;
            if(i != j && nr)
            {
                v[i].pb(j);
                tr[j].pb(i);
            }
        }
    for(int i = 1; i <= n; ++i)
        if(!viz[i])
            dfs(i);
    memset(viz, 0, sizeof(viz));
    dfp(Q[nr]);
    for(int i = 1; i <= n; ++i)
        if(!viz[i])
        {
            cout << "NO";
            return 0;
        }
    cout << "YES";
    return 0;
}

