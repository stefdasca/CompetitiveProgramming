#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
long long rand_seed()
{
	long long a = rng();
    return a;
}
int n, k;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;
    int ans = (n + 1) + n;
    int add = (1<<20);
    add = n - 1 + (k - 1);
    add = min(add, n - 1 + (n - k));
    cout << ans + add;
    return 0;
}

