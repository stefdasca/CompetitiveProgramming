#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
long long rand_seed()
{
	long long a = rng();
    return a;
}
int n, v[100002];
long long ans;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> v[i];
    for(int i = 0; i < n; ++i)
    {
        if(v[i+1] > v[i])
            ans += 1LL * (v[i+1] - v[i]) * (n - v[i+1] + 1);
        else
            ans += 1LL * (v[i] - v[i+1]) * v[i+1];
    }
    cout << ans;
    return 0;
}
