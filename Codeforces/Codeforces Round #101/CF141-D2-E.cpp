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


int n, m, cc, viz[1002];

vector<pair<pair<int, int>, int> >s, e;

vector<int>ans;
vector<pair<int, int> >nd;

vector<int> v[1002];

int tt[1002], rg[1002];
int Find(int nod)
{
    if(tt[nod] == nod)
        return nod;
    return tt[nod] = Find(tt[nod]);
}
void Unite(int a, int b)
{
    if(rg[a] < rg[b])
        swap(a, b);
    rg[b] += rg[a], tt[b] = a;
}

void dfs(int nod)
{
    viz[nod] = cc;
    for(int i = 0; i < v[nod].size(); ++i)
    {
        int vecin = v[nod][i];
        if(!viz[vecin])
            dfs(vecin);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i = 1; i <= m; ++i)
    {
        int x, y;
        char tip;
        cin >> x >> y >> tip;
        if(x != y)
        {
            if(tip == 'S')
                s.pb({{x, y}, i});
            else
                e.pb({{x, y}, i});
        }
    }
    if(s.size() > e.size())
        swap(s, e);
    for(int i = 0; i < e.size(); ++i)
    {
        v[e[i].fi.fi].pb(e[i].fi.se);
        v[e[i].fi.se].pb(e[i].fi.fi);
    }
    if(n % 2 == 0)
    {
        cout << -1;
        return 0;
    }
    for(int i = 1; i <= n; ++i)
        if(!viz[i])
            ++cc, dfs(i);
    if(cc - 1 > (n-1) / 2)
    {
        cout << -1;
        return 0;
    }
    for(int i = 1; i <= cc; ++i)
        tt[i] = i, rg[i] = 1;
    for(int i = 0; i < s.size(); ++i)
    {
        int a = s[i].fi.fi;
        int b = s[i].fi.se;
        if(Find(viz[a]) != Find(viz[b]))
        {
            Unite(Find(viz[a]), Find(viz[b]));
            nd.pb({a, b});
            ans.pb(s[i].se);
        }
        if(ans.size() == (n-1) / 2)
            break;
    }
    for(int i = 1; i <= n; ++i)
        tt[i] = i, rg[i] = 1;
    for(int i = 0; i < ans.size(); ++i)
        Unite(Find(nd[i].fi), Find(nd[i].se));
    for(int i = 0; i < s.size(); ++i)
    {
        int a = s[i].fi.fi;
        int b = s[i].fi.se;
        if(ans.size() == (n-1) / 2)
            break;
        if(Find(a) != Find(b))
        {
            Unite(Find(a), Find(b));
            nd.pb({a, b});
            ans.pb(s[i].se);
        }
    }
    if(ans.size() < (n-1) / 2)
    {
        cout << -1;
        return 0;
    }
    for(int i = 0; i < e.size(); ++i)
    {
        int a = e[i].fi.fi;
        int b = e[i].fi.se;
        if(Find(a) != Find(b))
        {
            Unite(Find(a), Find(b));
            ans.pb(e[i].se);
        }
        if(ans.size() == (n-1))
            break;
    }
    if(ans.size() != (n-1))
    {
        cout << -1;
        return 0;
    }
    cout << ans.size() << '\n';
    for(int i = 0; i < ans.size(); ++i)
        cout << ans[i] << " ";
    return 0;
}

