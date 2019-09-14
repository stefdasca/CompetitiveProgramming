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
struct para
{
    int a, b;
};
para v[102];
int ct[500002];
string s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    cin >> s;
    s = ' ' + s;
    int mx = 0;
    for(int i = 1; i <= n; ++i)
    {
        cin >> v[i].a >> v[i].b;
        int nxt = v[i].b;
        for(int j = 0; j <= 200000; j++)
        {
            if(j == nxt)
            {
                if(s[i] == '1')
                    s[i] = '0';
                else
                    s[i] = '1';
                nxt += v[i].a;
            }
            ct[j] += (s[i] - '0');
            mx = max(mx, ct[j]);
        }
    }
    cout << mx;
    return 0;
}

