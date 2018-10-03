#include<bits/stdc++.h>
using namespace std;
ifstream f("stiva.in");
ofstream g("stiva.out");
int dp[502][502];
char c[502];
int n;
int main()
{
    f>>(c+1);
    n=strlen(c+1);
    for(int i=n;i>=1;i--)
        for(int j=i;j<=n;++j){
            dp[i][j]=dp[i][j-1]+1;
            for(int k=i;k<j;++k)
                if(c[k]==c[j])
                    dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j-1]);
        }
    g<<dp[1][n]*2+n;
    return 0;
}
