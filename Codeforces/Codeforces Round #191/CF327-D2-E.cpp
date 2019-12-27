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
    int x = a+b;
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
int n, v[25], dp[(1<<24) + 4], k, rau, rau2, ta[28];
int summ[(1<<24) + 4];
bool bg[(1<<24) + 4];
int bz[25], x;
int p2[(1<<24) + 4];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; ++i)
        cin >> v[i];
    cin >> k;
    ll ans = 1;
    int xx = 0;
    for(int i = 1; i <= (1<<24); i *= 2)
        p2[i] = xx, ++xx;
    if(!k)
    {
        for(int i = 1; i <= n; ++i)
            ans = mul(ans, i);
        cout << ans;
        return 0;
    }
    for(int i = 0; i < n; ++i)
        summ[(1<<i)] = v[i];
    if(k)
        cin >> rau;
    else
        rau = -1;
    if(k >= 2)
        cin >> rau2;
    else
        rau2 = -1;
    if(rau > rau2)
        swap(rau, rau2);
    for(int i = 3; i < (1<<n); ++i)
    {
        if((i & (i-1)) == 0)
            continue;
        int prv = i - (i & (-i));
        if(bg[prv] || bg[i ^ prv])
            summ[i] = -2, bg[i] = 1;
        else
        {
            summ[i] = summ[prv] + summ[i ^ prv];
            if(summ[i] > rau2)
                bg[i] = 1;
        }
    }
    dp[0] = 1;
    for(int i = 0; i < (1<<n); ++i)
    {
        int sum = summ[i];
        if(sum == rau2 || sum == rau)
            continue;
        int nr = i;
        x = 0;
        while(nr)
        {
            bz[++x] = (nr & (-nr));
            nr -= bz[x];
        }
        for(int j = 1; j <= x; ++j)
            dp[i] = add(dp[i], dp[i ^ bz[j]]);
    }
    cout << dp[(1<<n) - 1];
    return 0;
}
