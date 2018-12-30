/// Never do the same mistake twice

#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int a, b, c;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> a >> b >> c;
    int ans = 6;
    int mn = 2;
    while(a >= mn && b >= mn + 1 && c >= mn + 2)
        ++mn, ans += 3;
    cout << ans;
    return 0;
}
