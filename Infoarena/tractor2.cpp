#define LL long long
#include<bits/stdc++.h>
using namespace std;
ifstream f("tractor2.in");
ofstream g("tractor2.out");
LL n,m,c;
LL dp[3002][1002];
bool vis[3002][1002];
struct qu
{
    LL when, hm, emb;
};
qu v[3002];
qu v2[1002];
LL sz1,sz2;
int main()
{
    f>>n>>m>>c;
    vis[0][0]=1;
    for(LL i=1;i<=n+m;++i)
    {
        LL a,b,c;
        f>>a>>b>>c;
        if(b==1)
            v[++sz1]={a,b,c};
        else
            v2[++sz2]={a,b,c};
    }
    for(LL i=0;i<=n;++i)
        for(LL j=0;j<=m;++j)
        {
            if(!vis[i][j])
                continue;
            LL pr=dp[i][j]+c;
            LL maxt=0;
            /// numai din prima
            if(i+4<=n)
            {
                for(LL k=i+1;k<=i+4;++k)
                    maxt=max(maxt,v[k].emb);
                LL k=i+4;
                LL maxx=max(dp[i][j],v[k].when);
                if(!vis[k][j])
                {
                    dp[k][j]=maxx+maxt+c;
                    vis[k][j]=1;
                }
                else
                    dp[k][j]=min(dp[k][j],maxx+maxt+c);
            }
            maxt=0;
            LL sum=0;
            for(LL k=j+1;k<=max(j+2,m);++k)
            {
                maxt=max(maxt,v2[k].emb);
                LL maxx=max(dp[i][j],v2[k].when);
                sum+=v2[k].hm;
                if(sum>4)
                    break;
                LL max2=maxt;
                for(LL p=i+1;p<=n && sum+p-i<=4;++p)
                    max2=max(max2,v[p].emb),maxx=max(maxx,v[p].when);
                LL p=4+i-sum;
                if(p>n)
                    continue;
                if(!vis[p][k])
                {
                    dp[p][k]=maxx+max2+c;
                    vis[p][k]=1;
                }
                else
                    dp[p][k]=min(dp[p][k],maxx+max2+c);
            }
        }
    g<<dp[n][m];
    return 0;
}
