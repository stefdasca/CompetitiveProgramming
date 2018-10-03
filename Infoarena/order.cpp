#include<bits/stdc++.h>
using namespace std;
ifstream f("order.in");
ofstream g("order.out");
int n,aib[30002],pas=1,prc=1;
bool isb[30002];
void add(int nod, int nr)
{
    for(;nod<=n;nod+=(nod&(-nod)))
        aib[nod]+=nr;
}
int compute(int nod)
{
    int S=0;
    for(;nod;nod-=(nod&(-nod)))
        S+=aib[nod];
    return S;
}
int main()
{
    f>>n;
    for(int i=1;i<=n;++i)
        add(i,1),isb[i]=1;
    int zz=0;
    for(;pas<=n;++pas)
    {
        int pas1=pas;
        if(compute(n)-compute(prc)<pas)
            pas1-=compute(n)-compute(prc),prc=0;
        pas1%=compute(n);
        if(pas1==0)
            pas1=compute(n);
        int b=prc;
        int e=n;
        while(b<=e)
        {
            int m=(b+e)/2;
            if(compute(m)-compute(prc)==pas1 && isb[m]==1)
            {
                ++zz;
                g<<m<<" ";
                isb[m]=0;
                add(m,-1);
                prc=m;
                break;
            }
            else
                if(compute(m)-compute(prc)<pas1)
                    b=m+1;
                else
                    e=m-1;
        }
    }
    return 0;
}
