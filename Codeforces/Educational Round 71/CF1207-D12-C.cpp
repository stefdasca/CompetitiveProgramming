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
int t;
bool he[200002];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    for(; t; --t)
    {
        ll n, a, b;
        cin >> n >> a >> b;
        ll ans = 1LL * (n+1) * b;
        string s;
        cin >> s;
        int curr_height = 0;
        memset(he, 0, sizeof(he));
        for(int i = 0; i < n; ++i)
            if(s[i] == '1')
                he[i] = 1, he[i+1] = 1;
        for(int i = 0; i <= n; ++i)
        {
            ans += 1LL * he[i] * b;
            if(i == n)
                continue;
            if(he[i] == 0 && he[i+1] == 1)
                ans += 2LL * a;
            else
                if(he[i] == 0 && he[i+1] == 0)
                    ans += 1LL * a;
                else
                    if(he[i] == 1 && he[i+1] == 1)
                        ans += 1LL * a;
                    else
                        if(he[i] == 1 && he[i+1] == 0)
                        {
                            ans += 1LL * a;
                            if(i+1 == n)
                                ans += 1LL * a;
                            else
                            {
                                int nextone = i+1;
                                int ch = 0;
                                while(he[nextone] == 0)
                                    ++nextone, ++ch;
                                if(1LL * ch * b <= 2LL * a)
                                {
                                    nextone = i+1;
                                    while(he[nextone] == 0)
                                        he[nextone] = 1, ++nextone;
                                }
                                else
                                    ans += 1LL * a;
                            }
                        }
        }
        cout << ans << '\n';
    }
    return 0;
}
