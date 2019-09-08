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
int n, k;
vector<int>v[100002];
bool out[100002];
int ans;
int seg[100002], poz[100002];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;
    for(int i = 1; i <= k; ++i)
    {
        int x;
        cin >> x;
        for(int j = 1; j <= x; ++j)
        {
            int nr;
            cin >> nr;
            v[i].pb(nr);
            seg[nr] = i;
            poz[nr] = j-1;
        }
    }
    for(int i = 1; i <= n; ++i)
    {
        if(out[i])
        {
            ++ans;
            continue;
        }
        int st = i;
        if(i == 1)
            while(poz[i] + 1 < v[seg[i]].size() && v[seg[i]][poz[i] + 1] == i+1)
                ++i;
        while(v[seg[i]].back() != i)
        {
            out[v[seg[i]].back()] = 1;
            v[seg[i]].pop_back();
            ++ans;
        }
        if(st != 1)
            ++ans;
    }
    cout << ans;
    return 0;
}

