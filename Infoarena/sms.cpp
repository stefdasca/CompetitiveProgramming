/*
            Infoarena SMS

    We can use linearity of expectation to solve this problem. Thus, dp[i] will be the EV of the time
necessary to type the ith letter from the string.

    By writing out the actual formula for this problem, based on the statement, we can implement the recurrence in linear time.
Because of linearity of expectation, the answer is the sum of the individual EV.

*/
#include<bits/stdc++.h>
using namespace std;
ifstream f("sms.in");
ofstream g("sms.out");
int n, k;
char s[1000002];
double dp[1000002], a[32], b[32], c[32];
int main()
{
    f >> n >> k;
    f >> (s + 1);
    for(int i = 0; i < k; ++i)
        f >> a[i] >> b[i] >> c[i];
    double sol = 0;
    for(int i = 1; i <= n; ++i)
    {
        // dp[i] = a[ch[i]] + b[ch[i]] * (2 + dp[i]) + c[ch[i]] * (1 + dp[i-1] + dp[i])
        // dp[i] * (1 - b[ch[i]] - c[ch[i]]) = a[ch[i]] + 2 * b[ch[i]] + c[ch[i]] * (1 + dp[i-1])
        // dp[i] = 1 + b[ch[i]] + c[ch[i]] * dp[i-1]) / a[ch[i]];
        dp[i] = (1 + b[s[i] - 'a'] + c[s[i] - 'a'] * dp[i-1]) / a[s[i] - 'a'];
        sol += dp[i];
    }
    g << fixed << setprecision(8) << sol;
    return 0;
}
