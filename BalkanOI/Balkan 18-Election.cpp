/*
        Balkan 18 - Elections

    We will process the queries in increasing order of the R(this can be done with counting sort).

    We will keep the null stack, like it's described in the editorial, and using the segment tree we are going to keep the smallest suffix sum
and we will also use upper bound to find the number of positions which will have been already nullified by the first traversal.

*/
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

int n, q;

string s;

int aint[2000002], lazy[2000002], ans[500002];

vector<pair<int, int> >qu[500002];
void lz(int nod, int st, int dr)
{
    aint[nod] += lazy[nod];
    if(st != dr)
    {
        lazy[nod << 1] += lazy[nod];
        lazy[nod << 1|1] += lazy[nod];
    }
    lazy[nod] = 0;
}
void upd(int nod, int st, int dr, int L, int R, int val)
{
    lz(nod, st, dr);
    if(dr < L || st > R)
        return;
    if(L <= st && dr <= R)
    {
        lazy[nod] += val;
        lz(nod, st, dr);
        return;
    }
    int mid = (st + dr) / 2;
    upd(nod << 1, st, mid, L, R, val);
    upd(nod << 1|1, mid+1, dr, L, R, val);
    aint[nod] = min(aint[nod << 1], aint[nod << 1|1]);
}

int query(int nod, int st, int dr, int L, int R)
{
    lz(nod, st, dr);
    if(dr < L || st > R)
        return 100000001;
    if(L <= st && dr <= R)
        return aint[nod];
    int mid = (st + dr) / 2;
    return min(query(nod << 1, st, mid, L, R), query(nod << 1|1, mid+1, dr, L, R));
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    cin >> s;
    s = ' ' + s;
    cin >> q;
    for(int i = 1; i <= q; ++i)
    {
        int a, b;
        cin >> a >> b;
        qu[b].pb({a, i});
    }
    vector<int> d;
    for(int i = 1; i <= n; ++i)
    {
        if(s[i] == 'T')
            d.pb(i);
        else
        {
            if(!d.empty())
            {
                upd(1, 1, n, (int) d.back(), n, -1);
                d.pop_back();
            }
            upd(1, 1, n, i, n, 1);
        }
        for(int j = 0; j < qu[i].size(); ++j)
        {
            int cs = qu[i][j].fi;
            int pz = qu[i][j].se;
            int sol = query(1, 1, n, cs, i);
            if(cs > 1)
                sol -= query(1, 1, n, cs-1, cs-1);
            auto it = lower_bound(d.begin(), d.end(), cs);
            int cnt = (int) d.size() - (it - d.begin());
            ans[pz] = cnt - min(0, sol);
        }
    }
    for(int i = 1; i <= q; ++i)
        cout << ans[i] << '\n';
    return 0;
}
