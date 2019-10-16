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

int poz[100002], b[100002], a[100002], prf[100002], poz2[100002];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> a[i], poz[a[i]] = i;
    for(int i = 1; i <= n; ++i)
        cin >> b[i], poz2[b[i]] = i;
    for(int i = 1; i <= n; ++i)
        prf[poz[b[i]]] = i;
    for(int i = 2; i <= n; ++i)
        prf[i] = max(prf[i-1], prf[i]);
    int ans = 0;
    for(int i = 1; i <= n; ++i)
    {
        if(i < prf[poz[b[i]]])
        {
            ++ans;
        }
    }
    cout << ans;
    return 0;
}
