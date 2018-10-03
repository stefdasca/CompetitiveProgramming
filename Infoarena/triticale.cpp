#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
ifstream f("triticale.in");
ofstream g("triticale.out");
int n;
pair<pair<int,int>,int>v[3002];
int dp[3002],care[3002];
int r[5];
deque<int>sol;
int main()
{
    f>>n;
    for(int i=1;i<=n;++i)
    {
        int val=3*(i-1)+1;
        int a,b,c;
        f>>r[1]>>r[2]>>r[3];
        sort(r+1,r+4);
        a=r[1];b=r[2];c=r[3];
        v[val]={{a,b},c};
        v[val+1]={{a,c},b};
        v[val+2]={{b,c},a};
    }
    sort(v+1,v+3*n+1);
    for(int i=1;i<=3*n;++i)
    {
        dp[i]=v[i].se;
        for(int j=i-1;j>=1;--j)
            if(v[j].fi.fi<v[i].fi.fi && v[j].fi.se<v[i].fi.se)
                if(dp[j]+v[i].se>dp[i])
                {
                    dp[i]=dp[j]+v[i].se;
                    care[i]=j;
                }
    }
    int solmax=0,who=0;
    for(int i=1;i<=3*n;++i)
        if(dp[i]>solmax)
            solmax=dp[i],who=i;
    g<<solmax<<'\n';
    while(who!=0)
    {
        sol.push_front(who);
        who=care[who];
    }
    for(int i=0;i<sol.size();++i)
    {
        int R=sol[i];
        g<<v[R].fi.fi<<" "<<v[R].fi.se<<" "<<v[R].se<<'\n';
    }
    return 0;
}
