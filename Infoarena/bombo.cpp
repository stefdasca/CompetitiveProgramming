#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
ifstream f("bombo.in");
ofstream g("bombo.out");
int n,m;
deque<pair<short,int> >v[6];
struct hmt
{
    short a,b,c,d;
    int e;
};
deque<hmt>q;
int dp[12][12][12][12];
int main()
{
    f>>n>>m;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
        {
            int a,b;
            f>>a>>b;
            v[i].push_front({a,b});
        }
    q.push_back({0,0,0,0,0});
    int d=0;
    int maxsol=0;
    while(!q.empty())
    {
        while(!q.empty())
        {
            hmt love=q.front();
            q.pop_front();
            while(love.a<v[1].size() && v[1][love.a].fi<=d)
                ++love.a;
            while(love.b<v[2].size() && v[2][love.b].fi<=d)
                ++love.b;
            while(love.c<v[3].size() && v[3][love.c].fi<=d)
                ++love.c;
            while(love.d<v[4].size() && v[4][love.d].fi<=d)
                ++love.d;
            if(love.a<v[1].size())
            {
                hmt love2=love;
                love2.e+=v[1][love2.a].se*(v[1][love2.a].fi-d);
                dp[love2.a+1][love2.b][love2.c][love2.d]=max(dp[love2.a+1][love2.b][love2.c][love2.d],love2.e);
                maxsol=max(maxsol,love2.e);
            }
            if(love.b<v[2].size())
            {
                hmt love2=love;
                love2.e+=v[2][love2.b].se*(v[2][love2.b].fi-d);
                maxsol=max(maxsol,love2.e);
                dp[love2.a][love2.b+1][love2.c][love2.d]=max(dp[love2.a][love2.b+1][love2.c][love2.d],love2.e);
            }
            if(love.c<v[3].size())
            {
                hmt love2=love;
                love2.e+=v[3][love2.c].se*(v[3][love2.c].fi-d);
                 maxsol=max(maxsol,love2.e);
                dp[love2.a][love2.b][love2.c+1][love2.d]=max(dp[love2.a][love2.b][love2.c+1][love2.d],love2.e);
            }
            if(love.d<v[4].size())
            {
                hmt love2=love;
                love2.e+=v[4][love2.d].se*(v[4][love2.d].fi-d);
                 maxsol=max(maxsol,love2.e);
                dp[love2.a][love2.b][love2.c][love2.d+1]=max(dp[love2.a][love2.b][love2.c][love2.d+1],love2.e);
            }
        }
        for(int i=0;i<=v[1].size();++i)
            for(int j=0;j<=v[2].size();++j)
                for(int k=0;k<=v[3].size();++k)
                    for(int p=0;p<=v[4].size();++p)
                        if(dp[i][j][k][p])
                            q.push_back({i,j,k,p,dp[i][j][k][p]}),dp[i][j][k][p]=0;
        ++d;
    }
    g<<maxsol;
    return 0;
}
