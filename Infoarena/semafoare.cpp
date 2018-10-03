#include<bits/stdc++.h>
using namespace std;
ifstream f("semafoare.in");
ofstream g("semafoare.out");
int dx[]={ -1, 0, 1, 0 };
int dy[]={ 0, 1, 0, -1 };
struct elem
{
    int x, y, d;
};
short n, m, x1, yyy, x2, y2, i, j, k, op, t, tim, tr[100], v[1010][1010][4], b[1010][1010];
char c;
char S[1010];
deque<elem>Q[5];
int Solve()
{
    memset(v, 127, sizeof(v));
    v[x1][yyy][tr[c]] = 0;
    Q[0].push_back({x1,yyy,tr[c]});
    while (true)
    {
        while (!Q[0].empty())
        {
            elem now = Q[0].front();
            Q[0].pop_front();
            if (now.x == x2 && now.y == y2)
                return t;
            tim=((now.d-b[now.x][now.y]-(t&3)+8)&3)+1;
            for (k = 0; k < 4; k++)
            {
                if (k == now.d)
                    continue;
                i = now.x + dx[k];
                j = now.y + dy[k];
                op = (k + 2) % 4;
                if (!(i < 0 || j < 0 || i > n || j > m) && t + tim < v[i][j][op])
                {
                    v[i][j][op] = t + tim;
                    Q[tim].push_back( { i, j, op } );
                }
            }
        }
        for (k = 0; k < 4; k++)
            swap(Q[k], Q[k + 1]);
        t++;
    }
}
int main()
{
    f >> n >> m >> x1 >> yyy >> c >> x2 >> y2;
    tr['N'] = 0;
    tr['E'] = 1;
    tr['S'] = 2;
    tr['V'] = 3;
    for (int i = 0; i <= n; i++)
    {
        f >> S;
        for (int j = 0; j <= m; j++)
            b[i][j] = tr[S[j]];
    }
    g << Solve() << '\n';
    return 0;
}
