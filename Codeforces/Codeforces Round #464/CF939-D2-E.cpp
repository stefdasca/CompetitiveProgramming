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
int q;
vector<int>v;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> q;
    ll sum = 0;
    int nr = 0;
    int pz = 0;
    for(; q; --q)
    {
        int tip;
        cin >> tip;
        if(tip == 2)
        {
            double ans = 1.0000000 * v.back();
            ans = ans - (sum + 0.00000) / (nr + 0.00000);
            cout << fixed << setprecision(12) << ans << '\n';
        }
        else
        {
            int x;
            cin >> x;
            if(nr == 0)
                sum = x, nr = 1;
            else
                sum = sum + x - v.back();
            v.push_back(x);
            while(pz != v.size() - 1)
            {
                double r1 = (sum + 0.0000) / (nr + 0.0000);
                double r2 = (sum + 0.0000 + v[pz]) / (nr + 1.00000);
                if(r2 <= r1)
                    sum = sum + v[pz], ++nr, ++pz;
                else
                    break;
            }
        }
    }
    return 0;
}
