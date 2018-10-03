#include<bits/stdc++.h>
#define LL long long
#define mx 10003
using namespace std;
ifstream f("reactor.in");
ofstream g("reactor.out");
LL n,q;
LL dp[10005][102];
int main()
{
    f>>n;
    for(int i=1;i<=n;++i)
        f>>dp[0][i];
    for(int i=0;i<mx;++i)
        for(int j=1;j<=n;++j)
        {
            int pf=(j+dp[i][j])%n;
            if(pf==0)
                pf=n;
            dp[i+1][pf]+=dp[i][j];
        }
    f>>q;
    for(int i=1;i<=q;++i)
    {
        int s,t;
        f>>s>>t;
        if(t<=mx)
            g<<dp[t][s]<<'\n';
        else
        {
            int rez=0;
            for(int j=1;j<=n;++j)
            {
                long long pos=1LL*j+1LL*(t-mx)*dp[mx][j];
                pos%=n;
                if(pos==0)
                    pos=n;
                if(pos==s)
                    rez+=dp[mx][j];
            }
            g<<rez<<'\n';
        }
    }
    return 0;
}
