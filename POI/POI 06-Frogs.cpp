/*
            POI 06-Frogs

    In order to find the maximum distance, we are going to binary search on the answer(find a path which crosses only cells with value >= mid)

    In order to find dist[i][j] = min distance from a scourge to (i, j), we are going to speed up an O(n^3) algorithm.

    How are we going to do this? We can keep the closest scourge to (i, j) in the same line and use the fact that opt[i][j] <= opt[i+1][j] for all i
to reduce the constant.

*/
#include<bits/stdc++.h>
#define god dimasi5eks
#pragma GCC optimize("O3")
#define fi first
#define se second
#define pb push_back
#define pf push_front
#define mod 1000000007
#define dancila 3.14159265359
#define eps 1e-9

// #define fisier 1

using namespace std;

typedef long long ll;

int n, m, nr;
int xa, ya, xb, yb;

int ox[] = {-1, 0, 1, 0};
int oy[] = {0, 1, 0, -1};
struct wall
{
    int x, y;
};
wall v[1000002];

int dist[1002][1002], dist2[1002][1002], rc[1002][1002], rcd[1002][1002], mare = (1<<30);

int opt[1002][1002], opt2[1002][1002], nxt[1002], nxtrev[1002];

bool viz[1002][1002], zid[1002][1002];

bool iz[1002];

bool chk(int d)
{
    memset(viz, 0, sizeof(viz));
    queue<pair<int, int> >d2;
    d2.push({xa, ya});
    viz[xa][ya] = 1;
    while(!d2.empty())
    {
        pair<int, int> nod = d2.front();
        d2.pop();
        int X = nod.fi;
        int Y = nod.se;
        for(int dir = 0; dir <= 3; ++dir)
        {
            int nxtX = X + ox[dir];
            int nxtY = Y + oy[dir];
            if(viz[nxtX][nxtY] || dist[nxtX][nxtY] < d)
                continue;
            if(nxtX >= 1 && nxtY >= 1 && nxtX <= n && nxtY <= m)
            {
                viz[nxtX][nxtY] = 1;
                d2.push({nxtX, nxtY});
            }
        }
    }
    if(viz[xb][yb])
        return 1;
    return 0;
}
int main()
{

    #ifdef fisier
        ifstream f("input.in");
        ofstream g("output.out");
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    cin >> xa >> ya >> xb >> yb;
    cin >> nr;
    for(int i = 1; i <= nr; ++i)
    {
        cin >> v[i].x >> v[i].y;
        zid[v[i].x][v[i].y] = 1;
        iz[v[i].x] = 1;
    }
    nxt[n] = n+1;
    for(int i = n-1; i >= 1; --i)
        if(iz[i+1])
            nxt[i] = i+1;
        else
            nxt[i] = nxt[i+1];
    for(int i = 1; i <= n; ++i)
    {
        rcd[i][m+1] = m+1;
        for(int j = 1; j <= m; ++j)
        {
            opt[0][j] = 1;
            opt[n+1][j] = n;
            if(zid[i][j])
                rc[i][j] = j;
            else
                rc[i][j] = rc[i][j-1];
        }
        for(int j = m; j >= 1; --j)
        {
            if(zid[i][j])
                rcd[i][j] = j;
            else
                rcd[i][j] = rcd[i][j+1];
        }
        for(int j = 1; j <= m; ++j)
            if(rc[i][j] && rcd[i][j] != m+1)
                rc[i][j] = min(j - rc[i][j], rcd[i][j] - j);
            else
                if(rc[i][j])
                    rc[i][j] = j - rc[i][j];
                else
                    if(rcd[i][j] != m+1)
                        rc[i][j] = rcd[i][j] - j;
                    else
                        rc[i][j] = -1;
    }
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
        {
            if(zid[i][j]);
            else
            {
                dist2[i][j] = mare;
                dist[i][j] = mare;
            }
        }
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
        {
            if(dist[i][j] == 0)
            {
                opt[i][j] = i;
                continue;
            }
            for(int x = opt[i-1][j]; x <= i; x = nxt[x])
            {
                int diff = i - x;
                if(rc[x][j] != -1 && diff * diff + rc[x][j] * rc[x][j] < dist[i][j])
                    dist[i][j] = diff * diff + rc[x][j] * rc[x][j], opt[i][j] = x;
            }
            if(dist[i][j] == mare)
                opt[i][j] = i+1;
        }
    for(int i = n; i >= 1; --i)
        for(int j = 1; j <= m; ++j)
        {
            if(dist2[i][j] == 0)
            {
                opt2[i][j] = i;
                continue;
            }
            for(int x = i; x <= opt2[i+1][j]; x = nxt[x])
            {
                int diff = x - i;
                if(rc[x][j] != -1 && diff * diff + rc[x][j] * rc[x][j] < dist2[i][j])
                    dist2[i][j] = diff * diff + rc[x][j] * rc[x][j], opt2[i][j] = x;
            }
            if(dist2[i][j] == mare)
                opt2[i][j] = i-1;
            if(dist2[i][j] < dist[i][j])
                dist[i][j] = dist2[i][j];
        }
    int st = 0;
    int dr = min(dist[xa][ya], dist[xb][yb]);
    int ans = 0;
    while(st <= dr)
    {
        int mid = (st + dr) / 2;
        if(chk(mid))
            ans = mid, st = mid + 1;
        else
            dr = mid - 1;
    }
    cout << ans;
    return 0;
}
