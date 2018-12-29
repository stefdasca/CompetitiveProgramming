/// Never do the same mistake twice

#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    for(int i = 1; i <= t; ++i)
    {
        int nr;
        cin >> nr;
        int ans = 180 / __gcd(180, nr);
        int unghi = 180 - 360 / ans;
        if(unghi < nr)
            ans *= 2;
        cout << ans << '\n';
    }
    return 0;
}
