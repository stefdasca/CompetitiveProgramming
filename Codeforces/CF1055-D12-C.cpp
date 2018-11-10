/// Never do the same mistake twice

#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
long long a, b, c, d, e, f;
long long intersect(long long L1,long long R1,long long L2,long long R2)
{
    return min(R1,R2)-max(L1,L2)+1LL;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> a >> b >> c;
    cin >> d >> e >> f;
    long long gg = __gcd(c, f);
    if(a > d)
        swap(a, d), swap(b, e);
    long long q = (d - a) / gg;
    long long ans = 0;
    ans = max(ans, max(intersect(a+q*gg,b+q*gg,d,e),intersect(a+(q+1)*gg,b+(q+1)*gg,d,e)));
    cout << ans;
    return 0;
}
