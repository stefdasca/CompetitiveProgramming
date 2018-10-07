#include<bits/stdc++.h>
#include "treasure.h"
using namespace std;
int gg[102][102];
void findTreasure(int N)
{
    int m = N/2;
    for(int i = N; i >= 1; --i)
    {
        for(int j = N; j >= 1; --j)
        {
            if(i > m && j > m)
                gg[i][j] = countTreasure(1, 1, i, j);
            if(i <= m && j > m)
                gg[i][j] = gg[N][j] - countTreasure(i+1, 1, N, j);
            if(i > m && j <= m)
                gg[i][j] = gg[i][N] - countTreasure(1, j+1, i, N);
            if(i <= m && j <= m)
                gg[i][j] = gg[N][j] + gg[i][N] - gg[N][N] + countTreasure(i+1, j+1, N, N);
        }
    }
    for(int i = 1; i <= N; ++i)
        for(int j = 1; j <= N; ++j)
            if(gg[i][j] > gg[i-1][j] + gg[i][j-1] - gg[i-1][j-1])
                Report(i, j);
    return;
}
