#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#define mod 1000000007
#define fi first
#define se second
using namespace std;
int n, k, sol[102];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    // shuffle(permutation.begin(), permutation.end(), rng);
    cin >> k >> n;
    for(int i = 1; i < n; ++i)
        sol[i] = i, k -= i;
    sol[n] = k;
    for(int i = 1; i <= n; ++i)
        cout << sol[i] << '\n';
    return 0;
}
