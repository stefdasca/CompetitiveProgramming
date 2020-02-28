#include<bits/stdc++.h>
#include "grader.h"
#include "encoder.h"

using namespace std;

vector<int> v[1002];

int dist[40][1002], tt[1002], state[1002];

bool viz[1002];

void dfs(int dad, int nod)
{
    viz[nod] = 1;
    tt[nod] = dad;
    for(int i = 0; i < v[nod].size(); ++i)
        if(!viz[v[nod][i]])
            dfs(nod, v[nod][i]);
}
void encode(int n, int h, int m, int *a, int *b)
{
    for(int i = 0; i < m; ++i)
    {
        v[a[i]].push_back(b[i]);
        v[b[i]].push_back(a[i]);
    }
    dfs(0, 0);
    for(int i = 0; i < n; ++i)
        for(int j = 0; j <= 9; ++j)
            if(tt[i] & (1<<j))
                encode_bit(1);
            else
                encode_bit(0);
    for(int i = 0; i < h; ++i)
    {
        dist[i][i] = 1;
        deque<int> d;
        d.push_back(i);
        while(!d.empty())
        {
            int nod = d[0];
            d.pop_front();
            for(int x = 0; x < v[nod].size(); ++x)
            {
                int vecin = v[nod][x];
                if(!dist[i][vecin])
                {
                    dist[i][vecin] = dist[i][nod] + 1;
                    d.push_back(vecin);
                }
            }
        }
        for(int j = 0; j < n; ++j)
        {
            if(dist[i][j] == dist[i][tt[j]])
                state[j] = 0;
            else
                if(dist[i][j] > dist[i][tt[j]])
                    state[j] = 1;
                else
                    state[j] = 2;
        }
        // 5 states with 8 bits
        for(int j = 0; j < n; j += 5)
        {
            int msk = 0;
            for(int x = j; x < min(n, j + 5); ++x)
                msk = msk * 3 + state[x];
            for(int pw = 0; pw <= 7; ++pw)
                if(msk & (1<<pw))
                    encode_bit(1);
                else
                    encode_bit(0);
        }
    }
}

