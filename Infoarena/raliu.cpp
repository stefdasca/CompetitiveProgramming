#include<bits/stdc++.h>
using namespace std;
ifstream f("raliu.in");
ofstream g("raliu.out");
int t,n;
long long v[1000002],y;
int main()
{
    f>>t;
    for(;t;--t)
    {
        f>>n;
        for(int i=1;i<=n;++i)
           f>>v[i];
        for(int i=1;i<=n;++i)
            f>>y,v[i]-=y;
        int st=1,sf=1;
        long long sum=0;
        bool ok=0;
        while(st<=n)
        {
            if(sf!=n)
                sum+=v[sf%n];
            else
                sum+=v[sf];
            if(sum<0)
            {
                st=sf+1;
                ++sf;
                sum=0;
            }
            else
            {
                ++sf;
                if(sf-st==n){
                    g<<"DA"<<'\n';
                    g<<st<<'\n';
                    ok=1;
                    break;
                }
            }
        }
        if(ok==0)
            g<<"NU"<<'\n';
    }
    return 0;
}
