#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#define fi first
#define se second
#define pb push_back
#define pf push_front
#define mod 998244353

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
int n, sp[52][52], dp[52][52][52][52];
char c[52][52];
int get(int xa, int ya, int xb, int yb)
{
    return sp[xb][yb] - sp[xa-1][yb] - sp[xb][ya-1] + sp[xa-1][ya-1];
}
int calc(int xa, int ya, int xb, int yb)
{
    if(dp[xa][ya][xb][yb] != -1)
        return dp[xa][ya][xb][yb];
    if(get(xa, ya, xb, yb) == 0)
        return dp[xa][ya][xb][yb] = 0;
    dp[xa][ya][xb][yb] = max(xb-xa, yb-ya)+1;
    for(int i = xa; i < xb; ++i)
        dp[xa][ya][xb][yb] = min(dp[xa][ya][xb][yb], calc(xa, ya, i, yb) + calc(i+1, ya, xb, yb));
    for(int i = ya; i < yb; ++i)
        dp[xa][ya][xb][yb] = min(dp[xa][ya][xb][yb], calc(xa, ya, xb, i) + calc(xa, i+1, xb, yb));
    return dp[xa][ya][xb][yb];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> (c[i] + 1);
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j)
            sp[i][j] = sp[i-1][j] + sp[i][j-1] - sp[i-1][j-1] + (c[i][j] == '#');
    memset(dp, -1, sizeof(dp));
    calc(1, 1, n, n);
    cout << dp[1][1][n][n];
    return 0;
}

