#include<bits/stdc++.h>
#define god dimasi5eks
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

vector<int> divizori[1000002];
int pr[1000002], ok[1000002];
void ciur()
{
    for(int i = 2; i <= 1000000; ++i)
    {
        if(!ok[i])
            for(int j = i; j <= 1000000; j += i)
            {
                int z = j;
                while(z % i == 0)
                    pr[j] ^= 1, z /= i;
                ok[j] = 1;
                divizori[j].pb(i);
            }
    }
}

int FindDiv1(int nr, int mx)
{
    int sol = 0;
    for(int i = 1; i < (1<<(int)divizori[nr].size()); ++i)
    {
        int vx = 1;
        int ct = 0;
        for(int j = 0; j < divizori[nr].size(); ++j)
            if(i & (1<<j))
                vx *= divizori[nr][j], ++ct;
        if(ct % 2 == 0)
            sol -= mx / vx;
        else
            sol += mx / vx;
    }
    return mx - sol;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ciur();
    int t;
    cin >> t;
    for(; t; --t)
    {
        int x, p, k;
        cin >> x >> p >> k;
        int va = FindDiv1(p, x);
        k += va;
        int st = x;
        int dr = (1LL<<23);
        int ans = dr;
        while(st <= dr)
        {
            int mid = (st + dr) / 2;
            if(FindDiv1(p, mid) >= k)
                ans = mid, dr = mid - 1;
            else
                st = mid + 1;
        }
        cout << ans << '\n';
    }
    return 0;
}
