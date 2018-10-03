#include<bits/stdc++.h>
using namespace std;
ifstream f("meeting.in");
ofstream g("meeting.out");
double x,y,t,prob;
int main()
{
    f>>x>>y>>t;
    y-=x;
    y*=60.0;
    prob=(y-2.0*t)*(t*2)/y+(2.0*t)*(t*1.5)/y;
    prob/=y;
    g<<fixed<<setprecision(7)<<prob;
}
