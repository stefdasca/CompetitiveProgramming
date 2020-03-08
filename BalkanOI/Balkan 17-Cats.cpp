/*
        Balkan 17-Cats

    It is obvious that it is not optimal to move an element twice.

    Also, we can remove elements and then add them back in the array as we wish, since this is equivalent to the given operation.

    Let dp[i][j][0/1][0/1][0/1/2] = max number of elements we can keep at their place up to position i if we fixed j twos, we have an one
in prefix or not, we have a zero in prefix or not and the last element is 0/1/2.

    This can be computed in O(n^2) time and memory with some casework but since the memory limit is 16MB, we have to cut the first dimension
from the recurrence because one can observe that states from line i depends only on states from line i+1

    Last but not least, the answer will be n - max value of any value from the dp array.
*/
#include<bits/stdc++.h>
using namespace std;
int n, v[5002], cnt[3], dp[5002][2][2][3];
void verif(int i, int j, int has1, int has0, int prv)
{
    int ans = -(1<<30);
    if(has1 == 0 && prv == 1)
        return;
    if(has0 == 0 && prv == 0)
        return;
    if(prv + v[i] == 1)
    {
        if(j < cnt[2])
            ans = max(ans, dp[j+1][1][1][v[i]]);
    }
    else
        if(v[i] == 2)
        {
            if(j < cnt[2])
                ans = max(ans, dp[j+1][has1 | (prv != 0)][has0 | (prv != 1)][v[i]]);
        }
        else
            if(prv == 2)
                ans = max(ans, dp[j][has1 | (v[i] == 1)][has0 | (v[i] == 0)][v[i]]);
            else
                ans = max(ans, dp[j][has1][has0][v[i]]);
    dp[j][has1][has0][prv] = max(dp[j][has1][has0][prv], ans + 1);
}
void solve()
{
    cin >> n;
    cnt[0] = cnt[1] = cnt[2] = 0;
    for(int i = 1; i <= n; ++i)
    {
        cin >> v[i];
        cnt[v[i]]++;
    }
    if(!cnt[2])
    {
        if(cnt[0] && cnt[1])
            cout << -1 << '\n';
        else
            cout << 0 << '\n';
        return;
    }
    if(!cnt[0] || !cnt[1])
    {
        cout << 0 << '\n';
        return;
    }
    int ans = -(1<<30);
    memset(dp, 0, sizeof(dp));
    for(int i = 0; i <= 1; ++i)
        dp[cnt[2]][0][0][i] = dp[cnt[2]][0][1][i] = dp[cnt[2]][1][0][i] = -(1<<30);
    for(int i = 0; i <= cnt[2]; ++i)
        dp[i][0][0][1] = dp[i][0][1][1] = dp[i][0][0][0] = dp[i][1][0][0] = -(1<<30);
    for(int i = n; i >= 1; --i)
    {
        if(v[i] == 2)
            ans = max(ans, dp[1][1][1][2] + 1);
        else
            ans = max(ans, dp[0][v[i] == 1][v[i] == 0][v[i]] + 1);
        for(int j = 0; j <= cnt[2]; ++j)
            for(int has1 = 0; has1 <= 1; ++has1)
                for(int has0 = 0; has0 <= 1; ++has0)
                {
                    for(int last = 0; last <= 2; ++last)
                        if(v[i] != last)
                            verif(i, j, has1, has0, last);
                    verif(i, j, has1, has0, v[i]);
                }
    }
    cout << n - ans << '\n';

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    for(; t; --t)
        solve();
    return 0;
}
