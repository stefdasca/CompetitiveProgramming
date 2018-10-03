#include<bits/stdc++.h>
using namespace std;
ifstream f("qtri.in");
ofstream g("qtri.out");
long long x1,x2,x3,x4,yy,y2,y3,y4;
int q;
bool arie()
{
    long long a1=x1*(y2-y3)+x2*(y3-yy)+x3*(yy-y2); // ABC
    long long a2=x1*(y2-y4)+x2*(y4-yy)+x4*(yy-y2); // ABD
    long long a3=x1*(y3-y4)+x3*(y4-yy)+x4*(yy-y3); // ACD
    long long a4=x2*(y3-y4)+x3*(y4-y2)+x4*(y2-y3); // BCD
    a1=max(a1,-a1);
    a2=max(a2,-a2);
    a3=max(a3,-a3);
    a4=max(a4,-a4);
    if(a1==a2+a3+a4)
        return 1;
    return 0;
}
int main()
{
    f>>q;
    for(;q;--q)
    {
        f>>x1>>yy>>x2>>y2>>x3>>y3>>x4>>y4;
        if(arie())
            g<<"DA"<<'\n';
        else
            g<<"NU"<<'\n';
    }
    return 0;
}
