/// #bettercoderthanshebeautiful
#include<bits/stdc++.h>
using namespace std;
ifstream f("coins.in");
ofstream g("coins.out");
int n;
bool win[(1<<22)];
int v;
int s;
int am(int nr)
{
    int sol=0;
    for(int i=21;i>=0;--i)
        if(nr&(1<<i))
            ++sol;
    return sol;
}
int main()
{
    f>>n;
    win[1]=1;
    for(int i=3;i<=(1<<22);i=i*2+1)
        win[i]=1;
    for(int i=3;i<(1<<22);++i)
    {
        if(win[i])
            continue;
        win[i]=1;
        for(int j=21;j>0;--j)
            if(i&(1<<j))
                for(int k=j-1;k>=0;--k)
                    if(!(i&(1<<k))){
                        win[i]=win[i]&win[i-(1<<j)+(1<<k)];
                        break;
                    }
        win[i]^=1;
    }
    int sol=0;
    for(int i=1;i<=n;++i)
    {
        int q=0;
        int nr=0;
        for(int j=0;j<=21;++j)
        {
            f>>v;
            if(v==1)
                q+=(1<<j),++nr;
        }
        if(win[q])
            sol+=nr;
    }
    g<<sol;
    return 0;
}
