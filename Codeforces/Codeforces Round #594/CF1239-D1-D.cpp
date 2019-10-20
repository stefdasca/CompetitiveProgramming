#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#define fi first
#define se second
#define pb push_back
#define pf push_front
#define mod 1000000007

using namespace std;

typedef long long ll;

int t, n, m, nr;
vector<int>v[1000002], tr[1000002], ctc[1000002];
bool viz[1000002], viz2[1000002];
int poz[1000002];
stack<int>s;
set<int>nd;
void dfs(int nod)
{
    viz[nod] = 1;
    for(int j = 0; j < v[nod].size(); ++j)
    {
        int vecin = v[nod][j];
        if(!viz[vecin])
            dfs(vecin);
    }
    s.push(nod);
}
void dfs2(int nod)
{
    viz2[nod] = 1;
    ctc[nr].push_back(nod);
    nd.insert(nod);
    poz[nod] = nr;
    for(int j = 0; j < tr[nod].size(); ++j)
    {
        int vecin = tr[nod][j];
        if(!viz2[vecin])
            dfs2(vecin);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    for(; t; --t)
    {
        for(int i = 1; i <= n; ++i)
        {
            tr[i].clear();
            v[i].clear();
            viz[i] = 0;
            poz[i] = 0;
            viz2[i] = 0;
        }
        for(int i = 1; i <= nr; ++i)
            ctc[i].clear();
        nr = 0;
        cin >> n >> m;
        for(int i = 1; i <= m; ++i)
        {
            int a, b;
            cin >> a >> b;
            v[a].pb(b);
            tr[b].pb(a);
        }
        for(int i = 1; i <= n; ++i)
            if(!viz[i])
                dfs(i);
        bool bad = 1;
        while(!s.empty())
        {
            int nod = s.top();
            s.pop();
            if(!viz2[nod])
            {
                ++nr;
                nd.clear();
                dfs2(nod);
                if(bad)
                {
                    bool evil = (ctc[nr].size() == n);
                    for(int i = 0; i < ctc[nr].size(); ++i)
                    {
                        for(int j = 0; j < v[ctc[nr][i]].size(); ++j)
                        {
                            int vecin = v[ctc[nr][i]][j];
                            if(nd.find(vecin) == nd.end())
                                evil = 1;
                        }
                    }
                    if(!evil)
                    {
                        bad = 0;
                        cout << "Yes\n";
                        cout << ctc[nr].size() << " " << n - ctc[nr].size() << '\n';
                        for(int i = 0; i < ctc[nr].size(); ++i)
                            cout << ctc[nr][i] << " ";
                        cout << '\n';
                        for(int i = 1; i <= n; ++i)
                            if(nd.find(i) == nd.end())
                                cout << i << " ";
                        cout << '\n';
                    }
                }
            }
        }
        if(bad == 1)
            cout << "No\n";
    }
    return 0;
}
