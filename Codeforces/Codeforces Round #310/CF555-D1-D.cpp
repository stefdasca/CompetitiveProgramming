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
int n, m;
pair<int, int> v[200002], v2[200002];
int cb(int poz)
{
    int st = 1;
    int dr = n;
    int ans = 0;
    while(st <= dr)
    {
        int mid = (st + dr) / 2;
        if(poz >= v[mid].fi)
            ans = mid, st = mid + 1;
        else
            dr = mid - 1;
    }
    return ans;
}
int cb2(int poz)
{
    int st = 1;
    int dr = n;
    int ans = 1;
    while(st <= dr)
    {
        int mid = (st + dr) / 2;
        if(poz <= v[mid].fi)
            ans = mid, dr = mid - 1;
        else
            st = mid + 1;
    }
    return ans;
}
int solve(int curr, int st, int dr, int val)
{
    if(st == dr)
        return st;
    if(curr == st && val < v[st+1].fi - v[st].fi)
        return curr;
    if(curr == dr && val < v[dr].fi - v[dr-1].fi)
        return curr;
    int rap = val / (v[dr].fi - v[st].fi);
    val %= (v[dr].fi - v[st].fi);
    if(curr == st)
    {
        if(rap % 2 == 1)
            curr = dr;
    }
    else
    {
        if(rap % 2 == 1)
            curr = st;
    }
    if(curr == st)
    {
        int new_right = cb(v[curr].fi + val);
        return solve(new_right, st, new_right, v[st].fi + val - v[new_right].fi);
    }
    else
    {
        int new_right = cb2(v[curr].fi - val);
        return solve(new_right, new_right, dr, v[new_right].fi - (v[dr].fi - val));
    }
    return 1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i = 1; i <= n; ++i)
    {
        cin >> v[i].fi;
        v[i].se = i;
        v2[i] = v[i];
    }
    sort(v+1, v+n+1);
    for(int i = 1; i <= m; ++i)
    {
        int poz, length;
        cin >> poz >> length;
        int st_length = length;
        int point = cb(v2[poz].fi);
        int new_point = cb(v2[poz].fi + length);
        length = v[point].fi + length - v[new_point].fi;
        point = new_point;
        new_point = cb2(v[point].fi - length);
        if(new_point == point && st_length == length)
        {
            cout << v[new_point].se << '\n';
            continue;
        }
        cout << v[solve(new_point, new_point, point, v[new_point].fi - (v[point].fi - length))].se << '\n';
    }
    return 0;
}
