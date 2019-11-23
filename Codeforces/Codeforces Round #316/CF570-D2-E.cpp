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

int n, m;
int add(int a, int b)
{
    ll x = a+b;
    if(x >= mod)
        x -= mod;
    if(x < 0)
        x += mod;
    return x;
}

char a[502][502];

int dp[3][502][502];

int dist(int a, int b, int c, int d)
{
    return c - a + d - b;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i = 1; i <= n; ++i)
        cin >> (a[i] + 1);
    int ans = 0;
    for(int L1 = 1; L1 <= n; ++L1)
    {
        for(int C1 = 1; C1 <= m; ++C1)
            for(int L2 = n; L2 >= 1; --L2)
            {
                int C2 = n + m + 2 - L1 - C1 - L2;
                if(L1 > L2 || C1 > C2)
                    continue;
                if(dist(1, 1, L1, C1) != dist(L2, C2, n, m))
                    continue;
                if(a[L1][C1] != a[L2][C2])
                    continue;
                if(L1 == 1 && C1 == 1)
                    dp[2][C1][L2] = 1;
                else
                {
                    dp[2][C1][L2] = add(dp[1][C1][L2], dp[1][C1][L2 + 1]);
                    dp[2][C1][L2] = add(dp[2][C1][L2], add(dp[2][C1 - 1][L2], dp[2][C1 - 1][L2 + 1]));
                }
                if(abs(L1 - L2) + abs(C1 - C2) <= 1)
                    ans = add(ans, dp[2][C1][L2]);
            }
        memcpy(dp[1], dp[2], sizeof(dp[2]));
        memset(dp[2], 0, sizeof(dp[2]));
    }
    cout << ans << '\n';
    return 0;
}
