#pragma GCC optimize ("O3")
#include<bits/stdc++.h>
using namespace std;
ifstream f("zidar.in");
ofstream g("zidar.out");
short n,m,x,t,nr;
short mat[53][22];
short sp[53][22];
short dp[53][402][62];
bool xx[53][402];
vector<int>R[402];
struct secv
{
    short st,sf;
};
secv v[402];
short sum(short i, short stc, short sfc)
{
    return sp[i][sfc]-sp[i][stc-1];
}
bool matches(short j, short k)
{
    return (max(v[j].st,v[k].st)<=min(v[j].sf,v[k].sf));
}
int main()
{
    f>>n>>m>>x>>t;
    for(short i=1;i<=n;++i)
        for(short j=1;j<=m;++j){
            f>>mat[i][j];
            sp[i][j]=sp[i][j-1]+mat[i][j];
        }
    short nr=0;
    short maxx=0;
    for(short i=1;i<=m;++i)
        for(short j=i;j<=m;++j){
            v[++nr]={i,j};
            dp[1][nr][j-i+1]=sum(1,i,j);
            short am=j-i+1;
            if(dp[1][nr][j-i+1]<=t && am<=x){
                maxx=max(maxx,am);
                xx[1][nr]=1;
            }
        }
    for(short i=1;i<=nr;++i)
        for(short j=1;j<=nr;++j)
            if(matches(i,j))
                R[i].push_back(j);
    for(short i=2;i<=n;++i)
    {
        bool ss=0;
        for(short j=1;j<=nr;++j)
        {
            short val=sum(i,v[j].st,v[j].sf);
            short dist=(v[j].sf-v[j].st+1);
            if(val>t || dist>x)
                continue;
            for(int k=dist+i-1;k<=x;++k)
                dp[i][j][k]=t+1;
            for(short k=0;k<R[j].size();++k){
                short V=R[j][k];
                short L=v[V].sf-v[V].st+1;
                if(!xx[i-1][V])
                    continue;
                for(short p=i-2+L;p+dist<=x;++p){
                    if(!dp[i-1][V][p])
                        break;
                    short am=dp[i-1][V][p]+val;
                    if(am>t)
                        break;
                    if(am<dp[i][j][p+dist])
                        dp[i][j][p+dist]=am;
                    if(p+dist>maxx)
                        maxx=p+dist;
                    ss=1,xx[i][j]=1;
                }
            }
            for(int k=dist+i-1;k<=x;++k)
                if(dp[i][j][k]==t+1)
                    dp[i][j][k]=0;
        }
        if(!ss)
            break;
    }
    g<<maxx<<'\n';
    return 0;
}
