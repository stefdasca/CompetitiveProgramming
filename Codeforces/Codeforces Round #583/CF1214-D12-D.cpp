#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#define fi first
#define se second
#define pb push_back
#define pf push_front
#define mod 1000000007

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
int nr, n, m;
int nodd = 0;
vector<char>v2[1000002];
vector<int>v[1000002], sol[1000002], viz2[1000002], adj2[1000002], viz3[1000002];
bool viz[1000002];
int niv[1000002], low[1000002];
deque<int>d;
void dfs(int dad, int nod)
{
    viz[nod] = 1;
    low[nod] = niv[nod];
    d.push_back(nod);
    for(int i = 0; i < v[nod].size(); ++i)
    {
        int vecin = v[nod][i];
        if(vecin == dad)
            continue;
        if(viz[vecin])
        {
            low[nod] = min(low[nod], niv[vecin]);
            continue;
        }
        niv[vecin] = niv[nod] + 1;
        dfs(nod, vecin);
        low[nod] = min(low[nod], low[vecin]);
        if(low[vecin] >= niv[nod])
        {
            if(nod != 1 && nod != nodd)
                nr = 1;
            int lst;
            do
            {
                sol[nr].push_back(d.back());
                lst = d.back();
                d.pop_back();
            }while(!d.empty() && lst != vecin);
            sol[nr].push_back(nod);
        }
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
            char c;
            cin >> c;
            v2[i].push_back(c);
            viz2[i].push_back(0);
            adj2[i].push_back(0);
            viz3[i].push_back(0);
        }

    viz2[1][0] = 1;
    viz3[1][0] = 1;
    for(int i = 1; i <= n; ++i)
        for(int j = 0; j < m; ++j)
        {
            if(viz2[i][j])
            {
                if(i+1 <= n && v2[i+1][j] != '#')
                    viz3[i+1][j] = 1, viz2[i+1][j] = 1;
                if(j+1 < m && v2[i][j+1] != '#')
                    viz3[i][j+1] = 1, viz2[i][j+1] = 1;
            }
        }
    if(!viz2[n][m-1])
    {
        cout << 0;
        return 0;
    }
    if(n == 1 || m == 1)
    {
        cout << 1;
        return 0;
    }
    for(int i = 1; i <= n; ++i)
        for(int j = 0; j < m; ++j)
            viz2[i][j] = 0;
    viz2[n][m-1] = 1;
    for(int i = n; i >= 1; --i)
        for(int j = m-1; j >= 0; --j)
        {
            if(viz2[i][j] && v2[i][j] != '#' && viz3[i][j])
            {
                ++nodd;
                adj2[i][j] = nodd;
                if(i - 1 >= 1 && v2[i-1][j] != '#' && viz3[i-1][j])
                    viz2[i-1][j] = 1;
                if(j-1 >= 0 && v2[i][j-1] != '#' && viz3[i][j-1])
                    viz2[i][j-1] = 1;
                if(i+1 <= n && viz2[i+1][j])
                {
                    v[nodd].push_back(adj2[i+1][j]);
                    v[adj2[i+1][j]].push_back(nodd);
                }
                if(j+1 < m && viz2[i][j+1])
                {
                    v[nodd].push_back(adj2[i][j+1]);
                    v[adj2[i][j+1]].push_back(nodd);
                }
            }
        }
    nr = 0;
    dfs(0, 1);
    if(nr == 0)
    {
        cout << 2;
        return 0;
    }
    cout << 1;
    return 0;
}
