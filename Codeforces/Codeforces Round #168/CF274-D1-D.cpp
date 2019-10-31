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

int n, m, gr[100005];
vector<int>v[100005];
vector<pair<int, int> >grup[100005], grup2[100005];

int grad[100005];

map<pair<int, int>, int>ct;
set<pair<int, int> >proc;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
            int x;
            cin >> x;
            v[i].pb(x);
            grup[i].pb({0, j});
        }
    }
    for(int i = 0; i < n; ++i)
    {
        map<int, int> vx;
        vector<int>val = v[i];
        sort(val.begin(), val.end());
        int nr = 0;
        for(int j = 0; j < val.size(); ++j)
        {
            if(j != 0 && val[j] > val[j-1] && val[j-1] != -1)
                ++nr;
            if(val[j] != -1)
                ct[{nr, i}]++;
            vx[val[j]] = nr;
        }
        for(int j = 0; j < v[i].size(); ++j)
        {
            grup[i][j].fi = vx[v[i][j]];
            if(grup[i][j].fi != 0)
                ++gr[grup[i][j].se];
        }
        grup2[i] = grup[i];
        sort(grup[i].begin(), grup[i].end());
    }
    deque<int>d;
    vector<int>ans;
    for(int i = 0; i < m; ++i)
        if(!gr[i])
            d.pb(i);
    while(!d.empty())
    {
        ans.pb(d[0]);
        int nod = d[0];
        d.pop_front();
        for(int i = 0; i < n; ++i)
        {
            pair<int, int> par = grup2[i][nod];
            if(v[i][nod] == -1)
                continue;
            --ct[{par.fi, i}];
            if(!ct[{par.fi, i}])
            {
                int st = 0;
                int dr = m - 1;
                int ans = -1;
                while(st <= dr)
                {
                    int mid = (st + dr) / 2;
                    if(grup[i][mid].fi > par.fi)
                        ans = mid, dr = mid - 1;
                    else
                        st = mid + 1;
                }
                if(ans == -1)
                    continue;
                int z = ans;
                while(z < grup[i].size() && grup[i][z].fi == grup[i][ans].fi)
                {
                    --gr[grup[i][z].se];
                    if(!gr[grup[i][z].se])
                        d.pb(grup[i][z].se);
                    ++z;
                }
            }
        }
    }
    if(ans.size() != m)
        cout << -1;
    else
    {
        for(int i = 0; i < ans.size(); ++i)
            cout << ans[i] + 1 << " ";
        cout << '\n';
    }
    return 0;
}
