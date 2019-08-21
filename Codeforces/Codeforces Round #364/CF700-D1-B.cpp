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

int n, k;
vector<int>v[200002];
int countt[200002];
bool need[200002];
ll ans, dis[200002];
void dfs(int dad, int nod)
{
    countt[nod] = need[nod];
    for(int i = 0; i < v[nod].size(); ++i)
    {
        int vecin = v[nod][i];
        if(vecin == dad)
            continue;
        dfs(nod, vecin);
        countt[nod] += countt[vecin];
        dis[nod] += dis[vecin] + countt[vecin];
    }
}
void dfs2(int dad, int nod, int ct, ll diss)
{
    int mxx = ct;
    for(int i = 0; i < v[nod].size(); ++i)
    {
        int vecin = v[nod][i];
        if(vecin == dad)
            continue;
        mxx = max(mxx, countt[vecin]);
        dfs2(nod, vecin, ct + countt[nod] - countt[vecin], (diss + ct) + (dis[nod] - dis[vecin] - countt[vecin]) + countt[nod] - countt[vecin]);
    }
    if(mxx <= k)
        ans = max(ans, diss + dis[nod]);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;
    for(int i = 1; i <= k+k; ++i)
    {
        int x;
        cin >> x;
        need[x] = 1;
    }
    for(int i = 1; i < n; ++i)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(0, 1);
    dfs2(0, 1, 0, 0);
    cout << ans;
    return 0;
}
