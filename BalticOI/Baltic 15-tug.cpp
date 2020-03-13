/*
                Baltic 15-tug

    Firstly, let's deal with the spots with 0 or 1 people who want it, by adding them in a queue.

        * If there is a spot such that nobody wants it, the answer is NO.
        * If there is a spot with just one person wanting it, we are going to assign it to that person while
also checking if the other spot will enter in this category.

    After we finished dealing with those spots, the remaining spots will all have at least two people wanting it
(it can be proven that exactly two people want each spot). Thus, if the spots are represented as the vertexes and the
contestants as edges, the resulted graph will be formed only of cycles and there are just two possible outcomes
(if difference in one of them is x, the difference in the other one is -x).

    Last but not least, we're left with finding an assignment of cycles such that the difference is at most maxdif, this
is a classical knapsack dp task, but in order to do it fast enough, we need to use bitsets.

*/
#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
using namespace std;

int n, maxdif, skill[60002];
set<int> v[60002];

pair<int, int> vals[60002];
bool viz[60002];

int dif;

bitset<20 * 60002> dp;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> maxdif;
    for(int i = 1; i <= n+n; ++i)
    {
        int a, b;
        cin >> a >> b >> skill[i];
        b += n;
        v[a].insert(i);
        v[b].insert(i);
        vals[i] = {a, b};
    }
    deque<int> d;
    for(int i = 1; i <= n+n; ++i)
        if(v[i].size() < 2)
            d.pb(i), viz[i] = 1;
    while(!d.empty())
    {
        int poz = d[0];
        d.pop_front();
        if(v[poz].size() == 0)
        {
            cout << "NO\n";
            return 0;
        }
        int nr = *v[poz].begin();
        v[vals[nr].fi].erase(nr);
        v[vals[nr].se].erase(nr);
        if(v[vals[nr].fi].size() < 2 && !viz[vals[nr].fi])
        {
            viz[vals[nr].fi] = 1;
            d.pb(vals[nr].fi);
        }
        if(v[vals[nr].se].size() < 2 && !viz[vals[nr].se])
        {
            viz[vals[nr].se] = 1;
            d.pb(vals[nr].se);
        }
        if(poz <= n)
            dif += skill[nr];
        else
            dif -= skill[nr];
    }
    vector<int> ruk;
    for(int i = 1; i <= n+n; ++i)
    {
        if(v[i].size() < 2)
            continue;
        int valas = 0;
        int j = i;
        while(v[j].size())
        {
            int val = *v[j].begin();
            if(j <= n)
                valas += skill[val];
            else
                valas -= skill[val];
            v[vals[val].fi].erase(val);
            v[vals[val].se].erase(val);
            if(j == vals[val].fi)
                j = vals[val].se;
            else
                j = vals[val].fi;
        }
        valas = abs(valas);
        dif -= valas;
        ruk.pb(2 * valas);
    }
    dif += 20 * n;
    dp[dif] = 1;
    for(int i = 0; i < ruk.size(); ++i)
        dp = dp | (dp << ruk[i]);
    bool ok = 0;
    for(int i = 20 * n - maxdif; i <= 20 * n + maxdif; ++i)
        ok |= dp[i];
    if(ok)
        cout << "YES\n";
    else
        cout << "NO\n";
    return 0;
}
