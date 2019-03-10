#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
long long rand_seed()
{
	long long a = rng();
    return a;
}
long long sum, v[100002], n;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> v[i], sum += v[i];
    long long ans = 0;
    for(int i = 1; i <= n; ++i)
    {
        sum -= v[i];
        ans += v[i] * sum;
    }
    cout << ans;
    return 0;
}

