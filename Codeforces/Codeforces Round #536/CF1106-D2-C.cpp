#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int n;
int v[300002];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> v[i];
    sort(v+1, v+n+1);
    long long ans = 0;
    for(int i = 1; i <= n/2; ++i)
        ans += 1LL * (v[n - i + 1] + v[i]) * (v[n - i + 1] + v[i]);
    cout << ans;
    return 0;
}

