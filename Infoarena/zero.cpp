#include<bits/stdc++.h>
using namespace std;
ifstream f("zero.in");
ofstream g("zero.out");
int L,B,P,Q;
int sum[28],ss;
int dp2[3][28][28][28];
int sz2[3][28][28];
int sum2[28],ss2;
int main()
{
    f>>L;
    f>>B;
    f>>P;
    f>>Q;
    int nr=B-1;
    while(nr)
    {
        dp2[1][0][0][++sz2[1][0][0]]=nr%10;
        nr/=10;
    }
    for(int i=2;i<=L;++i)
    {
        for(int j=0;j<i;++j)
            for(int k=0;k<=j;++k)
            {
                for(int p=1;p<=sz2[1][j][k];++p)
                    dp2[2][max(j,k+1)][k+1][p]+=dp2[1][j][k][p];
                sz2[2][max(j,k+1)][k+1]=max(sz2[2][max(j,k+1)][k+1],sz2[1][j][k]);
                for(int p=1;p<=sz2[1][j][k];++p)
                    dp2[2][j][0][p]+=dp2[1][j][k][p]*(B-1);
                sz2[2][j][0]=max(sz2[2][j][0],sz2[1][j][k]);
            }
        for(int j=0;j<i;++j)
            for(int k=0;k<=j;++k){
                for(int p=1;p<=sz2[2][j][k];++p)
                {
                    dp2[2][j][k][p+1]+=dp2[2][j][k][p]/10;
                    dp2[2][j][k][p]%=10;
                    if(dp2[2][j][k][p+1] && p==sz2[2][j][k])
                        ++sz2[2][j][k];
                    dp2[1][j][k][p]=dp2[2][j][k][p];
                    dp2[2][j][k][p]=0;
                }
                sz2[1][j][k]=sz2[2][j][k];
                sz2[2][j][k]=0;
            }
    }
    ss=0;
    for(int i=0;i<=P;++i)
        for(int j=0;j<=i;++j)
        {
            ss=max(ss,sz2[1][i][j]);
            for(int p=1;p<=sz2[1][i][j];++p)
                sum[p]+=dp2[1][i][j][p];
        }
    for(int j=1;j<=ss;++j)
    {
        sum[j+1]+=sum[j]/10;
        sum[j]%=10;
        if(sum[ss+1])
            ++ss;
    }
    for(int j=ss;j>=1;--j)
        g<<sum[j];
    g<<'\n';
    for(int i=Q;i<=L;++i)
        for(int j=0;j<=i;++j)
        {
            ss2=max(ss2,sz2[1][i][j]);
            for(int p=1;p<=sz2[1][i][j];++p)
                sum2[p]+=dp2[1][i][j][p];
        }
    for(int j=1;j<=ss2;++j)
    {
        sum2[j+1]+=sum2[j]/10;
        sum2[j]%=10;
        if(sum2[ss2+1])
            ++ss2;
    }
    for(int j=ss2;j>=1;--j)
        g<<sum2[j];
    g<<'\n';
    return 0;
}
