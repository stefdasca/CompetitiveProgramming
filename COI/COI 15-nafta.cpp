/*
            COI 15-nafta

    We can use BFS to find every connected component from the matrix such that the values are numbers.
For each such component, we will keep the smallest and the biggest column which was covered by some square of the component.

    Then, our goal is to find the biggest sum which can be achieved, if we chose i columns and the last one is column j. This can be done using dp.
One can observe that opt[i][j] >= opt[i][j-1], so we can use D&C DP.


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

int n, m, sum[3002][3002], sum2[3002][3002];

char mat[3002][3002];

int ox[] = {-1, 0, 1, 0};
int oy[] = {0, 1, 0, -1};

int cum[3002];
int dp[3002][3002], sp[3002][3002];
int cost(int a, int b)
{
    return sp[a][b];
}
void divide(int st, int dr, int optst, int optdr, int pz)
{
    if(st > dr || optst > optdr)
        return;
    int mid = (st + dr) / 2;
    int wht = 0;
    for(int i = min(mid, optst); i <= min(mid, optdr); ++i)
        if(dp[pz-1][i] + cum[mid] - cost(i, mid) > dp[pz][mid])
        {
            dp[pz][mid] = dp[pz-1][i] + cum[mid] - cost(i, mid);
            wht = i;
        }
    divide(st, mid-1, optst, wht, pz);
    divide(mid+1, dr, wht, optdr, pz);
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
    for(int i = 1; i <= n; ++i)
        cin >> (mat[i] + 1);
    int acm = 0;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            if(mat[i][j] >= '0' && mat[i][j] <= '9')
            {
                int L = j, R = j;
                int tot = (mat[i][j] - '0');
                deque<pair<int, int> > d;
                d.pb({i, j});
                mat[i][j] = '.';
                while(!d.empty())
                {
                    pair<int, int> nod = d[0];
                    L = min(L, nod.se);
                    R = max(R, nod.se);
                    d.pop_front();
                    for(int x = 0; x <= 3; ++x)
                    {
                        int new_x = nod.fi + ox[x];
                        int new_y = nod.se + oy[x];
                        if(new_x == 0 || new_y == 0 || new_x == n+1 || new_y == m+1)
                            continue;
                        if(mat[new_x][new_y] == '.')
                            continue;
                        tot += (mat[new_x][new_y] - '0');
                        mat[new_x][new_y] = '.';
                        d.pb({new_x, new_y});
                    }
                }
                sum[L][R] += tot;
                acm += tot;
            }
    for(int i = 1; i <= m; ++i)
        for(int j = i; j <= m; ++j)
            cum[i] += sum[i][j], cum[j+1] -= sum[i][j];
    for(int i = 1; i <= m; ++i)
        for(int j = m; j >= 1; --j)
            sum2[i][j] = sum[i][j] + sum2[i][j+1];
    for(int i = 1; i <= m; ++i)
        for(int j = m; j >= 1; --j)
            sp[i][j] = sum2[i][j] + sp[i-1][j];
    for(int i = 1; i <= m; ++i)
    {
        cum[i] += cum[i-1];
        dp[1][i] = cum[i];
    }
    for(int i = 2; i <= m; ++i)
        divide(1, m, 1, m, i);
    int ans = 0;
    for(int i = 1; i <= m; ++i)
    {
        for(int j = 1; j <= m; ++j)
            ans = max(ans, dp[i][j]);
        cout << ans << '\n';
    }
    return 0;
}
