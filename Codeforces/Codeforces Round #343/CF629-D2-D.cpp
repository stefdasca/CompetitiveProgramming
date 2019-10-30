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

int n;
long long aib[100002];
void update(int node, ll value)
{
    for(int i = node; i <= n; i += (i & (-i)))
        aib[i] = max(aib[i], value);
}
ll compute(int node)
{
    ll ans = 0;
    for(int i = node; i > 0; i -= (i & (-i)))
        ans = max(ans, aib[i]);
    return ans;
}
pair<int, int> date[100002];
int ord[100002], poz[100002];
long long arie[100002];
bool cmp(pair<ll, int> a, pair<ll, int> b)
{
    if(a.fi == b.fi)
        return a.se < b.se;
    return a.fi < b.fi;
}
map<ll, int>mp;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> date[i].fi >> date[i].se;
    vector<pair<ll, int> > pz;
    for(int i = 1; i <= n; ++i)
    {
        arie[i] = 1LL * date[i].fi * date[i].fi * date[i].se;
        pz.pb({arie[i], i});
    }
    sort(pz.begin(), pz.end(), cmp);
    int x = 0;
    for(int i = 0; i < pz.size(); ++i)
    {
        if(i == 0 || pz[i].fi > pz[i-1].fi)
            ++x;
        mp[pz[i].se] = x;
    }
    ll sol = 0;
    for(int i = 1; i <= n; ++i)
    {
        int z = mp[i];
        ll ans = compute(z - 1) + arie[i];
        update(z, ans);
        sol = max(sol, ans);
    }
    double ans = 1.00000 * sol;
    long double pi = 3.14159265358979323846;
    cout << fixed << setprecision(12) << ans * pi << '\n';
    return 0;
}
