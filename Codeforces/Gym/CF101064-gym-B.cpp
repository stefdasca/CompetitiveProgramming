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
int dp[62][62][62][62][2];
int solve(int a1, int a2, int a3, int a4, int fc)
{
    if(a1 + a2 + a3 + a4 == 0)
        return fc;
    if(dp[a1][a2][a3][a4][fc] != -1)
        return dp[a1][a2][a3][a4][fc];
    int &rez = dp[a1][a2][a3][a4][fc];
    rez = 0;
    for(int i = 1; i <= a1; ++i)
		rez = add(rez, solve(i - 1, a2 + a1 - i, a3, a4, fc));
	for(int i = 1; i <= a2; ++i)
		rez = add(rez, solve(a1, i - 1, a3 + a2 - i, a4, fc));
	for(int i = 1; i <= a3; ++i)
		rez = add(rez, solve(a1, a2, i - 1, a4 + a3 - i, 1));
	if(a4)
		rez = add(rez, solve(a1, a2, a3, a4 - 1,1));
	return rez;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    memset(dp, -1, sizeof(dp));
    ll ans = 1;
    for(int i = 2; i <= n; ++i)
        ans = (ans * i) % mod;
    ans = ans + mod - solve(n, 0, 0, 0, 0);
    if(ans >= mod)
        ans -= mod;
    cout << ans;
    return 0;
}
