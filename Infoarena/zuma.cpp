#include<bits/stdc++.h>
using namespace std;
ifstream f("zuma.in");
ofstream g("zuma.out");
int n, k, lit[502], gr[502], dp[502][502], sol[502];
char s[502];
int main()
{
    f >> n >> k;
    f >> (s+1);
    for(int i = 1; i <= n; ++i)
        dp[i][i] = 1;
    for(int i = 2; i <= n; i++)
    {
        for(int j = i - 1; j >= 1; j--)
        {
            for(int cnn = j; cnn < i; cnn++)
            {
                if(s[cnn + 1] == s[j] && dp[cnn + 1][i] != 0 && dp[j][cnn] != 0)
                    dp[j][i] = max(dp[j][i], dp[j][cnn] + dp[cnn + 1][i]);
                if(k <= dp[cnn + 1][i])
                    dp[j][i] = max(dp[j][i], dp[j][cnn]);
            }
        }
    }
    int mx = 0;
    for(int i = 1; i <= n; ++i)
    {
        mx = max(mx, sol[i-1]);
        for(int j = i; j <= n; ++j)
            if(dp[i][j] >= k)
                sol[j] = max(sol[j], mx + j - i + 1);
    }
    mx = max(mx, sol[n]);
    g << n - mx;
    return 0;
}
