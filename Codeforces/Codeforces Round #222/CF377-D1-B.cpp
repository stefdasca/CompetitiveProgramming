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

int n, m, p;

pair<int, int> v[100002];

pair<int, int> vx[100002];

int pz[100002];

bool cmp(int a, int b)
{
    return vx[a].fi < vx[b].fi;
}

int wh[100002];

bool chk(int d)
{
    int rem = 0;
    int oo = 0;
    int q = n;
    set<pair<int, int> > cost;
    int tc = 0;
    for(int i = m; i >= 1; --i)
    {
        while(q >= 1 && vx[pz[q]].fi >= v[i].fi)
            cost.insert({vx[pz[q]].se, pz[q]}), --q;
        if(rem)
            --rem, wh[v[i].se] = oo;
        else
        {
            if(cost.empty())
                return 0;
            pair<int, int> it = *cost.begin();
            tc += it.fi;
            oo = it.se;
            rem = d - 1;
            wh[v[i].se] = oo;
            cost.erase(it);
        }
        if(tc > p)
            return 0;
    }
    return 1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> p;
    for(int i = 1; i <= m; ++i)
        cin >> v[i].fi, v[i].se = i;
    sort(v + 1, v + m + 1);
    for(int i = 1; i <= n; ++i)
        cin >> vx[i].fi;
    for(int i = 1; i <= n; ++i)
        cin >> vx[i].se, pz[i] = i;
    sort(pz + 1, pz + n + 1, cmp);
    if(v[m].fi > vx[pz[n]].fi)
    {
        cout << "NO";
        return 0;
    }
    int st = 1;
    int dr = m;
    int ans = m+1;
    while(st <= dr)
    {
        int mid = (st + dr) / 2;
        if(chk(mid))
            ans = mid, dr = mid - 1;
        else
            st = mid + 1;
    }
    if(ans == m+1)
    {
        cout << "NO";
        return 0;
    }
    chk(ans);
    cout << "YES\n";
    for(int i = 1; i <= m; ++i)
        cout << wh[i] << " ";
    return 0;
}
