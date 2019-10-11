// https://infoarena.ro/problema/cubeon

#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int n, k, t;
long long a[1000002], sp[1000002];
long long dp[2][1000002];
long long C(int a, int b)
{
    long long val = sp[b] - sp[a-1];
    return val*val*val;
}
void compute(int i, int st, int dr, int optst, int optdr)
{
    if(st > dr)
        return;
    int mid = (st + dr) / 2;
    pair<long long, int> best = {(1LL<<60), -1};
    for (int k = optst; k <= min(mid, optdr); k++)
        best = min(best, {dp[1-i][k-1] + C(k, mid), k});
    dp[i][mid] = best.first;
    int opt = best.second;
    compute(i, st, mid - 1, optst, opt);
    compute(i, mid + 1, dr, opt, optdr);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    for(; t; --t)
    {
        cin >> n >> k;
        for(int i = 1; i <= n; ++i)
            cin >> a[i];
        for(int i = 1; i <= n; ++i)
            sp[i] = sp[i-1] + a[i];
        long long ss = 0;
        for(int i = 1; i <= n; ++i)
        {
            ss = ss + a[i];
            dp[1][i] = ss * ss * ss;
        }
        for(int i = 2; i <= k; ++i)
            compute(i%2, i, n, i, n);
        cout << dp[k%2][n] << '\n';
    }
    return 0;
}
