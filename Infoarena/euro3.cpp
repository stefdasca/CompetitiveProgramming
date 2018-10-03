#include<bits/stdc++.h>
using namespace std;
ifstream f("euro3.in");
ofstream g("euro3.out");
int t;
int n,vmax;
int dp[8002],v[4002];
int mini[8002],sol[8002];
int main()
{
    f>>t;
    for(int i=1;i<=t;++i)
    {
        f>>n>>vmax;
        for(int j=1;j<=vmax;++j)
            dp[j]=mini[j]=sol[j]=-1;
        for(int j=1;j<=n;++j)
            f>>v[j];
        sort(v+1,v+n+1);
        for(int a=1;a<=n;++a)
        {
            for(int j=vmax-v[a];j>=0;--j)
            {
                if(dp[j]==-1)
                    continue;
                if(j==0)
                {
                    dp[j+v[a]]=1;
                    mini[j+v[a]]=v[a];
                    sol[j+v[a]]=0;
                }
                else
                    if(dp[j+v[a]]==-1)
                    {
                        dp[j+v[a]]=1;
                        mini[j+v[a]]=mini[j];
                        sol[j+v[a]]=v[a]-mini[j+v[a]];
                    }
                    else
                        if(mini[j]>mini[j+v[a]])
                        {
                            mini[j+v[a]]=mini[j];
                            sol[j+v[a]]=min(sol[j+v[a]],v[a]-mini[j+v[a]]);
                        }
            }
        }
        for(int j=1;j<=vmax;++j)
        {
            if(dp[j]==-1)
                g<<-1<<" ";
            else
                g<<sol[j]<<" ";
        }
        g<<'\n';
    }
}
