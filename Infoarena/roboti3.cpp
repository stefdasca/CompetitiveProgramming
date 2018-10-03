#include <fstream>
using namespace std;
ifstream f("roboti3.in");
ofstream g("roboti3.out");
int tip,n,i,sol,nr,Q,x,y,P,dp[1<<10];
void solve()
{
    int ok=0;
    for(i=1;i<=1000;++i)
        if(dp[i])
        {
            if(!ok)
            {
                while(dp[i]--)
                    g<<i<<' ';
                ok=1;
            }
            else
                if(dp[i]>1)
                {
                    while(dp[i]>1)
                        g<<i<<' ',dp[i]--;
                    ok=1;
                }
                else
                    if(ok==1)
                    {
                        g<<i<<' ';
                        dp[i]=0;
                        ok=2;
                    }
                    else
                        ok=1;
        }
    for(i=1000;i>0;--i)
        if(dp[i])
            g<<i<<' ';
}
int main()
{
    f>>tip>>n;
    for(i=nr=1;i<=n;++i)
    {
        f>>x;
        dp[x]++;
        if(i>1)
        {
            if(x>y) nr++;
            else
            {
                if(!P) P=nr;
                nr=1;
            }
            sol=max(sol,nr);
        }
        else Q=x;
        y=x;
    }
    if(y<Q) sol=max(sol,nr+P);
    if(tip==1)
        g<<sol;
    else
        solve();
    return 0;
}
