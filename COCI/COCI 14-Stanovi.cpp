/*
            COCI 14-Stanovi

    * We have to notice that it's optimal to cut a rectangle of size (x * y) using either an horizontal cut(rectangle of size z * y)
or a vertical cut(rectangle of size x * z)

    * Since we are constrained by the fact that every rectangle has to border one of the sides of the rectangle, we have to keep extra four
dimensions to mark us whether we have one side which shares a border with the inital rectangle.

    * Therefore, for a certain rectangle, we can either use the whole rectangle or cut it using the cuts described above. We will solve this recursively
in O(n^3).

    * In order to make the program faster, write dp[2][2][2][2][Nmax][Nmax] instead of dp[Nmax][Nmax][2][2][2][2], because of the way memory allocation
works.

*/
#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#define fi first
#define se second
#define pb push_back
#define pf push_front
#define mod 1000000007

using namespace std;
typedef long long ll;

ll n, m, k;
ll dp[2][2][2][2][302][302];
ll solve (int a, int b, int L, int R, int U, int D)
{
    if (L && R && U && D)
        return (1LL<<60);
    if (dp[L][R][U][D][a][b] != -1)
        return dp[L][R][U][D][a][b];
    if (a > b)
        return dp[L][R][U][D][a][b] = solve(b, a, U, D, R, L);
    if (L > R)
        return dp[L][R][U][D][a][b] = solve(a, b, R, L, U, D);
    if (U > D)
        return dp[L][R][U][D][a][b] = solve(a, b, L, R, D, U);

    ll ans = a * b - k;
    ans *= ans;
    if (a >= 2 && solve(1, b, L, 1, U, D) + solve(a - 1, b, 1, R, U, D) < (1LL<<60))
        for (int k = 1; k <= a - 1; ++k)
            ans = min(ans, solve(k, b, L, 1, U, D) + solve(a - k, b, 1, R, U, D));

    if (b >= 2 && solve(a, 1, L, R, 1, D) + solve(a, b - 1, L, R, U, 1) < (1LL<<60))
        for (int k = 1; k <= b - 1; ++k)
            ans = min(ans, solve(a, k, L, R, 1, D) + solve(a, b - k, L, R, U, 1));

    dp[L][R][U][D][a][b] = ans;
    return dp[L][R][U][D][a][b];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> k;
    memset(dp, -1, sizeof(dp));
    cout << solve(n, m, 0, 0, 0, 0);
    return 0;
}

