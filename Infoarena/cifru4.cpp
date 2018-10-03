/// #bettercoderthanshebeautiful
#include<bits/stdc++.h>
#define mod 46337
using namespace std;
ifstream f("cifru4.in");
ofstream g("cifru4.out");
int n,p,k;
char strCh[128][128];
int sol,fact[128],l[128],pos[128][128];
int main()
{
    f>>n>>p>>k;
    for(int i=1;i<=n;++i)
    {
        f>>strCh[i]+1;
        l[i]=strlen(strCh[i]+1);
    }
    fact[0]=1;
    for(int i=1;i<=100;i++)
        fact[i]=(fact[i-1]*i)%mod;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=l[i];++j)
            if(strCh[i][j]=='0'+k)
            {
                int lp=p-j;
                if(lp>=0)
                {
                    memset(pos,0,sizeof(pos));
                    pos[0][0]=1;
                    for(int act=1;act<=n;act++)
                        if(act!=i)
                            for(int lung=lp-l[act];lung>=0;lung--)
                                for(int fol=0;fol<=n;fol++)
                                    pos[lung+l[act]][fol+1]+=pos[lung][fol];
                    for(int fol=0;fol<=n;fol++)
                        sol=(sol+((fact[fol]*pos[lp][fol])%mod)*(fact[n-1-fol])%mod)%mod;
                }
            }
    g<<sol;
    return 0;
}
