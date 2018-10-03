#include<bits/stdc++.h>
using namespace std;
ifstream f("numar2.in");
ofstream g("numar2.out");
int n,m;
int v1[102],cd[102];
int prv,min1,poz1;
int main()
{
    f>>n>>m;
    for(int i=1;i<=n;++i)
        f>>v1[i],cd[i]=v1[i];
    while(m)
    {
        min1=cd[1];
        poz1=1;
        for(int i=2;i<=n;++i)
            if(cd[i]<min1)
                min1=cd[i],poz1=i;
        if(min1!=prv){
            --m;
            prv=min1;
        }
        cd[poz1]+=v1[poz1];
    }
    g<<min1;
}
