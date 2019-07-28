/*
        CF 100283-gym-C

    * Notice that we have to optimize the obvious O(n^2 * m * s) solution by reducing it by one of n factors.
    * We can observe that each time we're doing an update, we're updating a square of size (t-1) * (t-1) except some corner triangles.
    * Therefore, we can keep data of values which should be added or dropped for each of the 5 matrices(squares and the 4 rotations of
the triangles).

*/
#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#define fi first
#define se second
#define pb push_back
#define pf push_front
#define mod 1000000007

using namespace std;

typedef long long ll;


ifstream fin("treasures.in");

int add(int a, int b)
{
    ll x = a+b;
    if(x >= mod)
        x -= mod;
    if(x < 0)
        x += mod;
    return x;
}
ll mul(ll a, ll b)
{
    return (a*b) % mod;
}

int t;
int n, m, s, pi, pj;
int sum[302][302], val[302][302];
int ad[5][302][302], dr[5][302][302];
int dirx[] = {0, 1, 1, -1, -1};
int diry[] = {0, -1, 1, -1, 1};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    fin >> t;
    for(int i = 1; i <= t; ++i)
    {
        fin >> n >> m >> s >> pi >> pj;
        pi += 100, pj += 100;
        memset(sum, 0, sizeof(sum));
        memset(val, 0, sizeof(val));
        memset(ad, 0, sizeof(ad));
        for(int x = 101; x <= 100 + n; ++x)
            for(int y = 101; y <= 100 + m; ++y)
                fin >> val[x][y];
        sum[pi][pj] = 1;
        cout << "Case " << i << ": ";
        --s;
        while(s >= 1)
        {
            memset(ad, 0, sizeof(ad));
            memset(dr, 0, sizeof(dr));
            for(int x = 101; x <= 100 + n; ++x)
                for(int y = 101; y <= 100 + m; ++y)
                {
                    if(!sum[x][y])
                        continue;
                    /// add in square
                    ad[0][x - s][y - s] = add(ad[0][x - s][y - s], sum[x][y]);
                    ad[0][x - s][y + s + 1] = add(ad[0][x - s][y + s + 1], -sum[x][y]);
                    ad[0][x + s + 1][y - s] = add(ad[0][x + s + 1][y - s], -sum[x][y]);
                    ad[0][x + s + 1][y + s + 1] = add(ad[0][x + s + 1][y + s + 1], sum[x][y]);
                    // drop upper left corner
                    ad[1][x - s][y - s] = add(ad[1][x - s][y - s], sum[x][y]);
                    ad[1][x - s][y] = add(ad[1][x - s][y], -sum[x][y]);
                    dr[1][x - s + 1][y - s - 1] = add(dr[1][x - s + 1][y - s - 1], sum[x][y]);
                    dr[1][x + 1][y - s - 1] = add(dr[1][x + 1][y - s - 1], -sum[x][y]);
                    // drop upper right corner
                    ad[2][x - s][y + 1] = add(ad[2][x - s][y + 1], sum[x][y]);
                    ad[2][x - s][y + s + 1] = add(ad[2][x - s][y + s + 1], -sum[x][y]);
                    dr[2][x - s + 1][y + s + 1] = add(dr[2][x - s + 1][y + s + 1], sum[x][y]);
                    dr[2][x + 1][y + s + 1] = add(dr[2][x + 1][y + s + 1], -sum[x][y]);
                    // drop lower left corner
                    ad[3][x + s][y - s] = add(ad[3][x + s][y - s], sum[x][y]);
                    ad[3][x + s][y] = add(ad[3][x + s][y], -sum[x][y]);
                    dr[3][x][y - s - 1] = add(dr[3][x][y - s - 1], sum[x][y]);
                    dr[3][x + s][y - s - 1] = add(dr[3][x + s][y - s - 1], -sum[x][y]);
                    // drop lower right corner
                    ad[4][x + s][y + 1] = add(ad[4][x + s][y + 1], sum[x][y]);
                    ad[4][x + s][y + s + 1] = add(ad[4][x + s][y + s + 1], -sum[x][y]);
                    dr[4][x][y + s + 1] = add(dr[4][x][y + s + 1], sum[x][y]);
                    dr[4][x + s][y + s + 1] = add(dr[4][x + s][y + s + 1], -sum[x][y]);
                }
            for(int x = 101 - s; x <= 100 + n + s; ++x)
                for(int y = 101 - s; y <= 100 + m + s; ++y)
                    ad[0][x][y] = add(add(ad[0][x][y], ad[0][x-1][y]), add(ad[0][x][y-1], -ad[0][x-1][y-1]));
            for(int x = 101 - s; x <= 100 + n + s; ++x)
                for(int y = 101 - s; y <= 100 + m + s; ++y)
                    for(int j = 1; j <= 4; ++j)
                        ad[j][x][y] = add(ad[j][x][y], ad[j][x][y-1]);
            for(int y = 101 - s; y <= 100 + m + s; ++y)
                for(int x = 101 - s; x <= 100 + n + s; ++x)
                    for(int j = 1; j <= 4; ++j)
                        dr[j][x][y] = add(dr[j][x][y], dr[j][x-1][y]);
            for(int x = 101 - s; x <= 100 + n; ++x)
                for(int y = 101 - s; y <= 100 + m + s; ++y)
                    ad[1][x][y] = add(add(ad[1][x][y], ad[1][x - dirx[1]][y - diry[1]]), -dr[1][x][y]);
            for(int x = 101 - s; x <= 100 + n; ++x)
                for(int y = 101 - s; y <= 100 + m + s; ++y)
                    ad[2][x][y] = add(add(ad[2][x][y], ad[2][x - dirx[2]][y - diry[2]]), -dr[2][x][y]);
            for(int x = 100 + n + s; x >= 101; --x)
                for(int y = 101 - s; y <= 100 + m + s; ++y)
                    ad[3][x][y] = add(add(ad[3][x][y], ad[3][x - dirx[3]][y - diry[3]]), -dr[3][x][y]);
            for(int x = 100 + n + s; x >= 101; --x)
                for(int y = 101 - s; y <= 100 + m + s; ++y)
                    ad[4][x][y] = add(add(ad[4][x][y], ad[4][x - dirx[4]][y - diry[4]]), -dr[4][x][y]);
            for(int x = 101; x <= 100 + n; ++x)
                for(int y = 101; y <= 100 + m; ++y)
                {
                    sum[x][y] = ad[0][x][y];
                    for(int p = 1; p <= 4; ++p)
                        sum[x][y] = add(sum[x][y], -ad[p][x][y]);
                }
            --s;
        }
        ll ans = 0;
        for(int x = 101; x <= 100 + n; ++x)
            for(int y = 101; y <= 100 + m; ++y)
                ans = add(ans, mul(val[x][y], sum[x][y]));
        cout << ans << '\n';
    }
    return 0;
}

