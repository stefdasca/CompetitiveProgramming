#include<bits/stdc++.h>
#define base 100000000
using namespace std;
ifstream f("mult.in");
ofstream g("mult.out");
int n,k;
int c[2502];
int dp[3][502][755],len[3][502];
int one[3];
int modd[5102];
inline void add(int a[], int b[], int &x, int y)
{
    x=max(x,y);
    int t=0;
    for(int i=1;i<=x;++i)
    {
        a[i]=a[i]+b[i]+t;
        t=a[i]/base;
        a[i]%=base;
    }
    if(t)
        a[++x]=t;
}
main()
{
    f>>n>>k;
    for(int j=0;j<=5000;++j)
        modd[j]=j%k;
    for(int i=1;i<=n;++i)
        f>>c[i],c[i]=modd[c[i]];
    one[1]=1;
    for(int i=1;i<=n;++i)
    {
        for(int j=0;j<k;++j)
        {
            if(!len[1][j])
                continue;
            add(dp[2][j],dp[1][j],len[2][j],len[1][j]);
            int nxt=modd[(j*10+c[i])];
            add(dp[2][nxt],dp[1][j],len[2][nxt],len[1][j]);
        }
        add(dp[2][c[i]],one,len[2][c[i]],1);
        for(int j=0;j<k;++j)
        {
            int y=len[2][j];
            for(int p=1;p<=y;++p)
                dp[1][j][p]=dp[2][j][p],dp[2][j][p]=0;
            len[1][j]=len[2][j];
            len[2][j]=0;
        }
    }
    for(int i=len[1][0];i;--i)
    {
        int j=1;
        if(i!=len[1][0])
            while(j<base)
            {
                if(j>dp[1][0][i])
                    g<<0;
                j=j*10;
            }
        g<<dp[1][0][i];
    }
    return 0;
}
