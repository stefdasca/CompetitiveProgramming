#include<bits/stdc++.h>
using namespace std;
ifstream f("antivirus.in");
ofstream g("antivirus.out");
int t,n,v[2002],k,hmp;
int st,sf;
int sol[2002][2002],hm[2002];
int dp[2002][2002];
void pieces(int left, int right)
{
    for(int i=0;i<=right-left+1;++i)
        for(int j=0;j<=right-left+1;++j)
            dp[i][j]=0;
    for(int i=0;i<right-left+1;++i)
        for(int j=0;i+j<right-left+1;++j)
        {
            int val=dp[i][j];
            if(!val && i+j)
                continue;
            if(right!=n)
                if(!dp[i][j+1])
                    dp[i][j+1]=val+v[right-j];
                else
                    dp[i][j+1]=min(dp[i][j+1],val+v[right-j]);
            if(left!=1)
                if(!dp[i+1][j])
                    dp[i+1][j]=val+v[left+i];
                else
                    dp[i+1][j]=min(dp[i+1][j],val+v[left+i]);
        }
    for(int i=0;i<=right-left+1;++i)
        for(int j=0;i+j<=right-left+1;++j)
        {
            if(!dp[i][j])
                continue;
            if(!sol[hmp][i+j])
                sol[hmp][i+j]=dp[i][j];
            else
                sol[hmp][i+j]=min(sol[hmp][i+j],dp[i][j]);
        }
}
void UnifyPieces(int cate)
{
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=hmp;++i)
    {
        for(int j=1;j<=cate;++j)
            dp[i][j]=dp[i-1][j];
        for(int j=1;j<=hm[i];sol[i][j]=0,++j)
            for(int k=cate-j;k>=0;--k)
            {
                if(k && !dp[i-1][k])
                    continue;
                if(!dp[i][j+k])
                    dp[i][j+k]=dp[i-1][k]+sol[i][j];
                else
                    dp[i][k+j]=min(dp[i][k+j],dp[i-1][k]+sol[i][j]);
            }
    }
    g<<dp[hmp][cate]<<'\n';
}
int main()
{
    f>>t;
    for(int i=1;i<=t;++i)
    {
        f>>n>>k;
        st=sf=0;
        hmp=0;
        for(int j=1;j<=n;++j)
        {
            f>>v[j];
            if(v[j]!=0)
            {
                if(!st)
                    ++hmp,st=j;
                sf=j;
            }
            else
            {
                --k;
                if(st)
                {
                    hm[hmp]=sf-st+1;
                    pieces(st,sf);
                    st=sf=0;
                }
            }
        }
        if(st!=0)
            hm[hmp]=sf-st+1,pieces(st,sf);
        UnifyPieces(k);
    }
    return 0;
}
