#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
long long n, k, a, b;
long long mn = (1LL<<60), mx = 0;
long long cmmdc(long long p, long long q)
{
    long long r = 0;
    while(q)
    {
        r = p % q;
        p = q;
        q = r;
    }
    return p;
}
void tri(long long x, long long y)
{
    long long dst, q;
    if(x <= y)
        dst = y - x;
    else
        dst = k + y - x;
    while(dst <= n * k)
    {
        if(dst != 0)
        {
            long long vl = (n * k) / cmmdc(n * k, dst);
            mn = min(mn, vl);
            mx = max(mx, vl);
        }
        dst += k;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k >> a >> b;
    tri(a, b);
    if(a != 0)
        tri(k - a, b);
    if(b != 0)
        tri(a, k - b);
    if(a != 0 && b != 0)
        tri(k - a, k - b);
    cout << mn << " " << mx << '\n';
    return 0;
}

