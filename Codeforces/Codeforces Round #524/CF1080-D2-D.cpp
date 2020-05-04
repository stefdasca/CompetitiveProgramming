#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
long long t;
long long n, nr;
bool gg;
long long ans;
void divide(long long lvl, long long nec, long long gp)
{
    long long maxim = 0;
    long long gp2 = 1;
    while(lvl)
    {
        nec -= gp;
        if(nec < 0)
            return;
        long long zz = lvl - 1;
        long long azz = 1;
        while(zz)
        {
            azz *= 4;
            if(nec - maxim - gp2 * ((azz-1) / 3) <= 0)
            {
                gg = 1;
                ans = lvl - 1;
                return;
            }
            --zz;
        }
        maxim += gp2 * ((azz-1) / 3);
        --lvl;
        gp = (gp * 2) + 1;
        gp2 = (gp2 + 1) * 2 + 1;
        if(nec - maxim <= 0)
        {
            gg = 1;
            ans = lvl;
            return;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    for(int i = 1; i <= t; ++i)
    {
        cin >> n >> nr;
        gg = 0;
        ans = 0;
        divide(n, nr, 1);
        if(gg == 0)
            cout << "NO\n";
        else
            cout << "YES" << " " << ans << '\n';
    }
    return 0;
}
