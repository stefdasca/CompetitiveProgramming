/// #bettercoderthanshebeautiful
#include<bits/stdc++.h>
using namespace std;
ifstream f("valuare.in");
ofstream g("valuare.out");
unsigned long long B,r,u,b,P,mB;
void calc(unsigned long long k)
{
    if(k==1)
    {
        r=1;
        u=1;
        b=mB;
        return;
    }
    if(k&1)
    {
        calc(k-1);
        r=(r*mB+k)%P;
        u=(u*mB+1)%P;
        b=b*mB%P;
    }
    else
    {
        calc(k>>1);
        r=(r*(b+1)%P+(k>>1)%P*u)%P;
        u=u*(b+1)%P;
        b=b*b%P;
    }
}
int main()
{
    f>>B>>P;
    mB=B%P;
    calc(B-1);
    g<<r;
    return 0;
}
