#include<bits/stdc++.h>
using namespace std;
ifstream f("tictac.in");
ofstream g("tictac.out");
int t;
double ang1,ang2;
const double r1=30.000000,r2=360.000000;
int main()
{
    f>>t;
    for(;t;--t)
    {
        f>>ang1>>ang2;
        while(ang1>=r1)
            ang1-=r1;
        double d1=ang1/r1;
        double d2=ang2/r2;
        if(max(d1-d2,d2-d1)<=1e-3)
            g<<1<<'\n';
        else
            g<<0<<'\n';
    }
    return 0;
}
