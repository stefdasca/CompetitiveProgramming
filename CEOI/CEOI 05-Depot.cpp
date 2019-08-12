/*

    editorial = https://github.com/mostafa-saad/MyCompetitiveProgramming/blob/master/Olympiad/CEOI/official/2005/soldepot.pdf

*/
#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#define fi first
#define se second
#define pb push_back
#define pf push_front
#define mod 1000000007

using namespace std;

typedef long long ll;

int n, m;
vector<int>pos[502][502], edges;
vector<pair<int, int> >gr[1002];
int st[1002];
void euler(int nod)
{
    for(; st[nod] < gr[nod].size(); )
    {
        pair<int,int> p = gr[nod][st[nod]];
        st[nod]++;
        euler(p.fi);
        if(p.se != -1)
            edges.pb(p.se);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
        {
            int a;
            cin >> a;
            pos[a][i].pb((i-1) * m + j);
        }
    for(int i = 1; i <= m; ++i)
        for(int j = 1; j <= n; ++j)
        {
            for(int k = 1; k < pos[i][j].size(); k++)
                gr[m + j].pb({i, pos[i][j][k]});
            if(pos[i][j].empty())
                gr[i].pb({m + j, -1});
        }
    vector<pair<int, int> >ans;
    for(int i = 1; i <= n + m; ++i)
    {
        euler(i);
        if(edges.size())
        {
            ans.pb({edges.front(), n*m+1});
            for(int i = 1; i < edges.size(); i++)
                ans.pb({edges[i], edges[i-1]});
            ans.pb({n*m+1, edges.back()});
            edges.clear();
        }
    }
    cout << ans.size() << '\n';
    for(int i = 0; i < ans.size(); ++i)
        cout << ans[i].first << " " << ans[i].second << '\n';
    return 0;
}
