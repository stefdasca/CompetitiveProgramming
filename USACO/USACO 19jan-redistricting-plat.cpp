/*
            USACO 19jan-redistricting

    * find prefix sum for the given string, where H = 1 and G = -1
    * use n deques to find sliding window max for each of the possible n prefix sums
    * use segtree to do the max updates and to answer to query

                Total complexity O(n log n)

*/

#include<bits/stdc++.h>
#define MAXN 310002
using namespace std;
ifstream f("redistricting.in");
ofstream g("redistricting.out");
int n, k;
int prefsum[MAXN], aint[MAXN * 8];
deque<int>d[MAXN];
string s;
void build(int nod, int st, int dr)
{
    if(st == dr)
    {
        aint[nod] = (1LL<<30);
        return;
    }
    int mid = (st + dr) / 2;
    build(nod << 1, st, mid);
    build(nod << 1|1, mid + 1, dr);
    aint[nod] = min(aint[nod << 1], aint[nod << 1 | 1]);
}
void update(int nod, int st, int dr, int poz, int val)
{
    if(st == dr)
    {
        aint[nod] = val;
        return;
    }
    int mid = (st + dr) / 2;
    if(poz <= mid)
        update(nod << 1, st, mid, poz, val);
    else
        update(nod << 1|1, mid + 1, dr, poz, val);
    aint[nod] = min(aint[nod << 1], aint[nod << 1 | 1]);
}
int query(int nod, int st, int dr, int L, int R)
{
    if(L <= st && dr <= R)
        return aint[nod];
    if(dr < L || st > R)
        return (1<<30);
    int mid = (st + dr) / 2;
    return min(query(nod << 1, st, mid, L, R), query(nod << 1 | 1, mid + 1, dr, L, R));
}
int dp[300002];
int main()
{
    f >> n >> k;
    f >> s;
    s = ' ' + s;
    prefsum[0] = n + 1;
    int mini = prefsum[0];
    int maxi = prefsum[0];
    for(int i = 1; i <= n; ++i)
    {
        prefsum[i] = prefsum[i-1];
        if(s[i] == 'G')
            prefsum[i]--;
        else
            prefsum[i]++;
        mini = min(mini, prefsum[i]);
        maxi = max(maxi, prefsum[i]);
    }
    for(int i = 0; i <= n; ++i)
        prefsum[i] -= (mini - 1);
    int Len = maxi - mini + 1;
    build(1, 1, Len);
    d[prefsum[0]].push_back(0);
    update(1, 1, Len, prefsum[0], 0);
    for(int i = 1; i <= n; ++i)
    {
        if(i >= k + 1)
        {
            int pr = prefsum[i - k - 1];
            int nw = (1<<30);
            if(d[pr].front() == i - k - 1)
            {
                d[pr].pop_front();
                if(!d[pr].empty())
                    nw = dp[d[pr].front()];
                update(1, 1, Len, pr, nw);
            }
        }
        int mini = (1<<30);
        mini = min(mini, query(1, 1, Len, 1, prefsum[i] - 1));
        mini = min(mini, query(1, 1, Len, prefsum[i], Len) + 1);
        dp[i] = mini;
        int prvmax = (1<<30);
        if(!d[prefsum[i]].empty())
            prvmax = dp[d[prefsum[i]].front()];
        if(prvmax > dp[i])
            update(1, 1, Len, prefsum[i], dp[i]);
        while(!d[prefsum[i]].empty() && dp[i] < dp[d[prefsum[i]].back()])
            d[prefsum[i]].pop_back();
        d[prefsum[i]].push_back(i);
    }
    g << dp[n] << '\n';
    return 0;
}
