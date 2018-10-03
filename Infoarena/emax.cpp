#include<bits/stdc++.h>
using namespace std;
ifstream f("emax.in");
ofstream g("emax.out");
int n,k,i,j,x,v[100003],dp[100003],s;
double L[100003],l;
int main()
{
    f>>n;
    while(f>>x)
    {
        x=abs(x);
        if(x)
            v[++k]=x;
    }
    dp[0]=1;
    for(i=1;i<=k;++i)
    {
        s=0;
        for(j=i;j<=i+2;++j)
        {
            s+=v[j];
            l=log(s);
            if(L[j]<L[i-1]+l)
            {
                L[j]=L[i-1]+l;
                dp[j]=(dp[i-1]*s)%666013;
            }
        }
    }
    g<<dp[k];
    return 0;
}
