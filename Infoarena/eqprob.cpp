#include<bits/stdc++.h>
using namespace std;
ifstream f("eqprob.in");
ofstream g("eqprob.out");
int t;
int n;
long long pos2,pos,dp[52][52];
char c[55],c2[55];
void calc()
{
    memset(dp,0,sizeof(dp));
    int sz=strlen(c2+1);
    for(int i=1;i<=n;++i)
        if(c[i]==c2[1])
            dp[i][1]=1;
    for(int i=2;i<=sz;++i)
    {
        long long sum=0;
        for(int j=1;j<=n;++j)
        {
            if(c[j]==c2[i])
                dp[j][i]=sum;
            sum+=dp[j][i-1];
        }
    }
    for(int j=1;j<=n;++j)
        pos2+=dp[j][sz];
}
int main()
{
    f>>t;
    for(;t;--t)
    {
        f>>n;
        f>>(c+1);
        pos=1LL*n*(n+1)/2*((1LL<<n)-1);
        pos2=0;
        memset(c2,NULL,sizeof(c2));
        for(int i=1;i<=n;++i)
        {
            for(int j=1;j<=n-i+1;++j)
            {
                for(int k=j;k<j+i;++k)
                    c2[k-j+1]=c[k];
                calc();
            }
        }
        double sol=(0.0+pos2)/(0.0+pos);
        g<<fixed<<setprecision(12)<<sol<<'\n';
    }
    return 0;
}
