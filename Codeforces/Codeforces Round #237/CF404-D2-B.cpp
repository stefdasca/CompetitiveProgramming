#include<bits/stdc++.h>
#define god dimasi5eks
#pragma GCC optimize("O3")
#define fi first
#define se second
#define pb push_back
#define pf push_front
#define mod 1000000007
#define eps 1e-9

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

double a, d;

int n;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> a >> d;
    cin >> n;
    double ox = 0.00000;
    double oy = 0.00000;
    int tip = 1;
    while(d >= 4 * a)
        d -= 4 * a;
    for(int i = 1; i <= n; ++i)
    {
        double difrm = d;
        while(difrm >= eps)
        {
           // cout << ox << " " << oy << " " << difrm << " " << tip << '\n';
            if(tip == 1)
            {
                double lst = a + 0.00000;
                if(lst - ox <= difrm)
                    difrm -= (lst - ox), ox = lst, tip = 2;
                else
                    ox += difrm, difrm = 0.0000;
            }
            else
            if(tip == 2)
            {
                double lst = a + 0.0000;
                if(lst - oy <= difrm)
                    difrm -= (lst - oy), oy = lst, tip = 3;
                else
                    oy += difrm, difrm = 0.0000;
            }
            else
            if(tip == 3)
            {
                double lst = 0.0000;
                if(ox <= difrm)
                    difrm -= ox, ox = 0.0000, tip = 4;
                else
                    ox -= difrm, difrm = 0.0000;
            }
            else
            if(tip == 4)
            {
                double lst = 0.0000;
                if(oy <= difrm)
                    difrm -= oy, oy = 0.0000, tip = 1;
                else
                    oy -= difrm, difrm = 0.0000;
            }
        }
        cout << fixed << setprecision(10) << ox << " " << oy << '\n';
    }
    return 0;
}
