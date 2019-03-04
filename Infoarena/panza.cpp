/*
        infoarena panza(https://www.infoarena.ro/problema/panza)
        
   "Given n segments and m roads of increasing lengths, which unite segments i and i+1, for each i < n, find the shortest path from the starting square, 
which is on the segment 1, to the end square, which is on the segment n. One has to pass during the path through at least one square
from position [ai, bi] for each i from 1 to n."

    We can use dp[i][j] = the shortest path to get on the ith segment, at position j, but the normal O(n * m^2) approach is too slow.
 We can use a minqueue to optimize the approach for O(n * m), which is good enough given that n * m is guaranteed to be smaller than 10^6

*/
#include<bits/stdc++.h>
using namespace std;
ifstream f("panza.in");
ofstream g("panza.out");
int n, m, s, ff;
int dist[100002];
vector<long long>dp[100002];
struct gg
{
    int x, y;
};
gg v[100002];
long long d[100002];
long long org[100002];
int poz = 0;
int main()
{
    f >> n >> m >> s >> ff;
    for(int i = 1; i <= m; ++i)
        f >> dist[i];
    for(int i = 1; i <= n; ++i)
        f >> v[i].x >> v[i].y;
    for(int i = 1; i <= n; ++i)
        for(int j = 0; j <= m; ++j)
            dp[i].push_back(0);
    for(int i = 1; i <= m; ++i)
    {
        if(s < v[1].x)
            dp[1][i] = (v[1].x - s) + abs(v[1].x - i);
        else
            if(v[1].x <= s && s <= v[1].y)
                dp[1][i] = abs(s - i);
            else
                dp[1][i] = (s - v[1].y) + abs(v[1].y - i);
        dp[1][i] += dist[i];
    }
    for(int i = 1; i < n; ++i)
    {
        poz = 0;
        for(int j = 1; j <= m; ++j)
        {
            long long pred = dp[i][j];
            int ts = j;
            if(j < v[i+1].x)
                pred += (v[i+1].x - j), ts = v[i+1].x;
            else
                if(j > v[i+1].y)
                    pred += (j - v[i+1].y), ts = v[i+1].y;
            while(poz && pred + abs(ts - j) <= d[poz] + abs(org[poz] - j))
                --poz;
            ++poz;
            d[poz] = pred;
            org[poz] = ts;
            dp[i+1][j] = d[1] + abs(org[1] - j);
        }
        poz = 0;
        for(int j = m; j >= 1; --j)
        {
            long long pred = dp[i][j];
            int ts = j;
            if(j < v[i+1].x)
                pred += (v[i+1].x - j), ts = v[i+1].x;
            else
                if(j > v[i+1].y)
                    pred += (j - v[i+1].y), ts = v[i+1].y;
            while(poz && pred + abs(ts - j) <= d[poz] + abs(org[poz] - j))
                --poz;
            ++poz;
            d[poz] = pred;
            org[poz] = ts;
            dp[i+1][j] = min(dp[i+1][j], d[1] + abs(org[1] - j));
        }
        if(i + 1 < n)
            for(int j = 1; j <= m; ++j)
                dp[i+1][j] += dist[j];
    }
    g << dp[n][ff] << '\n';
    return 0;
}
