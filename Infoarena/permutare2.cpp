#include<bits/stdc++.h>
#define Nmax 100002
#define ll long long
using namespace std;
ifstream f("permutare2.in");
ofstream g("permutare2.out");
ll n,m,nr,cs,dif;
ll fr[Nmax];
ll sol[Nmax];
ll solb[Nmax];
ll mins=1e17;
void read()
{
    f>>m>>n;
    for(int i=1;i<=m;++i)
        f>>nr;
    fr[0]++;
    for(int i=2;i<=n;++i)
        f>>nr,fr[nr]++;
}
void st()
{
    cs=m/2+m%2;
    ll sum=0;
    ll hm=0;
    for(int i=cs;i<m;++i){
        sum+=hm;
        sum+=fr[i],hm+=fr[i];
     //   g<<sum<<" "<<hm<<'\n';
    }
    sol[0]=sum;
    for(int i=1;i<m;++i)
    {
        sum-=1LL*(m/2)*fr[cs];
        hm-=fr[cs];
        sum+=hm+fr[i-1];
        hm+=fr[i-1];
        sol[i]=sum;
        ++cs;
        if(cs>=m)
            cs=0;
      //  g<<i<<" "<<cs<<'\n';
    }
    --cs;
}
void dr()
{
   // g<<cs<<'\n';
    ll sum=0;
    ll hm=0;
    for(int i=cs;i>=0;--i){
        sum+=hm;
        sum+=fr[i],hm+=fr[i];
    }
    solb[m-1]=sum;
    for(int i=m-2;i>=0;--i)
    {
        sum-=1LL*(m/2-1+m%2)*fr[cs];
        hm-=fr[cs];
        sum+=hm+fr[i+1];
        hm+=fr[i+1];
        solb[i]=sum;
        --cs;
        if(cs<0)
            cs=m-1;
    }
}
int main()
{
    read();
    st();
    dr();
    /*
    for(int i=0;i<n;++i)
        g<<sol[i]<<" ";
    g<<'\n';
    for(int i=0;i<n;++i)
        g<<solb[i]<<" ";
    g<<'\n';
    */
    for(int i=0;i<m;++i)
        mins=min(mins,sol[i]+solb[i]);
    g<<mins;
    return 0;
}
