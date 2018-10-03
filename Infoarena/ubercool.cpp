#include<bits/stdc++.h>
using namespace std;
ifstream f("ubercool.in");
ofstream g("ubercool.out");
int t;
long long nr;
bitset<1000001>v;
int vp[100002],nrp=1;
long long ls[1000002],l;
void ciur()
{
    for(int i=4;i<=1000000;i+=2)
        v[i]=1;
    vp[1]=2;
    for(int i=3;i<=999999;i+=2)
        if(v[i]==0)
        {
            vp[++nrp]=i;
            for(int j=i+i;j<=1000000;j+=i)
                v[j]=1;
        }
}
int main()
{
    f>>t;
    ciur();
    for(int i=1;i<=nrp;++i)
    {
        double nr=(1e18+0.0)/(vp[i]+0.0);
        long long prd=vp[i];
        for(int j=1;nr-(vp[i]+0.0)>=0;nr/=(vp[i]+0.0)){
            prd*=vp[i];
            ls[++l]=prd;
        }
    }
    sort(ls+1,ls+l+1);
    for(;t;--t)
    {
        f>>nr;
        if(nr<2)
            g<<"NU"<<'\n';
        else
        {
            bool ok=0;
            int b=1;
            int e=l;
            while(b<=e)
            {
                int m=(b+e)/2;
                if(ls[m]==nr){
                    ok=1;
                    break;
                }
                else
                    if(ls[m]>nr)
                        e=m-1;
                    else
                        b=m+1;
            }
            if(ok==0){
                long long z=(int)sqrt(nr);
                long long p=z*z;
                if(p!=nr)
                    g<<"NU"<<'\n';
                else
                {
                    ok=1;
                    for(long long i=2;i*i<=z;++i)
                        if(z%i==0)
                        {
                            ok=0;
                            break;
                        }
                    if(ok==1)
                        g<<"DA"<<'\n';
                    else
                        g<<"NU"<<'\n';
                }
            }
            else
                g<<"DA"<<'\n';
        }
    }
    return 0;
}
