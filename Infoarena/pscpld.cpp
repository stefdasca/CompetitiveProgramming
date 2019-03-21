#include<bits/stdc++.h>
using namespace std;
ifstream f("pscpld.in");
ofstream g("pscpld.out");
string s, s2;
long long ans;
int dp[2000002], N;
int main()
{
    f >> s2;
    N = s2.size();
    s += "$#";
    for(int i = 0; i < s2.size(); ++i)
        s += s2[i], s += '#';
    s += '$';
    int Center = 0, Right = 0, mirror;
    for (int i = 1; i < s.size()-1; ++i)
    {
        mirror = 2 * Center - i;
        if (i < Right)
            dp[i] = min(dp[mirror], Right - i);
        while(dp[i] < N && s[i+dp[i]+1] == s[i-dp[i]-1])
            ++dp[i];
        if (dp[i] + i > Right)
            Center = i, Right = i + dp[i];
        ans += dp[i]/2 + dp[i] % 2;
    }
    g << ans << '\n';
    return 0;
}

