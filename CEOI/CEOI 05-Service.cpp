/*
        CEOI 05-Service

    One can observe that we can run a DP in O(n^2 * q), since the place of one of the three people is fixed.

    In order to rebuild the DP array, we need to store for each state in a char the place where we go next(we need to run
the DP from q to 1).

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
using namespace std;

typedef long long ll;

int n, q, mat[202][202], poz[2002];

int dp[2][202][202];
char nxt[1002][202][202];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> q;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j)
            cin >> mat[i][j];
    for(int i = 1; i <= q; ++i)
        cin >> poz[i];
    for(int i = q; i >= 1; --i)
    {
        int curr = i % 2;
        int prv = (i + 1) % 2;
        for(int a = 1; a <= n; ++a)
            for(int b = 1; b <= n; ++b)
            {
                if(i == q)
                    continue;
                int c = poz[i];
                int d = poz[i+1];
                int mini = (1<<30);
                int wh = -1;
                if(c == d)
                {
                    mini = dp[prv][a][b] + mat[c][d];
                    wh = 1;
                }
                else if(a == d)
                {
                    mini = dp[prv][c][b] + mat[a][d];
                    wh = 2;
                }
                else if(b == d)
                {
                    mini = dp[prv][c][a] + mat[b][d];
                    wh = 3;
                }
                else
                {
                    int op = dp[prv][a][b];
                    if(op + mat[c][d] < mini)
                    {
                        mini = op + mat[c][d];
                        wh = 1;
                    }
                    op = dp[prv][c][b];
                    if(op + mat[a][d] < mini)
                    {
                        mini = op + mat[a][d];
                        wh = 2;
                    }
                    op = dp[prv][c][a];
                    if(op + mat[b][d] < mini)
                    {
                        mini = op + mat[b][d];
                        wh = 3;
                    }
                }
                nxt[i][a][b] = wh;
                dp[curr][a][b] = mini;
            }
    }
    int mini = (1<<30);
    int wh = 0;
    int a, b;
    int realA = 2, realB = 3, realC = 1;
    int op = dp[1][2][3];
    op += mat[1][poz[1]];
    if(op < mini)
    {
        mini = op;
        wh = 1;
        a = 2, b = 3;
    }
    op = dp[1][1][3];
    op += mat[2][poz[1]];
    if(op < mini)
    {
        mini = op;
        wh = 2;
        a = 1, b = 3;
        realA = 1, realB = 3, realC = 2;
    }
    op = dp[1][1][2];
    op += mat[3][poz[1]];
    if(op < mini)
    {
        mini = op;
        wh = 3;
        a = 1, b = 2;
        realA = 1, realB = 2, realC = 3;
    }
    cout << mini << '\n';
    vector<int> ans;
    int cur = wh;
    int pozz = 1;
    if(cur == 1)
        ans.pb(1);
    else
        if(cur == 2)
            ans.pb(2);
        else
            ans.pb(3);
    while(pozz != q)
    {
        cur = nxt[pozz][a][b];
        if(cur == 1)
            ans.pb(realC);
        else
            if(cur == 2)
                ans.pb(realA);
            else
                ans.pb(realB);
        if(cur == 1);
        else
            if(cur == 2)
            {
                a = poz[pozz];
                swap(realC, realA);
            }
            else
                if(cur == 3)
                {
                    b = a;
                    a = poz[pozz];
                    int tmp = realC, tmp2 = realB, tmp3 = realA;
                    realA = tmp, realB = tmp3, realC = tmp2;
                }
        pozz++;
    }
    for(int i = 0; i < ans.size(); ++i)
        cout << ans[i] << " ";
    return 0;
}
