#include<bits/stdc++.h>
using namespace std;
ifstream f("munte3.in");
ofstream g("munte3.out");
int n;
int dp[202][202][102];
int len[202][202];
inline void add(int a[], int b[], int &x, int y)
{
    x=max(x,y);
    int t=0;
    for(int i=1;i<=x;++i)
    {
        a[i]=a[i]+b[i]+t;
        t=a[i]/10;
        a[i]%=10;
    }
    if(t)
        a[++x]=t;
}
int main()
{
    f>>n;
    dp[0][0][1]=len[0][0]=1;
    dp[0][0][0]=dp[0][0][1]=1;
    for (int i=1; i<=2*n-2; i++)
    {
        add(dp[i][0],dp[i-1][1],len[i][0],len[i-1][1]);
        for (int j=1; j<=i; j++)
        {
            add(dp[i][j],dp[i-1][j-1],len[i][j],len[i-1][j-1]);
            if (i>=2)
              add(dp[i][j],dp[i-2][j],len[i][j],len[i-2][j]);
            add(dp[i][j],dp[i-1][j+1],len[i][j],len[i-1][j+1]);
        }
    }
    for(int i=len[2*n-2][0];i>=1;i--)
       g<<dp[2*n-2][0][i];
    return 0;
}
