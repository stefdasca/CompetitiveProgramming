#include<bits/stdc++.h>
using namespace std;
ifstream f("s2c.in");
ofstream g("s2c.out");
int t,n,v[2002],dp[3][2002],aib[2002],vs[2002];
void add(int nod, int val)
{
    if(nod==0)
    {
        aib[nod]=min(aib[nod],val);
        return;
    }
    for(;nod<=n;nod+=(nod&(-nod)))
        aib[nod]=min(aib[nod],val);
}
int compute(int nod)
{
    int s=aib[0];
    for(;nod;nod-=(nod&(-nod)))
        s=min(s,aib[nod]);
    return s;
}
bool cmp(int a, int b)
{
    if(v[a]==v[b])
        return a<b;
    return v[a]<v[b];
}
int main()
{
    f>>t;
    for(;t;--t)
    {
        f>>n;
        for(int i=1;i<=n;++i)
            f>>v[i];
        int vv=0,c=0;
        while(vv<n)
        {
            ++c;
            int mini=300000;
            for(int i=1;i<=n;++i)
                if(v[i]>=c)
                    mini=min(mini,v[i]);
            for(int i=1;i<=n;++i)
                if(v[i]==mini)
                    v[i]=c,++vv;
        }
        int sol=1;
        for(int i=2;i<=n;++i)
        {
            for(int j=0;j<=n;++j)
                aib[j]=100000;
            bool good=0;
            for(int j=i-1;j<=n;++j)
            {
                int ss=compute(v[j]-1);
                if(ss!=100000)
                    dp[1][j]=ss,good=1;
                if(dp[0][j]!=0 || i==2)
                    add(dp[0][j],v[j]);
                dp[0][j]=dp[1][j],dp[1][j]=0;
            }
            if(!good)
                break;
            else
                ++sol;
        }
        g<<sol<<'\n';
    }
    return 0;
}
