#include<bits/stdc++.h>
using namespace std;
int n, dp[200002];
string s2,  s;
int centru = 1, centruR = 2, dr, st;
int main()
{
    cin >> n;
    cin >> s2;
    int N = s2.size();
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
    }
    return 0;
}
