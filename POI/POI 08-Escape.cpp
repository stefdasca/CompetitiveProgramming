/*
                    POI 08-Escape

    * It can be observed that every correct path from the bank to the hideout is a spiral path.

    * Therefore, we can define a rectangle with opposing corners (Xa, Ya) and (Xb, Yb) to be the border of
one such spiral.

    * Given this information, we can do DP on rectangles to count the number of possible paths, starting from the smallest rectangles
and ending with the biggest ones.

    * In order to save memory, we will keep only the rectangles which have perimeter (size - 1) and (size - 2)

    more detailed editorial: https://github.com/mostafa-saad/MyCompetitiveProgramming/blob/master/Olympiad/POI/official/2008/editorial/uci.pdf

*/
#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#define fi first
#define se second
#define pb push_back
#define pf push_front

using namespace std;

typedef long long ll;

int mod;

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

ll pw(ll a, ll b)
{
    ll ans = 1;
    while(b)
    {
        if(b & 1)
            ans = (ans * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return ans;
}

int n, m, x, y;
bool police[105][105];
char c[106];

int step[4][2] = { {-1,0}, {0,1}, {1,0}, {0,-1} };
int dp[4][105][105][105][2];
bool free_area[4][105][105][105];

int dir, l0, l1, l2, l3, sz;

int compute()
{
    int cura = y-1 + step[(dir+3)%4][0] * l0;
    int curb = x-1 + step[(dir+3)%4][1] * l0;
    int mva = step[dir][0];
    int mvb = step[dir][1];
    free_area[dir][l0][l1][l3] = (!police[cura + mva * l1][curb + mvb * l1]) && (!police[cura - mva * l3][curb - mvb * l3]);
    if(l1)
        free_area[dir][l0][l1][l3] &= free_area[dir][l0][l1-1][l3];
    if(l3)
        free_area[dir][l0][l1][l3] &= free_area[dir][l0][l1][l3-1];
    if(!free_area[dir][l0][0][l3])
        return 0;
    if(l0 == 0)
        return 1;
    int ans = 0;
    if(l1)
        ans = add(ans, dp[dir][l0][l1-1][l2][(sz-1)%2]);
    if(free_area[dir][l0][l1][l3])
        ans = add(ans, dp[(dir+1)%4][l1][l2][l3][(sz-1)%2]);
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> mod;
    cin >> x >> y;
    for (int i = 0; i < n; i++)
    {
        cin >> c;
        for (int j = 0; j < m; j++)
            police[i][j] = (c[j] == '*');
    }
    for(sz = 2; sz <= n+m; sz++)
        for(int szn = max(1,sz-m); szn <= n && szn < sz; szn++)
            for(int a = 0; a + szn <= n; a++)
                for(int b = 0; b + sz-szn <= m; b++)
                {
                    l0 = x-1 - b;
                    l1 = y-1 - a;
                    l2 = b+sz-szn - x;
                    l3 = a+szn - y;
                    if (l0 < 0 || l1 < 0 || l2 < 0 || l3 < 0)
                        continue;
                    for (dir = 0; dir < 4; dir++)
                    {
                        dp[dir][l0][l1][l2][sz%2] = compute();
                        int tmp = l0;
                        l0 = l1;
                        l1 = l2;
                        l2 = l3;
                        l3 = tmp;
                    }
                }
    cout << dp[0][x-1][y-1][m-x][(n+m)%2];
    return 0;
}
