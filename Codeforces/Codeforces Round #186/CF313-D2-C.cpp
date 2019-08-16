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

int n, sz;
int v[2000002];
int mat[4002][4002];
ll ans;
struct ss
{
    int Ls, Ld, Cs, Cd;
};
void divide()
{
    deque<ss>d;
    d.pb({1, sz, 1, sz});
    while(!d.empty())
    {
        ss a = d[0];
        d.pop_front();
        int mid = (a.Ls + a.Ld) / 2;
        int mid2 = (a.Cs + a.Cd) / 2;
        if(mat[a.Ls][a.Cs] == 0)
            mat[a.Ls][a.Cs] = v[n--];
        ans += mat[a.Ls][a.Cs];
        if(a.Ls == a.Ld)
            continue;
        d.pb({a.Ls, mid, a.Cs, mid2});
        d.pb({a.Ls, mid, mid2+1, a.Cd});
        d.pb({mid+1, a.Ld, a.Cs, mid2});
        d.pb({mid+1, a.Ld, mid2+1, a.Cd});
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> v[i];
    sort(v+1, v+n+1);
    int nr = 1;
    while(nr < n)
    {
        nr *= 4;
        ++sz;
    }
    sz = (1<<sz);
    divide();
    cout << ans;
    return 0;
}
