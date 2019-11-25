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


int add(int a, int b)
{
    ll x = a+b;
    if(x >= mod)
        x -= mod;
    if(x < 0)
        x += mod;
    return x;
}
ll mul(ll a, ll b)
{
    return (a*b) % mod;
}

ll pw(ll a, ll b)
{
    ll ans = 1;
    while(b)
    {
        if(b & 1)
            ans = (ans * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return ans;
}

int n, m;
vector<vector<int> >ps;
vector<vector<int> >viz;
vector<string>map1, map2;

int ox[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int oy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
bool chk(int mid)
{
    deque<pair<int, int> >d;
    bool ok = 1;
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j)
        {
            viz[i][j] = 0;
            if(i >= mid && j >= mid && i + mid < n && j + mid < m)
            {
                int sumx = ps[i + mid][j + mid];
                if(i > mid)
                    sumx -= ps[i - mid - 1][j + mid];
                if(j > mid)
                    sumx -= ps[i + mid][j - mid - 1];
                if(i > mid && j > mid)
                    sumx += ps[i - mid - 1][j - mid - 1];
                if(sumx == (mid + mid + 1) * (mid + mid + 1))
                {
                     d.pb({i, j});
                     viz[i][j] = 1;
                }
            }
        }
    for(int i = 1; i <= mid; ++i)
    {
        if(!ok)
            break;
        deque<pair<int, int> >d2;
        while(!d.empty())
        {
            pair<int, int> nd = d[0];
            d.pop_front();
            if(map1[nd.fi][nd.se] == '.')
            {
                ok = 0;
                break;
            }
            for(int j = 0; j <= 7; ++j)
            {
                int nx = nd.fi + ox[j];
                int ny = nd.se + oy[j];
                if(nx < 0 || ny < 0 || nx >= n || ny >= m)
                {
                    ok = 0;
                    break;
                }
                if(!viz[nx][ny])
                {
                    viz[nx][ny] = 1;
                    d2.pb({nx, ny});
                }
            }
            if(ok == 0)
                break;
        }
        d = d2;
    }
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j)
            if(viz[i][j] && map1[i][j] == '.')
                ok = 0;
            else
                if(!viz[i][j] && map1[i][j] == 'X')
                    ok = 0;
    if(ok == 1)
    {
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j)
            {
                map2[i][j] = '.';
                int sumx = 0;
                if(i >= mid && j >= mid && i + mid < n && j + mid < m)
                {
                    int sumx = ps[i + mid][j + mid];
                    if(i > mid)
                        sumx -= ps[i - mid - 1][j + mid];
                    if(j > mid)
                        sumx -= ps[i + mid][j - mid - 1];
                    if(i > mid && j > mid)
                        sumx += ps[i - mid - 1][j - mid - 1];
                    if(sumx == (mid + mid + 1) * (mid + mid + 1))
                        map2[i][j] = 'X';
                }
            }
        return 1;
    }
    return 0;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    vector<int> x;
    for(int j = 0; j < m; ++j)
        x.pb(0);
    for(int i = 1; i <= n; ++i)
    {
        string s;
        cin >> s;
        map1.pb(s);
        map2.pb(s);
        ps.pb(x);
        viz.pb(x);
    }
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j)
        {
            ps[i][j] = 0;
            if(map1[i][j] == 'X')
                ps[i][j]++;
            if(i > 0)
                ps[i][j] += ps[i-1][j];
            if(j > 0)
                ps[i][j] += ps[i][j-1];
            if(i > 0 && j > 0)
                ps[i][j] -= ps[i-1][j-1];
        }
    int st = 0;
    int dr = min(n, m);
    int ans = 0;
    while(st <= dr)
    {
        int mid = (st + dr) / 2;
        if(chk(mid))
            ans = mid, st = mid + 1;
        else
            dr = mid - 1;
    }
    cout << ans << '\n';
    for(int i = 0; i < n; ++i)
        cout << map2[i] << '\n';
    return 0;
}
