/*

    Editorial: https://community.topcoder.com/tc?module=Static&d1=match_editorials&d2=srm406

*/
#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#define fi first
#define se second
#define pb push_back
#define pf push_front
#define mod 100000007

using namespace std;

typedef long long ll;

int n, col[52], ok[52][52];

int dp[52][52][2];
bool gs[52][52][2];

class PolygonColors
{
     public:
        ll solve(int st, int dr, int bn)
        {
            if(st + 1 >= dr)
                return 1;
            if(gs[st][dr][bn])
                return dp[st][dr][bn];
            gs[st][dr][bn] = 1;
            ll ans = solve(st + 1, dr, 1);
            for(int i = st + 2; i < dr + bn; i++)
                if(ok[st][i])
                    ans += solve(st, i, 0) * solve(i, dr, 1);
            ans %= mod;
            return dp[st][dr][bn] = ans;
        }
        int getWays(int N, vector<int> colors)
        {
            n = N;
            for(int i = 0; i < n; ++i)
                col[i+1] = colors[i];
            col[n+1] = col[1];
            for(int i = 1; i <= n; ++i)
            {
                for(int j = i+1; j <= n; ++j)
                    if(col[i] != col[j])
                        ok[i][j] = ok[j][i] = 1;
                if(col[i] == col[i+1])
                    return 0;
            }
            return solve(1, n, 0);
        }
};


