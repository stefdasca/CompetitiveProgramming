#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
long long n, k, ans;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;
    ans = ans + (2 * n) / k;
    if((2 * n) % k > 0)
        ++ans;
    ans = ans + (5 * n) / k;
    if((5 * n) % k > 0)
        ++ans;
    ans = ans + (8 * n) / k;
    if((8 * n) % k > 0)
        ++ans;
    cout << ans;
    return 0;
}
