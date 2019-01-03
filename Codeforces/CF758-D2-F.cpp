#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int n, l, r, sf;
int q;
long long ans;
long long p[10000002];
long long ratioo[10000002];
bool gg[10000002];
bool prim[10000002];
/// do sieve to find for each number from 1 to r the denominator of the ratio
void ciur(int sf)
{
    ratioo[1] = 1;
    for(int i = 2; i <= r; ++i)
        if(prim[i] == 0)
            for(int j = i; j <= r; j += i)
            {
                if(j > i)
                    prim[j] = 1;
                if(p[i] != 0 && j % p[i] == 0)
                {
                    if(ratioo[j] == 0)
                        ratioo[j] = 1;
                    int qq = j;
                    while(qq % p[i] == 0)
                        ratioo[j] *= i, qq /= p[i];
                }
            }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> l >> r;
    if(n >= 25)
    {
        cout << 0;
        return 0;
    }
    if(n == 1)
    {
        cout << r - l + 1;
        return 0;
    }
    p[1] = 1;
    /// find i^(n-1), where a^b = a * a * a * ... * a(b times)
    for(int i = 2; i <= r; ++i)
    {
        long long pr = 1;
        for(int j = 1; j < n; ++j)
        {
            pr *= i;
            if(pr > r)
                break;
        }
        if(pr > r)
            break;
        p[i] = pr;
        sf = i;
    }
    ciur(r);
    // count the progressions which start from i
    for(int i = l; i <= r; ++i)
    {
        if(ratioo[i] == 0)
            ratioo[i] = 1;
        long long fn = i;
        for(int j = 1; j < n; ++j)
            fn /= ratioo[i];
        int st = ratioo[i] + 1;
        int dr = r;
        int anss = ratioo[i];
        while(st <= dr)
        {
            int mid = (st + dr) / 2;
            if(p[mid] == 0 || 1LL * fn * p[mid] > r)
                dr = mid - 1;
            else
                anss = mid, st = mid + 1;
        }
        ans += (anss - ratioo[i]);
    }
    // double the answer, ratio 1/(fraction > 1) is literally the reverse of ratio (fraction > 1)
    ans = ans * 2;
    cout << ans;
    return 0;
}
