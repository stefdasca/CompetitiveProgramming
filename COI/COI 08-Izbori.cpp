/*
        COI 08-Izbori

    For the first part of the problem the greedy approach is obvious => give all the remaining votes to each party and be careful at conditions

    For the second part of the problem, we can use a binary search approach, where we check if we can end up with j votes for the party i.
During one step of the binary search, we're going to use dp to find out if we can accomplish the given condition.

    dp[i][j] = max number of votes if we have assigned j seats to the first i parties.

    We need to be careful at the implementation details in this case as well, because we need to be careful when it comes to checking the first condition
and when it comes to finding the solution(I used cross product instead of doubles, it may not be necessary, though).

    One can observe that even though the dp checking runs in O(nm^2 log m), we are going to run the dp at most 20 times
(only 20 parties can have 5% of votes at the same time), because of the first condition.

*/
#include<bits/stdc++.h>
using namespace std;
int v, n, m, sum, minvot;
int a[102];
int coef[102];
int proc(int poz)
{
    for(int i = 1; i <= n; ++i)
        coef[i] = 1;
    for(int i = 1; i <= m; ++i)
    {
        int mx = 0;
        for(int j = 1; j <= n; ++j)
        {
            if(a[j] * 20 < v)
                continue;
            if(mx == 0 || 1LL * a[j] * coef[mx] > 1LL * a[mx] * coef[j])
                mx = j;
        }
        coef[mx]++;
    }
    return coef[poz] - 1;
}
int dp[102][202];
int chk(int poz, int votes)
{
    memset(dp, -1, sizeof(dp));
    dp[0][0] = v - sum;
    for(int i = 0; i < n; ++i)
    {
        if(i+1 == poz)
        {
            for(int j = 0; j <= m; ++j)
                dp[i+1][j] = dp[i][j];
            continue;
        }
        for(int j = 0; j <= m; ++j)
        {
            if(dp[i][j] == -1)
                continue;
            for(int seats = 0; seats + j <= m; ++seats)
            {
                if(seats == 0)
                {
                    dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
                    continue;
                }
                if(i+1 < poz)
                {
                    int nec = (a[poz] * seats) / (votes + 1);
                    if((a[poz] * seats) % (votes + 1))
                        ++nec;
                    dp[i+1][j + seats] = max(dp[i+1][j + seats], dp[i][j] - max(0, max(minvot, nec) - a[i+1]));
                }
                else
                {
                    int nec = (a[poz] * seats) / (votes + 1) + 1;
                    dp[i+1][j + seats] = max(dp[i+1][j + seats], dp[i][j] - max(0, max(minvot, nec) - a[i+1]));
                }
            }
        }
    }
    for(int i = m; i >= 0; --i)
        if(dp[n][i] >= 0)
            return i;
}
int solve(int poz)
{
    if(a[poz] * 20 < v)
        return 0;
    int st = 0;
    int dr = m;
    int ans = m;
    while(st <= dr)
    {
        int mid = (st + dr) / 2;
        if(chk(poz, mid) + mid >= m)
            ans = mid, dr = mid - 1;
        else
            st = mid + 1;
    }
    return ans;
}
int main()
{
    cin >> v >> n >> m;
    minvot = v/20 + (v%20 > 0);
    for(int i = 1; i <= n; ++i)
        cin >> a[i], sum += a[i];
    for(int i = 1; i <= n; ++i)
    {
        a[i] += v - sum;
        cout << proc(i) << " ";
        a[i] -= v - sum;
    }
    cout << '\n';
    for(int i = 1; i <= n; ++i)
        cout << solve(i) << " ";
    cout << '\n';
    return 0;
}
