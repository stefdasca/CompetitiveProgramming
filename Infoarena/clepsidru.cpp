#include <fstream>
using namespace std;
int ls,lj,n,k,b,a0,an,s,p,i;
ifstream f("clepsidru.in");
ofstream g("clepsidru.out");
void p1(int x)
{
     if(ls<n)
     {
         ls+=x;
         lj+=x;
         if(ls>=n)
            ls=n,lj=n+b-1;
     }
}
void p2(int x)
{
     if(lj)
     {
         lj-=x;
         ls-=x;
         if(lj<=0)
            lj=0,ls=1-b;
     }
 }
int main()
{
    f>>n>>b;
    ls=1-b;
    g<<n+b-1<<"\n";
    f>>k;
    for(i=1;i<=k;i++)
    {
        f>>s>>p;
        if(p==1)
            p1(s);
         else
            p2(s);
    }
    if(ls<=0)
        a0=1-ls;
    if(lj>=n)
        an=lj-n+1;
    g<<a0<<" ";
    for(i=1;i<n;++i)
     if((i>=ls)&&(i<=lj))
        if(p==1)
            g<<"0\n1 ";
        else
            g<<"1\n0 ";
      else
        g<<"0\n0 ";
    g<<an<<"\n";
    return 0;
}
