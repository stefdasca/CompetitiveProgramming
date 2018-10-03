#include<bits/stdc++.h>
using namespace std;
ifstream f("sant.in");
ofstream g("sant.out");
short s,n,c;
struct tipuri
{
    short l,p;
};
tipuri v[102];
short dp[102][1002];
short care[102][1002];
short vv[102];
int main()
{
    f>>s>>n>>c;
    for(short i=1;i<=c;++i)
        f>>v[i].l>>v[i].p;
    for(int i=1;i<=c;++i)
        dp[1][v[i].l]=v[i].p,care[1][v[i].l]=i;
    for(int i=1;i<n;++i)
        for(int p=1;p<=c;++p)
            for(int j=s-v[p].l;j>=1;--j)
            {
                if(!dp[i][j])
                    continue;
                if( (dp[i][j]+v[p].p<dp[i+1][j+v[p].l]) || ( !dp[i+1][j+v[p].l]) )
                {
                    dp[i+1][j+v[p].l]=dp[i][j]+v[p].p;
                    care[i+1][j+v[p].l]=p;
                }
            }
    g<<dp[n][s]<<'\n';
    if(dp[n][s])
    {
        int nn=n;
        while(nn)
        {
            vv[nn]=care[nn][s];
            s-=v[care[nn][s]].l;
            --nn;
        }
        sort(vv+1,vv+n+1);
        for(int i=1;i<=n;++i)
            g<<vv[i]<<" ";
    }
    return 0;
}
