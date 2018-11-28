#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
long long t, n, x, y, d;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    for(int i = 1; i <= t; ++i)
    {
        cin >> n >> x >> y >> d;
        long long mini = (1LL<<60);
        if(abs((y - x)) % d == 0)
            mini = abs((y - x)) / d;
        long long aa = (x - 1) / d + ((x - 1) % d > 0);
        if((y - 1) % d == 0)
            mini = min(mini, aa + (y-1) / d);
        aa = (n - x) / d + ((n - x) % d > 0);
        if((n - y) % d == 0)
            mini = min(mini, aa + (n - y) / d);
        if(mini == (1LL<<60))
            cout << -1 << '\n';
        else
            cout << mini << '\n';
    }
    return 0;
}
