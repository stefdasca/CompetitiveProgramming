#include<bits/stdc++.h>
using namespace std;
ifstream f("sablon.in");
ofstream g("sablon.out");
string S,s;
bool dp[1502][1502][2];
int n,q,m;
bool gut()
{
    dp[0][0][0]=1;
    f>>s;
    m=s.size();
    s=' '+s;
    for(int i=1;i<=n;i++)
        for(int j=0;j<=m;j++)
        {
            if(S[i]=='?')
            {
                dp[i][j][0]=dp[i-1][j-1][0];
                dp[i][j][1]=dp[i-1][j-1][1];
                continue;
            }
            if(S[i]=='*')
            {
                dp[i][j][0]=(dp[i-1][j][0]|dp[i-1][j-1][0]|dp[i][j-1][0]);
                dp[i][j][1]=(dp[i-1][j][1]|dp[i-1][j-1][1]|dp[i][j-1][1]);
                continue;
            }
            if(S[i]==s[j])
            {
                dp[i][j][0]=dp[i-1][j-1][0];
                dp[i][j][1]=(dp[i-1][j-1][1]|dp[i-1][j][0]);
            }
            else
            {
                dp[i][j][0]=0;
                dp[i][j][1]=dp[i-1][j][0];
            }
        }
    return (dp[n][m][1]|dp[n][m][0]);
}
int main()
{
    f>>S>>q;
    n=S.size();
    S=' '+S;
    while(q--)
        g<<gut()<<'\n';
    return 0;
}
