#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#define fi first
#define se second
#define pb push_back
#define pf push_front
#define mod 998244353

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

struct ed
{
    int a, b;
};
ed ve[500002];
int t;
int n, m;
vector<pair<int, int> >v[300002];
vector<int>ans;
bool rm[500002], ca[300002];
void ch(int nm)
{
    int a = ve[nm].a;
    int b = ve[nm].b;
    for(int i = 0; i < v[a].size(); ++i)
        rm[v[a][i].se] = 1;
    for(int i = 0; i < v[b].size(); ++i)
        rm[v[b][i].se] = 1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    for(; t; --t)
    {
        ans.clear();
        for(int i = 1; i <= m; ++i)
            rm[i] = 0;
        for(int i = 1; i <= 3 * n; ++i)
            ca[i] = 0, v[i].clear();
        cin >> n >> m;
        for(int i = 1; i <= m; ++i)
        {
            int a, b;
            cin >> a >> b;
            ve[i] = {a, b};
            v[a].pb({b, i});
            v[b].pb({a, i});
        }
        int pp = 1;
        while(pp <= m)
        {
            if(rm[pp])
            {
                ++pp;
                continue;
            }
            ans.pb(pp);
            ch(pp);
            ca[ve[pp].a] = ca[ve[pp].b] = 1;
            rm[pp] = 1;
            ++pp;
        }
        if(ans.size() >= n)
        {
            cout << "Matching\n";
            for(int i = 0; i < n; ++i)
                cout << ans[i] << " ";
            cout << '\n';
        }
        else
        {
            cout << "IndSet\n";
            int xx = n;
            for(int i = 1; i <= 3 * n; ++i)
                if(!ca[i] && xx)
                    cout << i << " ", --xx;
            cout << '\n';
        }
    }
    return 0;
}

