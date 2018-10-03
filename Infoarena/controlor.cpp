#include<bits/stdc++.h>
using namespace std;
ifstream f("controlor.in");
ofstream g("controlor.out");
int n;
int mat[1002][1002];
int dp[1002][1002];
int sp[1002][1002];
int main()
{
    f>>n;
    for(int i=1;i<n;++i)
        for(int j=1;j<=n-i;++j)
            f>>mat[i][j],sp[i][j]=sp[i][j-1]+mat[i][j];
    for(int i=1;i<n;++i)
        dp[i][1]=sp[i][n-i];
    for(int j=2;j<n;++j)
        for(int i=1;i<n;++i)
            dp[i][j]=dp[i][1]-sp[i][j-1]+dp[i+1][j-1];
    for(int i=1;i<n;g<<'\n',++i)
        for(int j=1;j<=n-i;++j)
            g<<dp[i][j]<<" ";
    return 0;
}
