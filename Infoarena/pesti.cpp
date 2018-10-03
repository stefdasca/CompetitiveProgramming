#include<bits/stdc++.h>
using namespace std;
ifstream f("pesti.in");
ofstream g("pesti.out");
unsigned long n,x,a,b,c,z,u,p,zi=1;
long double r;
int main()
{  f>>n>>x;
   r=logl(n)/logl(2);
   if(r==floorl(r))
        z=r-1;
   else
        z=r;
   a=1;b=n;u=0;
   do{
        p=x;
        if((x-a)%2==0)
        {
            b=(a+b)/2;
            x=a+(x-a)/2;
        }
        else
        {
            c=(a+b)/2;
            x=c+(x-a+1)/2;
            a=c+1;
        }
        u++;
        if(x!=p)
            zi=u;
   }while(b-a>1);
   g<<z<<' '<<x<<' '<<zi<<'\n';
   return 0;
}
