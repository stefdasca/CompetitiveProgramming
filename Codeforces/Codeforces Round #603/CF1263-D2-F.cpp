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
int n, a, b, sts[2002], sts2[2002], lvl[2002], lvl2[2002], poz[2002], poz2[2002];
int mnn[2002], mxx[2002];
int mnn2[2002], mxx2[2002];
int val[2002][2002], val2[2002][2002];
vector<int> v1[2002], v2[2002];
pair<int, int> dev[2002];
void dfs(int dad, int nod)
{
    sts[nod] = 1;
    if(poz[nod] != 0)
        mnn[nod] = mxx[nod] = poz[nod];
    else
        mnn[nod] = 2001, mxx[nod] = 0;
    for(int i = 0; i < v1[nod].size(); ++i)
    {
        int vecin = v1[nod][i];
        if(vecin == dad)
            continue;
        lvl[vecin] = lvl[nod] + 1;
        dfs(nod, vecin);
        mnn[nod] = min(mnn[nod], mnn[vecin]);
        mxx[nod] = max(mxx[nod], mxx[vecin]);
        sts[nod] = sts[nod] + sts[vecin];
    }
    val[mnn[nod]][mxx[nod]] = max(val[mnn[nod]][mxx[nod]], sts[nod] - (sts[nod] == a));
}
void dfs2(int dad, int nod)
{
    sts2[nod] = 1;
    if(poz2[nod] != 0)
        mnn2[nod] = mxx2[nod] = poz2[nod];
    else
        mnn2[nod] = 2001, mxx2[nod] = 0;
    for(int i = 0; i < v2[nod].size(); ++i)
    {
        int vecin = v2[nod][i];
        if(vecin == dad)
            continue;
        lvl2[nod] = lvl2[vecin] + 1;
        dfs2(nod, vecin);
        sts2[nod] = sts2[nod] + sts2[vecin];
        mnn2[nod] = min(mnn2[nod], mnn2[vecin]);
        mxx2[nod] = max(mxx2[nod], mxx2[vecin]);
    }
    val2[mnn2[nod]][mxx2[nod]] = max(val2[mnn2[nod]][mxx2[nod]], sts2[nod] - (sts2[nod] == b ));
}
int dp[2002];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    cin >> a;
    for(int i = 1; i < a; ++i)
    {
        int x;
        cin >> x;
        v1[x].push_back(i+1);
        v1[i+1].push_back(x);
    }
    for(int i = 1; i <= n; ++i)
        cin >> dev[i].first, poz[dev[i].first] = i;
    cin >> b;
    for(int i = 1; i < b; ++i)
    {
        int x;
        cin >> x;
        v2[x].push_back(i+1);
        v2[i+1].push_back(x);
    }
    for(int i = 1; i <= n; ++i)
        cin >> dev[i].second, poz2[dev[i].second] = i;
    dfs(0, 1);
    dfs2(0, 1);
    for(int i = 1; i <= n; ++i)
    {
        dp[i] = max(dp[i], dp[i-1]);
        for(int j = 1; j <= i; ++j)
        {
            dp[i] = max(dp[i], dp[j-1] + val[j][i]);
            dp[i] = max(dp[i], dp[j-1] + val2[j][i]);
        }
    }
    cout << dp[n];
    return 0;
}
