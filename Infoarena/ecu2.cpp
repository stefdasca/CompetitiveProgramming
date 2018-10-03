#include<bits/stdc++.h>
using namespace std;
ifstream f("ecu2.in");
ofstream g("ecu2.out");
int n;
int a,b,c;
int main()
{
    f>>n;
    for(int i=1;i<=n;++i)
    {
        f>>a>>b>>c;
        if(a>0)
        {
            int d=b*b-4*a*c;
            if(d>0)
                g<<2<<'\n';
            else
                if(d==0)
                    g<<1<<'\n';
                else
                    g<<0<<'\n';
        }
        else
            if(b==0 && c>0)
                g<<0<<'\n';
            else
                if(b>0)
                    g<<1<<'\n';
                else
                    g<<"INF"<<'\n';
    }
    return 0;
}
