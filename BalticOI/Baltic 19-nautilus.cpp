/*
        Baltic 19-Nautilus

    dp[i][j][k] = 1 or 0 if we can get to (i, j) in k moves

    However, implementing this recurrence is not enough, so we must use bitsets, since we can use bitshift to do the transitions much faster.

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

int n, m, k;

string s;
char mat[502][502];
bitset<502 * 502> dp, pos;

int main()
{

    #ifdef fisier
        ifstream f("input.in");
        ofstream g("output.out");
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> k;
    for(int i = 1; i <= n; ++i)
        cin >> (mat[i] + 1);
    cin >> s;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            if(mat[i][j] != '#')
                dp[(i - 1) * (m + 1) + j] = 1;
    pos = dp;
    for(int i = 0; i < k; ++i)
    {
        if(s[i] == 'E')
            dp = (dp << 1) & pos;
        if(s[i] == 'W')
            dp = (dp >> 1) & pos;
        if(s[i] == 'N')
            dp = (dp >> (m + 1)) & pos;
        if(s[i] == 'S')
            dp = (dp << (m + 1)) & pos;
        if(s[i] == '?')
            dp = ((dp >> 1) | (dp << 1) | (dp >> (m + 1)) | (dp << (m + 1))) & pos;
    }
    cout << dp.count();
    return 0;
}
