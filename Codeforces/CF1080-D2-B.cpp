#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
long long q;
long long l, r;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> q;
    for(int i = 1; i <= q; ++i)
    {
        cin >> l >> r;
        long long sum =( r * (r+1) )/ 2 - ((l-1) * l) / 2;
        if(r % 2 == 0)
            --r;
        sum = sum - 2 * (r/2+1) * (r/2+1);
        --l;
        if(l % 2 == 0)
            --l;
        if(l >= 1)
            sum = sum + 2 * (l/2+1) * (l/2+1);
        cout << sum << '\n';
    }
    return 0;
}
