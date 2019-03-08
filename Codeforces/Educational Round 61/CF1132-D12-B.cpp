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
long long v[300002], sum[300002];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> v[i];
    sort(v+1, v+n+1);
    for(int i = 1; i <= n; ++i)
        sum[i] = sum[i-1] + v[i];
    int q;
    cin >> q;
    for(int i = 1; i <= q; ++i)
    {
        int x;
        cin >> x;
        long long ans = sum[n] - v[n - x + 1];
        cout << ans << '\n';
    }
    return 0;
}

