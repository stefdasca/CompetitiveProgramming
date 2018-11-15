/// Never do the same mistake twice

#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
long long t;
int nr;
struct ans
{
    long double sol, sol2;
};
ans v[1002];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    v[4] = {2.0000000, 2.0000000};
    for(int i = 5; i <= 1000; ++i)
    {
        long double st = 0.00000;
        long double dif = (0.00 + i - 1.00000) - v[i-1].sol2;
        long double qq = 0.000000 + i;
        for(int j = 1; j <= 2000; ++j)
        {
            long double mid = (st + dif) * 0.50000000;
            long double prod = mid * (qq - mid);
            if(prod >= qq)
                dif = mid;
            else
                st = mid;
        }
        v[i] = {qq - st, st};
    }
    for(int i = 1; i <= t; ++i)
    {
        cin >> nr;
        if(nr == 0)
        {
            cout << "Y 0.000000000 0.00000000\n";
            continue;
        }
        if(nr <= 3)
        {
            cout << "N\n";
            continue;
        }
        cout << "Y " << fixed << setprecision(12) << v[nr].sol << " " << fixed << setprecision(12) << v[nr].sol2 << '\n';
    }
    return 0;
}
