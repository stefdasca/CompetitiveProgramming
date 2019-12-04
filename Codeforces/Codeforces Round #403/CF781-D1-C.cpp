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

using namespace std;

typedef long long ll;

int n, m, k, viz[200002];
vector<int> v[200002], ans[200002];
int mx, xp = 1;
void dfs(int dad, int nod)
{
    ans[xp].pb(nod);
    if(ans[xp].size() == mx)
        ++xp;
    viz[nod] = 1;
    for(int i = 0; i < v[nod].size(); ++i)
    {
        int vecin = v[nod][i];
        if(!viz[vecin])
        {
            dfs(nod, vecin);
            ans[xp].pb(nod);
            if(ans[xp].size() == mx)
                ++xp;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> k;
    mx = (2 * n) / k;
    if((2 * n) % k != 0)
        ++mx;
    for(int i = 1; i <= m; ++i)
    {
        int a, b;
        cin >> a >> b;
        v[a].pb(b);
        v[b].pb(a);
    }
    dfs(0, 1);
    for(int i = 1; i <= k; ++i)
    {
        if(ans[i].size() == 0)
            ans[i].pb(1);
        cout << ans[i].size() << " ";
        for(int j = 0; j < ans[i].size(); ++j)
            cout << ans[i][j] << " ";
        cout << '\n';
    }
    return 0;
}
