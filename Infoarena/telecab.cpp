/// #bettercoderthanshebeautiful
#include<bits/stdc++.h>
using namespace std;
ifstream f("telecab.in");
ofstream g("telecab.out");
int n,k,s;
int cote[100002];
int nextBigger[100002];
int traseu[100002],len;
int dp[1002][1002];
int dist(int a, int b)
{
    int d=(int)sqrt((b-a)*(b-a)+(cote[b]-cote[a])*(cote[b]-cote[a]));
    return d;
}
int main()
{
    f>>n>>k>>s;
    for(int i=1;i<=n;++i)
        f>>cote[i];
    nextBigger[n]=n+1;
    for(int i=n-1;i>=1;--i)
        if(cote[i+1]>cote[i])
            nextBigger[i]=i+1;
        else
        {
            nextBigger[i]=nextBigger[i+1];
            while(nextBigger[i]!=n+1 && cote[nextBigger[i]]<=cote[i])
                nextBigger[i]=nextBigger[nextBigger[i]];
        }
    traseu[1]=1;
    len=1;
    while(traseu[len]<n)
    {
        if(nextBigger[traseu[len]]==n+1)
            traseu[++len]=traseu[len-1]+1;
        else
            traseu[++len]=nextBigger[traseu[len-1]];
    }
    int sol=0;
    for(int i=1;i<len;++i)
        sol+=dist(traseu[i],traseu[i+1]);
    g<<sol<<'\n';
    if(cote[traseu[2]]<cote[traseu[1]])
    {
        dp[1][0]=dist(traseu[1],traseu[2]);
        dp[1][abs(cote[traseu[1]]-cote[traseu[2]])]=1;
    }
    else
        dp[1][abs(cote[traseu[1]]-cote[traseu[2]])]=dist(traseu[1],traseu[2]);
    int i=2;
    for(i=2;traseu[i]<k;++i)
    {
        int D=dist(traseu[i],traseu[i+1]);
        int diflevel=abs(cote[traseu[i]]-cote[traseu[i+1]]);
        if(cote[traseu[i+1]]>=cote[traseu[i]])
        {
            for(int j=0;j+diflevel<=s;++j)
            {
                if(!dp[i-1][j])
                    continue;
                if(dp[i][j+diflevel]!=0)
                    dp[i][j+diflevel]=min(dp[i][j+diflevel],dp[i-1][j]+D);
                else
                    dp[i][j+diflevel]=dp[i-1][j]+D;
            }
        }
        else
        {
            for(int j=0;j<=s;++j)
            {
                if(!dp[i-1][j])
                    continue;
                if(j+diflevel<=s)
                    if(dp[i][j+diflevel]!=0)
                        dp[i][j+diflevel]=min(dp[i][j+diflevel],dp[i-1][j]+1);
                    else
                        dp[i][j+diflevel]=dp[i-1][j]+1;
                if(dp[i][j]!=0)
                    dp[i][j]=min(dp[i][j],dp[i-1][j]+D);
                else
                    dp[i][j]=dp[i-1][j]+D;
            }
        }
    }
    int mint=1e9;
    for(int j=0;j<=s;++j)
        if(dp[i-1][j])
            mint=min(mint,dp[i-1][j]);
    g<<mint<<'\n';
    return 0;
}
