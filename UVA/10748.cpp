/*
    https://algorithmist.com/wiki/UVa_10748
*/
#include<bits/stdc++.h>
using namespace std;

const unsigned int hsh_mod = 100019;
set<pair<int, int> > R[hsh_mod];

unsigned int hsh(int x, int y)
{
    unsigned int a = 63689, b = 378551;
    unsigned int value = 0;
    int c[4] = {x, y, y, x};
    for(int i = 0; i < 4; i++)
    {
        value = value * a + c[i];
        a *= b;
    }
    return value % hsh_mod;
}

const int dx[] = {1, 1, -1, -1, 2, 2, -2, -2};
const int dy[] = {2, -2, 2, -2, 1, -1, 1, -1};

int bfs(int sx[], int sy[], int dstep[], int n)
{
    for(int i = 0; i < hsh_mod; i++)
        R[i].clear();

    queue<int> X[64], Y[64];
    int step, tx, ty, x, y;

    for(int i = 63; i >= 0; i--)
    {
        for(int j = 0; j < n; j++)
        {
            if(dstep[j] == i)
            {
                X[i].push(sx[j]), Y[i].push(sy[j]);
                R[hsh(sx[j], sy[j])].insert(make_pair(sx[j], sy[j]));
            }
        }
        while(!X[i].empty())
        {
            x = X[i].front(), X[i].pop();
            y = Y[i].front(), Y[i].pop();

            if(i == 0)
                continue;
            for(int k = 0; k < 8; k++)
            {
                tx = x + dx[k], ty = y + dy[k];
                if(!R[hsh(tx, ty)].count(make_pair(tx, ty)))
                {
                    R[hsh(tx, ty)].insert(make_pair(tx, ty));
                    X[i-1].push(tx), Y[i-1].push(ty);
                }
            }
        }
    }

    int ans = 0;
    for(int i = 0; i < hsh_mod; i++)
        ans += R[i].size();
    return ans;
}
int main()
{
    int x[64], y[64], step[64];
    int n;
    int h[64] = {};
    for(int i = 0; i <= 50; i++)
    {
        x[0] = y[0] = 0, step[0] = i;
        h[i] = bfs(x, y, step, 1);
    }
    while(scanf("%d", &n) == 1 && n)
    {
        for(int i = 0; i < n; i++)
            scanf("%d %d %d", &x[i], &y[i], &step[i]);

        int independent = 0;
        for(int i = 0; i < n; i++)
        {
            int d = 0x3f3f3f3f;
            for(int j = 0; j < n; j++)
            {
                if(i == j)
                    continue;
                d = min(d, max(abs(x[i] - x[j]) + abs(y[i] - y[j]) - 3 *(step[i] + step[j]), 0));
            }
            if(d > 0)
                independent += h[step[i]], step[i] = -1;
        }

        int ans = bfs(x, y, step, n) + independent;
        printf("%d\n", ans);
    }
    return 0;
}
