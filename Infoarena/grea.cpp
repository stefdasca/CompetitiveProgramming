/*
            Infoarena grea(infoarena.ro/problema/grea)

    "Given a 2 * N binary matrix and a number K, find the minimal amount of time to get from (1, 1) to some square on the last
column, by either moving to the adjacent squares from the same column, or by moving with at most K squares away on the other column"

The obvious solution is to do BFS from the starting point and apply the classical algorithm, but due to the fact that one can move up to K
spaces on the other column, the naive algorithm will be too slow(O(n * k) will get TLE). Therefore, we will use any method to keep the unvisited
spaces and find them in O(log n). My implementation is using sets, because of their simplicity to find the required information



*/
#include<bits/stdc++.h>
using namespace std;
ifstream f("grea.in");
ofstream g("grea.out");
int k, n;
char c[3][260000];
bool viz[3][260000];
int dist[3][260000];
set<int>s[3];
int main()
{
    f >> n >> k;
    for(int i = 1; i <= 2; ++i)
        f >> (c[i] + 1);
    for(int i = 2; i <= n; ++i)
        if(c[1][i] == '0')
            s[1].insert(i);
    for(int i = 1; i <= n; ++i)
        if(c[2][i] == '0')
            s[2].insert(i);
    viz[1][1] = 1;
    deque<pair<int, int> >d;
    d.push_back({1, 1});
    while(!d.empty())
    {
        int L = d[0].first;
        int C = d[0].second;
        d.pop_front();
        if(!viz[L][C-1] && c[L][C-1] == '0')
        {
            dist[L][C-1] = dist[L][C] + 1;
            viz[L][C-1] = 1;
            d.push_back({L, C-1});
            s[L].erase(C-1);
        }
        if(!viz[L][C+1] && c[L][C+1] == '0')
        {
            dist[L][C+1] = dist[L][C] + 1;
            viz[L][C+1] = 1;
            d.push_back({L, C+1});
            s[L].erase(C+1);
        }
        int mini = max(C - k, 1);
        set<int> ::iterator it;
        it = s[3 - L].lower_bound(mini);
        while(it != s[3 - L].end() && *it <= min(n, C + k))
        {
            int val = *it;
            dist[3 - L][val] = dist[L][C] + 1;
            viz[3 - L][val] = 1;
            d.push_back({3 - L, val});
            s[3 - L].erase(val);
            it = s[3 - L].lower_bound(mini);
        }
    }
    int zz = (1<<30);
    if(viz[1][n])
        zz = min(zz, dist[1][n]);
    if(viz[2][n])
        zz = min(zz, dist[2][n]);
    g << zz;
    return 0;
}
