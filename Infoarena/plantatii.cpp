#include<bits/stdc++.h>
using namespace std;
ifstream f("plantatii.in");
ofstream g("plantatii.out");
unsigned int t,n,mat[1002][1002],dp[1002][1002],ds[1002][1002],w;
unsigned int s1,s2;
int max1,max2;
void Bin_Search_Par()
{
    int b=1;
    int e=n/2;
    while(b<=e)
    {
        int M=(b+e)/2;
        bool ok=0;
        int m=2*M;
        for(int i=m;i<=n;++i)
            for(int j=m;j<=n;++j)
            {
                s1=dp[i][j]-dp[i-m][j-m];
                s2=ds[i][j-m+1]-ds[i-m][j+1];
                if(s1+s2<=w){
                    ok=1;
                    i=n+1;
                    j=n+1;
                }
            }
        if(ok==1)
            max1=m,b=M+1;
        else
            e=M-1;
    }
}
void Bin_Search_Impar()
{
    int b=0;
    int e=n/2;
    while(b<=e)
    {
        int M=(b+e)/2;
        bool ok=0;
        int m=2*M+1;
        for(int i=m;i<=n;++i)
            for(int j=m;j<=n;++j)
            {
                s1=dp[i][j]-dp[i-m][j-m];
                s2=ds[i][j-m+1]-ds[i-m][j+1];
                if(s1+s2-mat[i-M][j-M]<=w){
                    ok=1;
                    i=n+1;
                    j=n+1;
                }
            }
        if(ok==1)
            max2=m,b=M+1;
        else
            e=M-1;
    }
}
int main()
{
    f>>t;
    for(;t;--t)
    {
        f>>n>>w;
        max1=0;
        max2=0;
        for(int i=1;i<=n;++i)
            for(int j=1;j<=n;++j)
                f>>mat[i][j],dp[i][j]=0,ds[i][j]=0;
        for(int i=1;i<=n;++i)
            for(int j=1;j<=n;++j)
                dp[i][j]=mat[i][j]+dp[i-1][j-1],ds[i][j]=mat[i][j]+ds[i-1][j+1];
        Bin_Search_Par();
        Bin_Search_Impar();
        g<<max(max1,max2)<<'\n';
    }
    return 0;
}
