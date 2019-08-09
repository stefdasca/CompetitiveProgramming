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
int n;

ll v[1000002], p1[1000002], p2[1000002], c1[1000002], c2[1000002];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> v[i], --v[i];
    ll ans = 0;
    for(int i = 1; i <= n; ++i)
    {
        if(v[i] == 0)
            continue;
        if(i == 1)
        {
            ans = add(ans, v[i]);
            p1[i] = 1;
            c1[i] = v[i];
        }
        else
        {
            if(v[i] <= v[i-1])
            {
                ll sum = 0;
                if(v[i] <= c1[i-1])
                    sum = p1[i-1] * v[i] + 1;
                else
                    sum = p1[i-1] * c1[i-1] + p2[i-1] * (v[i] - c1[i-1]) + 1;
                sum %= mod;
                ans = add(ans, mul(sum, v[i]));
                p1[i] = sum;
                c1[i] = v[i];
            }
            else
            {
                ll sum = p1[i-1] * c1[i-1] + p2[i-1] * c2[i-1] + 1;
                sum %= mod;
                ans = add(ans, mul(sum, v[i-1]));
                p1[i] = sum;
                c1[i] = v[i-1];
                p2[i] = 1;
                c2[i] = v[i] - v[i-1];
                ans = add(ans, c2[i]);
            }
        }
    }
    cout << ans;
    return 0;
}
