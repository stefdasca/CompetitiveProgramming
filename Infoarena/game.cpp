#include<bits/stdc++.h>
using namespace std;
ifstream f("game.in");
ofstream g("game.out");
int n,nr;
int main()
{
    for(int i=1;i<=10;++i)
    {
        f>>n;
        int Sxor=0;
        for(;n;--n)
            f>>nr,Sxor^=(nr&3);
        if(Sxor)
            g<<1<<'\n';
        else
            g<<0<<'\n';
    }
    return 0;
}
