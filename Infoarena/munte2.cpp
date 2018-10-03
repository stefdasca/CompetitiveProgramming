/// #bettercoderthanshebeautiful
#include<bits/stdc++.h>
using namespace std;
ifstream f("munte2.in");
ofstream g("munte2.out");
int n,k;
double l;
struct points
{
    int x,y;
};
points v[102];
double dp[102][32];
int fw[102][32];
int wt[102];
double dist(int a, int b)
{
    double d=(v[b].x-v[a].x)*(v[b].x-v[a].x)+(v[b].y-v[a].y)*(v[b].y-v[a].y);
    d=sqrt(d);
    return d;
}
deque<int>d;
int main()
{
    f>>n>>k>>l;
    for(int i=1;i<=n;++i)
        f>>v[i].x>>v[i].y;
    for(int i=1;i<n;++i)
        for(int j=i+1;j<=n;++j)
        {
            double d=dist(i,j);
           // g<<i<<" "<<j<<" "<<d<<'\n';
            if(d>l)
                continue;
            bool ok=1;
            double dif=v[i].y-v[j].y;
            double coord;
            for(int q=i+1;q<j;++q)
            {
                coord=v[j].y+dif*(v[j].x-v[q].x+0.0)/(v[j].x-v[i].x+0.0);
                if(v[q].y>=coord)
                    ok=0;
            }
            if(ok)
            {
                for(int q=0;q<min(i,k-1);++q)
                {
                    if(dp[i][q]==0 && i!=1)
                        continue;
                    if(dp[j][q+1]==0)
                        fw[j][q+1]=i,dp[j][q+1]=dp[i][q]+d;
                    else
                        if(dp[i][q]+d<dp[j][q+1])
                            fw[j][q+1]=i,dp[j][q+1]=min(dp[j][q+1],dp[i][q]+d);
                }
            }
        }
    g<<round(dp[n][k-1])<<'\n';
    int q=n,z=k-1;
    while(z>=0)
    {
        d.push_front(q);
        q=fw[q][z];
        --z;
    }
    for(int i=0;i<d.size();++i)
        g<<d[i]<<" ";
    return 0;
}
