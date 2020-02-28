#include<bits/stdc++.h>
#include "grader.h"
#include "decoder.h"

using namespace std;

vector<int> v[1002];

int tt[1002], dist[40][1002], state[1002];

void dfs(int h, int dad, int nod)
{
    dist[h][nod] = dist[h][tt[nod]] + (state[nod] + 1) % 3 - 1;
    for(int i = 0; i < v[nod].size(); ++i)
    {
        int vecin = v[nod][i];
        if(vecin == dad)
            continue;
        dfs(h, nod, vecin);
    }
}
void decode(int n, int h)
{
    for(int i = 0; i < n; ++i)
    {
        int wh = 0;
        for(int j = 0; j <= 9; ++j)
            wh = wh + (1<<j) * decode_bit();
        tt[i] = wh;
        v[wh].push_back(i);
    }
    for(int i = 0; i < h; ++i)
    {
        for(int j = 0; j < n; j += 5)
        {
            int val = 0;
            for(int xx = 0; xx <= 7; ++xx)
                val = val + decode_bit() * (1<<xx);
            for(int xx = min(n - 1, j + 4); xx >= j; --xx)
            {
                state[xx] = val % 3;
                val /= 3;
            }
        }

        int nd = i;
        while(nd != tt[nd])
        {
            dist[i][tt[nd]] = dist[i][nd] - (state[nd] + 1) % 3 + 1;
            nd = tt[nd];
        }
        dfs(i, 0, 0);
        for(int j = 0; j < n; ++j)
            hops(i, j, dist[i][j]);
    }

}

