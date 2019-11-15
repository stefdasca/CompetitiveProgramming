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

int n, m, k, timp[100002];

vector<int>ccmin, cc;

int egal(int a, int b)
{
    if(a % k == b % k)
        return 1;
    return 0;
}

int nr, wh[100002];
bool viz[100002], viz2[100002];
vector<int>v[100002], tr[100002], ctc[100002];
stack<int>s;

bool nok[100002];
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
    wh[nod] = nr;
    ctc[nr].push_back(nod);
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
    cin >> n >> m >> k;
    for(int i = 1; i <= n; ++i)
        cin >> timp[i];
    for(int i = 1; i <= m; ++i)
    {
        int x, y;
        cin >> x >> y;
        if(egal(timp[x] + 1, timp[y]))
            v[x].pb(y), tr[y].pb(x);
        if(egal(timp[y] + 1, timp[x]))
            v[y].pb(x), tr[x].pb(y);
    }
    for(int i = 1; i <= n; ++i)
        if(!viz[i])
            dfs(i);
    while(!s.empty())
    {
        int nod = s.top();
        s.pop();
        if(!viz2[nod])
        {
            ++nr;
            dfs2(nod);
        }
    }
    for(int i = nr; i >= 1; --i)
    {
        if(i == nr)
            ccmin = ctc[i];
        else
        {
            if(!nok[i])
                if(ctc[i].size() < ccmin.size())
                    ccmin = ctc[i];
        }
        for(int j = 0; j < ctc[i].size(); ++j)
        {
            for(int jj = 0; jj < tr[ctc[i][j]].size(); ++jj)
            {
                int vc = tr[ctc[i][j]][jj];
                nok[wh[vc]] = 1;
            }
        }
    }
    cout << ccmin.size() << '\n';
    for(int i = 0; i < ccmin.size(); ++i)
        cout << ccmin[i] << " ";
    return 0;
}

