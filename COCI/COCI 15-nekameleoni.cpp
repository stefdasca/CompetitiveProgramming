/*
                COCI 15-nekameleoni

    We can solve the problem by storing the necessary data in a fully binary tree(we can't use segment tree or any other similar
data structure because memory limit doesn't allow us to do so).
    When we will update a certain node, we will start from the leave where that position is and we will use bitmasks
to memorize values of distinct prefixes and suffixes, in order in which they appear. Given that at each update we will do
O(k) operations and we update O(log N) nodes, the total complexity will be O(K * (N + Q) * log N)

*/
#include<bits/stdc++.h>
#define INF 1e9
using namespace std;
int n, k, q;
int v[100002];
struct nod
{
    int len;
    pair<long long, int> pref[52], suff[52];
    int ans;
};
nod tournie[300002];
bool egal(long long a, long long b)
{
    return (a & b) == a;
}
void upd(int a, int b)
{
    a += (1<<17);
    tournie[a].len = 1;
    tournie[a].pref[0] = {1LL<<b, a - (1<<17)};
    tournie[a].suff[0] = tournie[a].pref[0];
    tournie[a].ans = INF;
    for(a /= 2; a; a >>= 1)
    {
        int Lp, Sl;
        Lp = 0;
        for (int i = 0; i < tournie[a * 2].len; ++i)
            tournie[a].pref[Lp++] = tournie[a * 2].pref[i];
        for (int i = 0; i < tournie[a * 2 + 1].len; ++i)
            if(Lp == 0 || !egal(tournie[a * 2 + 1].pref[i].first, tournie[a].pref[Lp-1].first))
            {
                tournie[a].pref[Lp] = tournie[a * 2 + 1].pref[i];
                if (Lp > 0)
                    tournie[a].pref[Lp].first |= tournie[a].pref[Lp-1].first;
                ++Lp;
            }
        Sl = 0;
        for (int i = 0; i < tournie[a * 2 + 1].len; ++i)
            tournie[a].suff[Sl++] = tournie[a * 2 + 1].suff[i];
        for (int i = 0; i < tournie[a * 2].len; ++i)
            if (Sl == 0 || !egal(tournie[a * 2].suff[i].first, tournie[a].suff[Sl-1].first))
            {
                tournie[a].suff[Sl] = tournie[a * 2].suff[i];
                if (Sl > 0)
                    tournie[a].suff[Sl].first |= tournie[a].suff[Sl-1].first;
                ++Sl;
            }
        tournie[a].len = Lp;
        tournie[a].ans = INF;
        int pref_pos = 0;
        for (int suff_pos = tournie[a * 2].len-1; suff_pos >= 0; --suff_pos)
        {
            while (pref_pos < tournie[a * 2 + 1].len && (tournie[a * 2].suff[suff_pos].first | tournie[a * 2 + 1].pref[pref_pos].first) != (1LL<<k)-1)
                ++pref_pos;
            if (pref_pos < tournie[a * 2 + 1].len)
            {
                long long curr_mask = tournie[a * 2].suff[suff_pos].first | tournie[a * 2 + 1].pref[pref_pos].first;
                if (curr_mask == (1LL<<k)-1)
                    tournie[a].ans = min(tournie[a].ans, tournie[a * 2 + 1].pref[pref_pos].second-tournie[a * 2].suff[suff_pos].second+1);
            }
        }
        tournie[a].ans = min(tournie[a].ans, min(tournie[a * 2].ans, tournie[a * 2 + 1].ans));
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k >> q;
    for(int i = 0; i <= 280000; ++i)
        tournie[i].ans = INF;
    for(int i = 0; i < n; ++i)
    {
        cin >> v[i];
        upd(i, v[i] - 1);
    }
    for(int i = 1; i <= q; ++i)
    {
        int tip;
        cin >> tip;
        if(tip == 2)
        {
            if(tournie[1].ans == INF)
                cout << -1 << '\n';
            else
                cout << tournie[1].ans << '\n';
        }
        else
        {
            int a, b;
            cin >> a >> b;
            --a, --b;
            upd(a, b);
        }
    }
    return 0;
}
