/*
            IOI 07-miners

    We can use 5D dp to solve this task:

    * dp[i][digits of mask1][digits of mask2][mask1][mask2] = max sum until position i,
if the last mines have the masks equal to mask1, respectively to mask2

    * mask1 and mask2 are ternary masks used to store easily the situation for each mine.

    * The transitions aren't complicated, they are based on the character at the current position.

    * Since we can't store all the dp matrix, we will keep only the last 2 lines of it.

*/
#include<bits/stdc++.h>
using namespace std;
int n;
string s;
int dp[2][4][4][9][9];
bool viz[2][4][4][9][9];
int can[4][27], md[27];
int p3[] = {1, 3, 9};
int counter[4][27];
int nr(char c)
{
    if(c == 'B')
        return 0;
    if(c == 'M')
        return 1;
    return 2;
}
int proc(int hm, int nr)
{
    vector<int>c;
    for(int i = hm-1; i >= 0; --i)
    {
        c.push_back(nr / p3[i]);
        nr %= p3[i];
    }
    int ans = 1;
    sort(c.begin(), c.end());
    for(int i = 1; i < c.size(); ++i)
        ans = ans + (c[i] > c[i-1]);
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    cin >> s;
    s = ' ' + s;

    for(int i = 0; i <= 26; ++i)
        md[i] = i%9;
    can[0][0] = can[1][0] = can[2][0] = can[3][0] = 1;
    for(int i = 1; i <= 2; ++i)
        can[1][i] = can[2][i] = can[3][i] = 1;
    for(int i = 3; i <= 8; ++i)
        can[2][i] = can[3][i] = 1;
    for(int i = 9; i <= 26; ++i)
        can[3][i] = 1;

    for(int i = 0; i <= 26; ++i)
        for(int j = 1; j <= 3; ++j)
            if(can[j][i])
                counter[j][i] = proc(j, i);

    viz[0][0][0][0][0] = 1;

    int ans = 0;
    for(int i = 1; i <= n; ++i)
    {
        s[i] = nr(s[i]);
        int prv = (i-1) % 2;
        int cur = i % 2;
        for(int cf = 0; cf <= 3; ++cf)
            for(int prev = 0; prev <= 8; ++prev)
            {
                if(!can[cf][prev])
                    continue;
                for(int cf2 = 0; cf2 <= 3; ++cf2)
                    for(int prev2 = 0; prev2 <= 8; ++prev2)
                    {
                        if(!can[cf2][prev])
                            continue;
                        if(!viz[prv][cf][cf2][prev][prev2])
                            continue;
                        if(dp[prv][cf][cf2][prev][prev2] + 10 <= ans)
                            continue;

                        int new_state = md[prev] * 3 + s[i];
                        int new_cf = cf+1;
                        if(new_cf == 4)
                            new_cf = 3;
                        viz[cur][new_cf][cf2][md[new_state]][prev2] = 1;
                        dp[cur][new_cf][cf2][md[new_state]][prev2] = max(dp[cur][new_cf][cf2][md[new_state]][prev2], dp[prv][cf][cf2][prev][prev2] + counter[new_cf][new_state]);
                        ans = max(ans, dp[cur][new_cf][cf2][md[new_state]][prev2]);


                        new_state = md[prev2] * 3 + s[i];
                        new_cf = cf2 + 1;
                        if(new_cf == 4)
                            new_cf = 3;
                        viz[cur][cf][new_cf][prev][md[new_state]] = 1;
                        dp[cur][cf][new_cf][prev][md[new_state]] = max(dp[cur][cf][new_cf][prev][md[new_state]], dp[prv][cf][cf2][prev][prev2] + counter[new_cf][new_state]);

                        ans = max(ans, dp[cur][cf][new_cf][prev][md[new_state]]);
                    }
            }
    }
    cout << ans;
    return 0;
}
