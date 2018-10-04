#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#define mod 1000000007
#define fi first
#define se second
using namespace std;
int n;
int a[100002];
int b[100002];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    // shuffle(permutation.begin(), permutation.end(), rng);
    cin>>n;
    long long sol = n;
    for(int i = 1; i <= n; ++i)
        cin >> a[i] >> b[i];
    sort(a+1, a+n+1);
    sort(b+1, b+n+1);
    for(int i = 1; i <= n; ++i)
        sol += max(a[i], b[i]);
    cout << sol;
    return 0;
}
