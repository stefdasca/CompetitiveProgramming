/*
                    SPOJ TRIOMINO

    Let's use sprague-grundy numbers to solve this game. One can observe that we can use recursive dp to solve this game.
Basically, let's note dp[i][j] = mex of games which can be created from a rectangle 2*i if we have some additional spaces:

    j = 0(no space), j = 1(one space), j = 2(two spaces on same side), j = 3(two spaces on different sides).

    Based on the length and the number of spaces, we can find the transitions for our DP solution.

    Therefore, the answer for our game will be found in dp[x][0], and we're going to print X if dp[x][0] isn't 0, otherwise
print Y.

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

// #define fisier

using namespace std;

typedef long long ll;

int dp[1005][4];
int solve(int len, int tip)
{
    if(dp[len][tip] != -1)
        return dp[len][tip];
    set<int> mexvals;
    if(tip == 1)
        mexvals.insert(solve(len - 1, 0));
    if(tip == 2)
        mexvals.insert(solve(len - 1, 1));
    if(tip == 3)
        mexvals.insert(solve(len - 1, 1));
    for(int st = 0; st + 2 <= len; ++st)
    {
        if(tip == 0)
        {
            mexvals.insert(solve(st, 0) ^ solve(len - st - 2, 1));
            mexvals.insert(solve(st, 1) ^ solve(len - st - 2, 0));
        }
        if(tip == 1)
        {
            mexvals.insert(solve(st, 2) ^ solve(len - st - 2, 0));
            mexvals.insert(solve(st, 3) ^ solve(len - st - 2, 0));
            mexvals.insert(solve(st, 1) ^ solve(len - st - 2, 1));
        }
        if(tip == 2 || tip == 3)
        {
            mexvals.insert(solve(st, 2) ^ solve(len - st - 2, 1));
            mexvals.insert(solve(st, 3) ^ solve(len - st - 2, 1));
            mexvals.insert(solve(st, 1) ^ solve(len - st - 2, 2));
            mexvals.insert(solve(st, 1) ^ solve(len - st - 2, 3));
        }
    }
    dp[len][tip] = 0;
    while(mexvals.find(dp[len][tip]) != mexvals.end())
        ++dp[len][tip];
    return dp[len][tip];
}
int main()
{

#ifdef fisier
    ifstream f("input.in");
    ofstream g("output.out");
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    memset(dp, -1, sizeof(dp));
    dp[0][0] = dp[0][1] = dp[0][2] = dp[0][3] = dp[1][0] = 0;
    for(; t; --t)
    {
        int x;
        cin >> x;
        int ans = solve(x, 0);
        if(ans)
            cout << "X\n";
        else
            cout << "Y\n";
    }
    return 0;
}
