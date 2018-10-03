#include<bits/stdc++.h>
using namespace std;
ifstream f("cardinal.in");
ofstream g("cardinal.out");
int q,n;
long long di,dp;
char c[100002];
int main()
{
    f>>q;
    for(;q;--q)
    {
        f>>n;
        if(n%4==1 || n%4==2)
        {
            g<<"IMPOSIBIL"<<'\n';
            continue;
        }
        dp=1LL*(n/2)*(n/2+1);
        if((dp/2)%2==1)
        {
            g<<"IMPOSIBIL"<<'\n';
            continue;
        }
        di=1LL*n*(n+1)/2-dp;
        di/=2;
        dp/=2;
        for(int i=n;i>=1;--i)
            if(i&1)
               if(di>=i)
                  c[i]='U',di-=i;
               else
                  c[i]='D';
            else
               if(dp>=i)
                  c[i]='L',dp-=i;
               else
                  c[i]='R';
        for(int i=1;i<=n;++i)
            g<<c[i];
        g<<'\n';
    }
    return 0;
}
