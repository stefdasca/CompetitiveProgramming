#include<bits/stdc++.h>
using namespace std;
ifstream f("chiftea.in");
ofstream g("chiftea.out");
unsigned int t,n;
int main()
{
    f>>t;
    for(int i=1;i<=t;++i)
    {
        f>>n;
        if(n==0)
            g<<0<<'\n';
        else
        {
            unsigned int r=(int)sqrt(n);
            unsigned int z=n/r;
            unsigned int sol=2*(z+r);
            if(n%r)
                sol+=2;
            g<<sol<<'\n';
        }
    }
    return 0;
}
