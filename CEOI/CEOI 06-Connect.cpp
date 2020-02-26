/*
        CEOI 06-Connect

    We can solve this problem using recursive dp, after observing that at one step, we can add only one of the 11 possible states,
so we can use bitmask dp because our matrix is small.

    There is quite a bit of casework involved, because of the large number of transitions we have to deal with:

    https://github.com/mostafa-saad/MyCompetitiveProgramming/blob/master/Olympiad/CEOI/official/2006/connect.cpp
    https://github.com/mostafa-saad/MyCompetitiveProgramming/blob/master/Olympiad/CEOI/official/2006/editorial.pdf

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

int n, m, cum[13][40];

int dp[13][40][(1<<13)][2];
char a[26][82];

void read()
{
    cin >> n >> m;
    cin.get();
    for(int i = 0; i < n; ++i)
        cin.getline(a[i], m+1);
    n /= 2;
    m /= 2;
}

char *b[3][11] =
{
    {"+ +", "+ +", "+.+", "+ +", "+ +", "+ +", "+.+", "+.+", "+.+", "+ +", "+ +"},
    {"   ", ".X ", " X ", " X.", " X ", "...", " . ", ".. ", " ..", " ..", ".. "},
    {"+ +", "+ +", "+ +", "+ +", "+.+", "+ +", "+.+", "+ +", "+ +", "+.+", "+.+"},
};

void chk(int t0, int t1, int t2, int t3, int r, int c, int mask, int U, int &h0, int &h1, int &h2, int &h3);

int solve(int r, int c, int mask, int U, int reconstruct)
{
    if(r == n)
        return solve(0, c+1, mask, 0, reconstruct);
    if(c == m)
        return 0;
    if(!reconstruct && dp[r][c][mask][U] >= 0)
        return dp[r][c][mask][U];

    dp[r][c][mask][U] = (1<<20);

    int L = (mask >> r) & 1;
    int R = a[2*r+1][2*c+2] == ' ';
    int D = a[2*r+2][2*c+1] == ' ';
    int X = a[2*r+1][2*c+1] == 'X';
    int h0 = 0, h1 = 0, h2 = 0, h3 = 0;

    if(!X && !L && !U && 1 && 1)
        chk(0, 0, mask & ~(1<<r), 0, r, c, mask, U, h0, h1, h2, h3);

    if(X && L && !U && 1 && 1)
        chk(1, 1, mask & ~(1<<r), 0, r, c, mask, U, h0, h1, h2, h3);
    if(X && !L &&  U && 1 && 1)
        chk(2, 1, mask & ~(1<<r), 0, r, c, mask, U, h0, h1, h2, h3);
    if(X && !L && !U && R && 1)
        chk(3, 1, mask |  (1<<r), 0, r, c, mask, U, h0, h1, h2, h3);
    if(X && !L && !U && 1 && D)
        chk(4, 1, mask & ~(1<<r), 1, r, c, mask, U, h0, h1, h2, h3);

    if(!X &&  L && !U && R && 1)
        chk(5, 2, mask | (1<<r), 0, r, c, mask, U, h0, h1, h2, h3);
    if(!X && !L &&  U && 1 && D)
        chk(6, 2, mask & ~(1<<r), 1, r, c, mask, U, h0, h1, h2, h3);

    if(!X && L && U && 1 && 1)
        chk(7, 2, mask & ~(1<<r), 0, r, c, mask, U, h0, h1, h2, h3);
    if(!X && !L && U && R && 1)
        chk(8, 2, mask |  (1<<r), 0, r, c, mask, U, h0, h1, h2, h3);
    if(!X && !L && !U && R && D)
        chk(9, 2, mask |  (1<<r), 1, r, c, mask, U, h0, h1, h2, h3);
    if(!X &&  L && !U && 1 && D)
        chk(10, 2, mask & ~(1<<r), 1, r, c, mask, U, h0, h1, h2, h3);

    if(reconstruct)
    {
        cum[r][c] = h0;
        solve(r+1, c, h2, h3, 1);
    }
    return dp[r][c][mask][U];
}

void chk(int t0, int t1, int t2, int t3, int r, int c, int mask, int U, int &h0, int &h1, int &h2, int &h3)
{
    int v = t1 + solve(r+1, c, t2, t3, 0);
    if(v < dp[r][c][mask][U])
    {
        dp[r][c][mask][U] = v;
        h0 = t0;
        h1 = t1;
        h2 = t2;
        h3 = t3;
    }
}
int main()
{

    #ifdef fisier
        ifstream f("input.in");
        ofstream g("output.out");
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    read();
    memset(dp, -1, sizeof(dp));
    cout << solve(0, 0, 0, 0, 1) << '\n';
    for(int r = 0; r < n; ++r)
      for(int c = 0; c < m; ++c)
         for(int dr = 0; dr < 3; ++dr)
            for(int dc = 0; dc < 3; ++dc)
               if(b[dr][cum[r][c]][dc] != ' ')
                  a[2*r+dr][2*c+dc] = b[dr][cum[r][c]][dc];
    for(int i = 0; i <= n+n; cout << '\n', ++i)
        for(int j = 0; j <= m+m; ++j)
            cout << a[i][j];
    return 0;
}
