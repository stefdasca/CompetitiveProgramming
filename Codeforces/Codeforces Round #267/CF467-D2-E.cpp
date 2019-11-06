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

map<int, int> mp, rev;
int v[500002], v2[500002], fi[500002], lst[500002], frq[500002], prv[500002];


int aint[2000002], wh[2000002];

void update(int nod, int st, int dr, int poz, int val)
{
    if(st == dr)
    {
        aint[nod] = val;
        wh[nod] = v[poz];
        return;
    }
    int mid = (st + dr) / 2;
    if(poz <= mid)
        update(nod << 1, st, mid, poz, val);
    else
        update(nod << 1|1, mid+1, dr, poz, val);
    if(aint[nod << 1] < aint[nod << 1|1])
        aint[nod] = aint[nod << 1], wh[nod] = wh[nod << 1];
    else
        aint[nod] = aint[nod << 1|1], wh[nod] = wh[nod << 1|1];
}

pair<int, int> query(int nod, int st, int dr, int L, int R)
{
    if(dr < L || st > R)
        return {n+1, n+1};
    if(L <= st && dr <= R)
        return {aint[nod], wh[nod]};
    int mid = (st + dr) / 2;
    return min(query(nod << 1, st, mid, L, R), query(nod << 1|1, mid+1, dr, L, R));
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 1; i <= n; ++i)
    {
        cin >> v[i];
        v2[i] = v[i];
    }
    sort(v2 + 1, v2 + n + 1);
    int am = 1;
    for(int i = 1; i <= n; ++i)
    {
        if(i > 1 && v2[i] > v2[i-1])
            ++am;
        mp[v2[i]] = am, rev[am] = v2[i];
    }
    for(int i = 1; i <= n; ++i)
        v[i] = mp[v[i]];
    int fii = 1;
    vector<int> ans;
    for(int i = 1; i <= n; ++i)
    {
        ++frq[v[i]];
        if(frq[v[i]] == 4)
        {
            for(int j = 0; j <= 3; ++j)
                ans.pb(rev[v[i]]);
            for(int j = fii; j <= i; ++j)
            {
                fi[v[j]] = 0;
                frq[v[j]] = 0;
                prv[v[j]] = 0;
            }
            fii = i+1;
            prv[v[i]] = i;
        }
        else
        {
            if(frq[v[i]] >= 2)
            {
                pair<int, int> ans2 = query(1, 1, n, prv[v[i]] + 1, i - 1);
                if(ans2.fi <= prv[v[i]])
                {
                    ans.pb(rev[ans2.se]);
                    ans.pb(rev[v[i]]);
                    ans.pb(rev[ans2.se]);
                    ans.pb(rev[v[i]]);
                    for(int j = fii; j <= i; ++j)
                    {
                        fi[v[j]] = 0;
                        frq[v[j]] = 0;
                        prv[v[j]] = 0;
                    }
                    fii = i+1;
                }
                else
                    update(1, 1, n, i, fi[v[i]]);
            }
            else
            {
                fi[v[i]] = i;
                update(1, 1, n, i, fi[v[i]]);
            }
            prv[v[i]] = i;
        }
    }

    cout << ans.size() << '\n';
    for(int i = 0; i < ans.size(); ++i)
        cout << ans[i] << " ";
    return 0;
}
