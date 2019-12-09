#include<bits/stdc++.h>
#define god dimasi5eks
#pragma GCC optimize("O3")
#define fi first
#define se second
#define pb push_back
#define pf push_front
#define mod 1000000007
#define dancila 3.14159265359
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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
long long rand_seed()
{
    long long a = rng();
    return a;
}
int n;
string s;
int frq[28];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    cin >> s;
    for(int i = 0; i < s.size(); ++i)
        frq[s[i] - 'A']++;
    int mx = frq[0];
    int am = 1;
    for(int i = 1; i <= 25; ++i)
    {
        if(frq[i] > mx)
            mx = frq[i], am = 1;
        else
            if(mx == frq[i])
                ++am;
    }
    ll ans = 1;
    for(int i = 1; i <= n; ++i)
        ans = mul(ans, am);
    cout << ans;
    return 0;
}
