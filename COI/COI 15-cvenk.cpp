/*
        COI 15-cvenk

    The fractal described in the problem statement forms a tree, and we can use this observation to create a tree based on
the existent points. However, since the coordinates are big, we need to compress it, and we are going to use the binary representation
of each number from the pair of coordinates to do it.

    Let's iterate i from 1 << 29 downwards. Let curr = (0, 0) initially

        * If x & (1 << i), then we add (1 << i) to curr's x coordinate
        * If y & (1 << i), then we add (1 << i) to curr's y coordinate
        * Insert the edge between the old curr and the current curr, while taking care of the current edge.

    After we created the tree, finding the node which is the closest to all other nodes is a classical problem which can be solved
using DFS.

*/
#include<bits/stdc++.h>
#define fi first
#define se second

using namespace std;

typedef long long ll;

struct nod
{
    ll x, y, sz;
    nod *fii[2];

    nod(ll X = 0, ll Y = 0): x(X), y(Y), sz(0)
    {
        fii[0] = fii[1] = NULL;
    }

    nod* add(nod *tbi, int kid)
    {
        ++sz;
        if(!fii[kid])
        {
            fii[kid] = tbi;
            return tbi;
        }
        if(tbi -> x < fii[kid] -> x || tbi -> y < fii[kid] -> y)
        {
            tbi -> fii[kid] = fii[kid];
            tbi -> sz += fii[kid] -> sz;
            fii[kid] = tbi;
            return tbi;
        }
        if (tbi -> x > fii[kid] -> x || tbi -> y > fii[kid] -> y)
            return fii[kid] -> add(tbi, kid);
        return fii[kid];
    }
};
nod *rad = new nod();
int n;
ll sum, minans = (1LL<<60);
pair<int, int> pct[100002];

bool cmp(pair<int, int> a, pair<int, int> b)
{
    return (a.fi + a.se) > (b.fi + b.se);
}

void dfs(nod *cur)
{
    minans = min(minans, sum);
    for(int i = 0; i <= 1; i++)
        if(cur -> fii[i])
        {
            ll dx = (cur -> x) - (cur -> fii[i] -> x) + (cur -> y) - (cur -> fii[i] -> y);
            sum += dx * (2 * cur -> fii[i] -> sz - n);
            dfs(cur -> fii[i]);
            sum -= dx * (2 * cur -> fii[i] -> sz - n);
        }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 1; i <= n; ++i)
    {
        cin >> pct[i].fi >> pct[i].se;
        sum += pct[i].fi + pct[i].se;
    }
    sort(pct + 1, pct + n + 1, cmp);
    for(int i = 1; i <= n; ++i)
    {
        nod *cur = rad;
        ll cx = 0, cy = 0;
        for(int j = 29; j >= 0; --j)
        {
            if(pct[i].fi & (1<<j))
            {
                cx |= (1<<j);
                cur = cur -> add(new nod(cx, cy), 0);
            }
            else
                if(pct[i].se & (1<<j))
                {
                    cy |= (1<<j);
                    cur = cur -> add(new nod(cx, cy), 1);
                }
        }
        cur -> sz++;
    }
    dfs(rad);
    cout << minans;
    return 0;
}
