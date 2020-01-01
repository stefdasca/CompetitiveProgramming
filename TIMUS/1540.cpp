/*

    editorial: https://github.com/goswami-rahul/competitive-coding/blob/master/CompetitiveProgramming/timus/1540.cpp

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

int n, win;
vector<int> vals[52];
int dp[105][105];
vector<int> curr;
vector<int> games;
vector<vector<int> >values;
int pc;
int grundy(int L, int R)
{
    if(L == R)
        return 0;
    if(dp[L][R] != -1)
        return dp[L][R];
    vector<bool> has(105, 0), occ(105, 0);
    for(int i = L; i < R; ++i)
        occ[vals[pc][i]] = 1;
    for(int i = 1; i <= 100; ++i)
        if(occ[i])
        {
            int xr = 0;
            int s = L;
            for(int j = L; j <= R; ++j)
            {
                if(j < R && vals[pc][j] > i)
                {
                    s = j;
                    while(j < R && vals[pc][j] > i)
                        ++j;
                    if(s != L || j != R)
                        xr ^= grundy(s, j);
                }
            }
            has[xr] = 1;
            if (L == 0 && R == vals[pc].size())
                curr[i] = xr;
        }
    dp[L][R] = 0;
    while(has[dp[L][R]])
        ++dp[L][R];
    return dp[L][R];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        for(int j = 1; j <= x; ++j)
        {
            int p;
            cin >> p;
            vals[i].pb(p);
        }
        curr.resize(101);
        for(int j = 0; j <= 101; ++j)
            curr[j] = -1;
        pc = i;
        memset(dp, -1, sizeof(dp));
        games.pb(grundy(0, x));
        values.pb(curr);
        win ^= games.back();
    }
    if(win == 0)
    {
        cout << "S\n";
        return 0;
    }
    cout << "G\n";
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < vals[i].size(); ++j)
            if((games[i] ^ values[i][vals[i][j]]) == win)
            {
                cout << i + 1 << " " << j + 1 << '\n';
                return 0;
            }
    return 0;
}
