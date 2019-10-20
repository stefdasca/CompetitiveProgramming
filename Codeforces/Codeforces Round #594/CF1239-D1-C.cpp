#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#define fi first
#define se second
#define pb push_back
#define pf push_front
#define mod 1000000007

using namespace std;

typedef long long ll;

ll n, timespan, ans[100002];
pair<ll, int> start[100002];
set<pair<ll, pair<ll, ll> > >events;
set<int>want, inqueue;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> timespan;
    for(int i = 1; i <= n; ++i)
    {
        cin >> start[i].fi, start[i].se = i;
        events.insert({start[i].fi, {1, i}});
    }
    ll queuetime = 0;
    ll cur_time = 0;
    while(!events.empty())
    {
        pair<ll, pair<ll, ll> > x = *events.begin();
        events.erase(x);
     //   cout << x.fi << " " << x.se.fi << " " << x.se.se << '\n';
        if(x.se.fi == 1)
            want.insert(x.se.se);
        else
        {
            ans[x.se.se] = x.fi;
            inqueue.erase(x.se.se);
        }
        cur_time = x.fi;
        if(!want.empty() && (events.empty() || x.fi < (*events.begin()).fi))
        {
            if(inqueue.empty() || *want.begin() < *inqueue.begin())
            {
                int xx = *want.begin();
                inqueue.insert(*want.begin());
                want.erase(*want.begin());
                events.insert({max(cur_time, queuetime) + timespan, {0, xx}});
                queuetime = max(cur_time, queuetime) + timespan;
            }
        }
    }
    for(int i = 1; i <= n; ++i)
        cout << ans[i] << " ";
    return 0;
}

