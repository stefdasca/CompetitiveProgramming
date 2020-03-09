/*
        CEOI 15-teams

    Let's define dp[i][j] to be the number of arrays of length n with max value = j.

    From dp[i][j] we can go to dp[i+1][j] and dp[i+1][j+1] if we add a new max element or not.

    Now we can use a similar approach to find the position of the kth array in the array order. Thus, we
will initialize the dp values at each position of the array.

    If the value on the position i is x, we have two cases:

    1) x is the max element from the array, so we can initialize dp[i][x-1] with v[i] - 1
    2) x is not the max element from the array, so we can initialize dp[i][max_element] with v[i] - 1

    We are doing this in order to fix the first element, thus to ensure the property of the resulting arrays to
be smaller than the requested array.

    Last but not least, we can't keep the whole recurrence because we don't have enough memory for doing this, but we can
observe that the recurrence depends only of the previous line so we can keep only the last two lines.

*/
#include<bits/stdc++.h>
using namespace std;

const int mod = 1000007;

int n, v[10002];
int dp[2][10002];

int add(int a, int b)
{
    int ans = a+b;
    if(ans >= mod)
        ans -= mod;
    return ans;
}
long long mul(long long a, long long b)
{
    return (a * b) % mod;
}
int main()
{
    cin >> n;
    int maxi = 1;
    for(int i = 1; i <= n; ++i)
    {
        cin >> v[i];
        dp[1][max(v[i], maxi) - (v[i] > maxi)] = v[i] - 1;
        maxi = max(maxi, v[i]);
        for(int j = 1; j <= i; ++j)
        {
            dp[1][j] = add(dp[1][j], mul(dp[0][j], j));
            dp[1][j+1] = add(dp[1][j+1], dp[0][j]);
        }
        memcpy(dp[0], dp[1], sizeof(dp[1]));
        memset(dp[1], 0, sizeof(dp[1]));
    }
    int sum = 1;
    for(int i = 1; i <= n; ++i)
        sum = add(sum, dp[0][i]);
    cout << sum;
    return 0;
}
