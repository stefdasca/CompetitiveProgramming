#include<bits/stdc++.h>
using namespace std;
ifstream f("stele.in");
ofstream g("stele.out");
long long k,n;
int main()
{
    f>>k;
    for(long long i=1;i<=k;++i)
    {
        f>>n;
        if(n<5){
            g<<0<<'\n';
            continue;
        }
        long long etf=n;
        for(long long j=2;j*j<=n;++j)
            if(n%j==0)
            {
                etf=(etf/j)*(j-1);
                while(n%j==0)
                    n/=j;
            }
        if(n>1)
            etf=(etf/n)*(n-1);
        g<<etf/2-1<<'\n';
    }
    return 0;
}
