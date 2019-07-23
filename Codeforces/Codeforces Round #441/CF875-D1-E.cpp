#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#define fi first
#define se second
#define pb push_back
#define pf push_front
#define mod 998244353

using namespace std;

typedef long long ll;

ll add(ll a, ll b)
{
    ll x = a+b;
    if(x >= mod)
        x -= mod;
    return x;
}
ll mul(ll a, ll b)
{
    return (a*b) % mod;
}

int n, a, b;
int v[100002];
bool tri(int mx)
{
    set<int>s;
    s.insert(a);
    s.insert(b);
    for(int i = 1; i <= n; ++i)
    {
        while(!s.empty() && abs(*s.begin() - v[i]) > mx)
            s.erase(*s.begin());
        while(!s.empty() && abs(*s.rbegin() - v[i]) > mx)
            s.erase(*s.rbegin());
        if(s.empty())
            return 0;
        s.insert(v[i]);
    }
    return 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> a >> b;
    for(int i = 1; i <= n; ++i)
        cin >> v[i];
    int st = abs(a-b);
    int dr = 1000000000;
    int ans = dr;
    while(st <= dr)
    {
        int mid = (st+dr) / 2;
        if(tri(mid))
            ans = mid, dr = mid-1;
        else
            st = mid+1;
    }
    cout << ans;
    return 0;
}

