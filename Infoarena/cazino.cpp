// Blackjack for roses
#include<bits/stdc++.h>
using namespace std;
ifstream f("cazino.in");
ofstream g("cazino.out");
int t,x,y;
double tt,p;
int main()
{
    f>>t;
    for(;t;--t)
    {
        f>>x>>y;
        if(x%2==0 && y%2==1)
            y++;
        int tt=x*0.5;
        int p=y*0.5;
        g<<fixed<<setprecision(5)<<(double)tt/p<<'\n';
    }
    return 0;
}
