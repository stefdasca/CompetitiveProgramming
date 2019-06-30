#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#define mod 1000000007
using namespace std;
int n, m;
long long a[12][100002];
long long pos[12][100002];
long long prod[12][100002];
long long p10[100002];
long long modpow(long long b, long long ex)
{
    long long sol = 1;
    while(ex)
    {
        if(ex & 1)
            sol = (sol * b) % mod;
        b = (b*b) % mod;
        ex >>= 1;
    }
    return sol;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    // shuffle(permutation.begin(), permutation.end(), rng);
    cin>>n>>m;
    p10[0] = 1;
    for(int i = 1; i <= 100001; ++i)
        p10[i] = (p10[i-1] * 100003) % mod;
    long long ans = 0;
    for(int i = 1; i <= m; ++i)
    {
        for(int j = 1; j <= n; ++j)
            cin >> a[i][j], pos[i][a[i][j]] = j;
        for(int j = 1; j <= n; ++j)
            prod[i][j] = (1LL * prod[i][j-1] * 100003 + a[i][j]) % mod;
    }
    for(int i = 1; i <= n; ++i)
    {
        long long cate = n - pos[1][i] + 1;
        for(int j = 2; j <= m; ++j)
        {
            long long b = 1;
            long long e = min(cate, n - pos[j][i] + 1);
            long long sol = 0;
            while(b <= e)
            {
                long long mid = (b+e) / 2;
                long long proda = (prod[j-1][pos[j-1][i] + mid - 1]  - prod[j-1][pos[j-1][i] - 1] * p10[mid] + p10[mid] * mod) % mod;
                long long prodb = (prod[j][pos[j][i] + mid - 1]  - prod[j][pos[j][i] - 1] * p10[mid] + p10[mid] * mod) % mod;
                if(proda == prodb)
                    sol = mid, b = mid + 1;
                else
                    e = mid - 1;
            }
            cate = sol;
        }
        ans += cate;
    }
    cout << ans;
    return 0;
}
