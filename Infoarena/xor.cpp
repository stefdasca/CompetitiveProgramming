#include<bits/stdc++.h>
using namespace std;
ifstream f("xor.in");
ofstream g("xor.out");
int q,p;
long long sum;
int l1, l2, c1, c2;
inline int cntBit(int mx, int p)
{
    int p2=(1<<(p+1));
    int complete_cycles=mx/p2;
    int sol=complete_cycles*(1<<p);
    int rem=mx%p2;
    if(rem>=(1<<p))
        sol+=(rem-(1<<p)+1);
    return sol;
}
inline int fct(int a, int b, int p)
{
    return cntBit(b, p) - cntBit(a-1, p);
}
int main()
{
    f>>q>>p;
    for(int i=1;i<=q;++i)
    {
        f>>l1>>c1>>l2>>c2;
        sum=0;
        for(int j=26;j>=0;--j)
        {
            int nra=fct(l1,l2,j);
            int nrb=(l2-l1+1)-nra;
            int nrc=fct(c1,c2,j);
            int nrd=(c2-c1+1)-nrc;
            long long pp=1LL*nra*nrd+1LL*nrb*nrc;
            pp%=p;
            sum=(sum+(pp*(1<<j)))%p;
        }
        g<<sum<<'\n';
    }
    return 0;
}
