#include<bits/stdc++.h>
using namespace std;
ifstream f("matrix.in");
ofstream g("matrix.out");
int n,dp[1002][1002],m;
char ma[1002][1002],OR[1002];
bool gut[1002][1002];
int frq[30];
int main()
{
    f>>n>>m;
    for(int i=1;i<=n;++i)
        f>>(ma[i]+1);
    for(int i=1;i<=m;++i)
    {
        f>>(OR+1);
        for(int j=1;j<=m;++j)
            frq[OR[j]-'a']++;
    }
    memset(gut,1,sizeof(gut));
    for(char c='a';c<='z';++c)
    {
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;++i)
            for(int j=1;j<=n;++j)
            {
                dp[i][j]=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]+(ma[i][j]==c);
                if(i>=m && j>=m)
                    if((dp[i][j]-dp[i-m][j]-dp[i][j-m]+dp[i-m][j-m])!=frq[c-'a'])
                        gut[i][j]=0;
            }
    }
    int sol=0;
    for(int i=m;i<=n;++i)
        for(int j=m;j<=n;++j)
            sol+=gut[i][j];
    g<<sol;
    return 0;
}
