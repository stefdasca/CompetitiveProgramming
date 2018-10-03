#include<bits/stdc++.h>
using namespace std;
ifstream f("tort.in");
ofstream g("tort.out");
long long a,b,c,s,t,x,p,put=1;
int main(void)
{
    f>>a>>b;
    ++a;
    ++b;
    c=a+b;
    if(a%2==0)
        a/=2;
    else
        if(b%2==0)
            b/=2;
        else
            c/=2;
    p=a*b;
    while(p)
    {
        long long fact=p%10;
        p/=10;
        s=t+c*fact;
        x=x+(s%10)*put;
        t=s/10;
        put*=10;
    }
    if(t>0)
        g<<t;
    g<<x;
    return 0;
}
