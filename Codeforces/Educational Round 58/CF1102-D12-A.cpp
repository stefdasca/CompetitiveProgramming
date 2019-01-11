#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
long long q;
long long L, R, D;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> q;
    for(int i = 1; i <= q; ++i)
    {
        cin >> L >> R >> D;
        long long rp = R / D + 1;
        if(D < L)
            cout << D << '\n';
        else
            cout << rp * D << '\n';
    }
    return 0;
}
