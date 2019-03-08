#include<bits/stdc++.h>
using namespace std;
int n, k, lit[502], gr[502], dp[502][502], sol[502];
char s[502];
int main()
{
    cin >> n;
    cin >> (s+1);
    k = 1;
    for(int i = 1; i <= n; ++i)
        dp[i][i] = 1;
    int ll = 1;
    for(int i = 1; i <= n; ++i)
    {
        if(s[i] == s[ll]);
        else
        {
            for(int j = ll; j < i; ++j)
                for(int kk = j; kk < i; ++kk)
                    dp[j][kk] = 1;
            ll = i;
        }
    }
    for(int j = ll; j <= n; ++j)
        for(int kk = j; kk <= n; ++kk)
            dp[j][kk] = 1;
    for(int i = 2; i <= n; ++i)
    {
        for(int j = 1; j + i - 1 <= n; ++j)
        {
            if(dp[j][j + i - 1] == 0)
                dp[j][j + i - 1] = (1<<30);
            if(s[j] != s[j + i - 1])
            {
                for(int mid = j; mid < j + i - 1; ++mid)
                    dp[j][j + i - 1] = min(dp[j][j + i - 1], dp[j][mid] + dp[mid + 1][j + i - 1]);
            }
            else
            {
                for(int mid = j; mid < j + i - 1; ++mid)
                    dp[j][j + i - 1] = min(dp[j][j + i - 1], dp[j][mid] + dp[mid + 1][j + i - 1] - 1);
            }
        }
    }
    cout << dp[1][n] << '\n';
    return 0;
}
