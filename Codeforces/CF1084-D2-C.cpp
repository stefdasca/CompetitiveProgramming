/// Goodbye until the day we meet again

#include<bits/stdc++.h>
#define mod 1000000007
#pragma GCC optimize("O3")
using namespace std;
long long dp[100002], sum[100002];
string s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> s;
    int lastb = -1;
    long long ans = 0;
    for(int i = 0; i < s.size(); ++i)
    {
        if(s[i] == 'a')
        {
            dp[i] = 1;
            if(lastb != -1)
                dp[i] += sum[lastb];
        }
        if(s[i] == 'b')
            lastb = i;
        sum[i] = (sum[i-1] + dp[i]) % mod;
        ans = (ans + dp[i]) % mod;
    }
    cout << ans;
    return 0;
}
