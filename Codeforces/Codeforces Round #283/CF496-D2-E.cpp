#include<bits/stdc++.h>
#define god dimasi5eks
#pragma GCC optimize("O3")
#define fi first
#define se second
#define pb push_back
#define pf push_front
#define mod 1000000007
#define dancila 3.14159265359
#define eps 1e-9

using namespace std;

typedef long long ll;

int n, m;
pair<int, int> nt[100002];

bool cmp(int a, int b)
{
    if(nt[a].fi == nt[b].fi)
        return nt[a].se < nt[b].se;
    return nt[a].fi < nt[b].fi;
}
int wh[100002], v[100002], lft[100002];

struct actor
{
    int x, y, k, pi;
};
actor va[100002];

bool cmp2(actor a, actor b)
{
    return a.x < b.x;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 1; i <= n; ++i)
    {
        cin >> nt[i].fi >> nt[i].se;
        v[i] = i;
    }
    sort(v+1, v+n+1, cmp);
    cin >> m;
    for(int i = 1; i <= m; ++i)
    {
        cin >> va[i].x >> va[i].y >> va[i].k;
        lft[i] = va[i].k;
        va[i].pi = i;
    }
    sort(va + 1, va + m + 1, cmp2);
    set<pair<int, int> >s;
    int pz = 1;
    for(int i = 1; i <= n; ++i)
    {
        while(pz <= m && va[pz].x <= nt[v[i]].fi)
            s.insert({va[pz].y, va[pz].pi}), ++pz;
        while(!s.empty() && (*s.begin()).fi < nt[v[i]].fi)
            s.erase(s.begin());
        set<pair<int, int> > ::iterator it = s.lower_bound({nt[v[i]].se, 0});
        if(it == s.end())
        {
            cout << "NO";
            return 0;
        }
        pair<int, int> xx = *it;
        s.erase(xx);
        --lft[xx.se];
        wh[v[i]] = xx.se;
        if(lft[xx.se])
            s.insert(xx);
    }
    cout << "YES\n";
    for(int i = 1; i <= n; ++i)
        cout << wh[i] << " ";
    return 0;
}
