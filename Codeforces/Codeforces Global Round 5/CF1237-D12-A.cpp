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
    int x = a+b;
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

int v[50002], sum, ans[50002];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 1; i <= n; ++i)
    {
        cin >> v[i];
        if(v[i] % 2 == 0)
            ans[i] = v[i] / 2;
        else
            if(v[i] > 0)
                ans[i] = v[i] / 2;
            else
                ans[i] = v[i] / 2 - 1;
        sum += ans[i];
    }
    for(int i = 1; i <= n; ++i)
        if(sum < 0 && v[i] % 2 != 0)
            ++ans[i], ++sum;
    for(int i = 1; i <= n; ++i)
        cout << ans[i] << '\n';
    return 0;
}
