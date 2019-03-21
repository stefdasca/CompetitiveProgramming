#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
long long rand_seed()
{
	long long a = rng();
    return a;
}
long long n;
long long viz[200002], ans, dp[200002];
struct sp
{
    int nr;
    int vl;
};
sp v[200002];
bool cmp(sp a, sp b)
{
    return a.nr < b.nr;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> v[i].nr, v[i].vl = i;
    sort(v+1, v+n+1, cmp);
    long long ans = 0;
    for(int i = 1; i <= n; ++i)
    {
        for(int j = v[i].vl; j >= 1; --j)
        {
            if(viz[j] == 1)
                break;
            dp[j] = max(0, v[i].nr - (v[i].vl - j));
            viz[j] = 1;
        }
    }
    ans = 0;
    dp[n+1] = (1<<30);
    for(int i = n; i >= 1; --i)
    {
        dp[i] = max(0LL, min(dp[i], dp[i+1]-1));
        ans += dp[i];
    }
    cout << ans;
    return 0;
}

