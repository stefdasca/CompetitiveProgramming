/*
        MCO 17-LargeCity

    We can keep the intervals we can access from (1, 1) for each line, and for a given connected interval in the same line,
we can use two pointers to reduce the interval to the portion we can access. Since we have only M lines with intervals(the other
lines have connected range (1, n), we need to do some computing in order to find the number of squares we can access.

*/
#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
using namespace std;
int n, m;
long long ans;
pair<int, int> val[300002];
vector<pair<int, int> >pr[300002];
int poz[300002], xx;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i = 1; i <= m; ++i)
    {
        int a, b;
        cin >> a >> b;
        val[i] = {a, b};
    }
    sort(val + 1, val + m + 1);
    if(val[m].fi < n)
    {
        ++m;
        val[m] = {val[m-1].fi+1, n+1};
    }
    int prv = 0;
    pr[0].pb({1, n});
    int ln = 0;
    for(int i = 1; i <= m; )
    {
        int j = i;
        xx = 0;
        poz[xx++] = 0;
        while(j <= m && val[j].fi == val[i].fi)
        {
            if(val[j].se != n+1)
                poz[xx++] = val[j].se;
            ++j;
        }
        poz[xx++] = n+1;
        if(val[i].fi - prv != 1)
        {
            int lmax = n+1;
            if(pr[ln].empty());
            else
                ans += 1LL * (val[i].fi - prv - 1) * (n - pr[ln][0].fi + 1), lmax = pr[ln][0].fi;
            pr[ln].clear();
            if(lmax <= n)
                pr[ln].pb({lmax, n});
        }
        if(val[i].fi == 1)
        {
            pr[ln].clear();
            ans += (poz[1] - 1);
            pr[ln].pb({1, poz[1] - 1});
        }
        else
        {
            int lp = 0;
            for(int j = 0; j + 1 < xx; ++j)
            {
                int L = poz[j] + 1;
                int R = poz[j+1] - 1;
                if(L <= R)
                {
                    while(lp < pr[ln].size() && pr[ln][lp].se < L)
                        ++lp;
                    if(lp < pr[ln].size())
                    {
                        if(max(L, pr[ln][lp].fi) <= R)
                        {
                            pr[ln+1].pb({max(L, pr[ln][lp].fi), R});
                            ans += R - max(L, pr[ln][lp].fi) + 1;
                        }
                    }
                }
            }
            ++ln;
        }
        prv = val[i].fi;
        i = j;
    }
    if(n+1 - prv != 1)
    {
        int lmax = n+1;
        if(pr[ln].empty());
        else
            ans += 1LL * (n+1 - prv - 1) * (n - pr[ln][0].fi + 1), lmax = pr[ln][0].fi;
    }
    cout << ans;
    return 0;
}
