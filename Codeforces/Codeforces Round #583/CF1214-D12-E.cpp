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

pair<int, int> v[100002];
int lvl[200002], nn[200002];
pair<int, int> ans[200002];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
     cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> v[i].first, v[i].second = 2 * i - 1;
    sort(v + 1, v + n + 1);
    int mch = 0;
    for(int i = n; i >= 1; --i)
    {
        if(i > 1)
        {
            ++mch;
            lvl[v[i].second] = mch;
            lvl[v[i-1].second] = mch+1;
            ans[mch] = {v[i].second, v[i-1].second};
        }
        nn[lvl[v[i].second]] = v[i].second;
    }
    int leve = mch+1;
    for(int i = n; i >= 1; --i)
    {
        if(v[i].first == 1)
        {
            ans[++mch] = {v[i].second, v[i].second + 1};
            continue;
        }
        if(lvl[v[i].second] + v[i].first - 1 < leve)
        {
            ans[++mch] = {v[i].second + 1, nn[lvl[v[i].second] + v[i].first - 1]};
        }
        else
            {
                ans[++mch] = {nn[leve], v[i].second + 1};
                ++leve;
                nn[leve] = v[i].second + 1;
                lvl[v[i].second + 1] = leve;
            }
    }
    for(int i = 1; i <= mch; ++i)
        cout << ans[i].first << " " << ans[i].second << '\n';
    return 0;
}
