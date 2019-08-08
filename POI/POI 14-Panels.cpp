/*

    * Let's observe that we can reduce the task to finding max(gcd(a, b)) for xmin <= a <= xmax and ymin <= b <= ymax

    * Because of divisor symmetry, we only have to iterate each i from 1 to max(sqrt(xmax), sqrt(ymax)) and check at some step
i, xmax / i and ymax / i.

    * in order for some number to be eligible for the answer, we have to check whether between xmin and xmax, respectively between
ymin and ymax we have at least one multiple of that number. This can be easily checked in O(1).

*/
#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#define fi first
#define se second
#define pb push_back
#define pf push_front
#define mod 1000000007

using namespace std;

typedef long long ll;


int add(int a, int b)
{
    ll x = a+b;
    if(x >= mod)
        x -= mod;
    if(x < 0)
        x += mod;
    return x;
}
ll mul(ll a, ll b)
{
    return (a*b) % mod;
}

ll pw(ll a, ll b)
{
    ll ans = 1;
    while(b)
    {
        if(b & 1)
            ans = (ans * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return ans;
}
int a, b, c, d;
int ans;
void can(int x)
{
    if(((a+x-1) / x) <= (b / x) && ((c+x-1) / x) <= (d / x))
        ans = max(ans, x);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    for(; t; --t)
    {
        cin >> a >> b >> c >> d;
        ans = 1;
        int mx = max(sqrt(b), sqrt(d)) + 1;
        for(int i = 1; i <= mx; ++i)
        {
            can(i);
            if((a + i - 1) / i <= b / i)
                can(b / i);
            if((c + i - 1) / i <= d / i)
                can(d / i);
        }
        cout << ans << '\n';
    }
    return 0;
}
