#include<bits/stdc++.h>
using namespace std;
ifstream f("minusk.in");
ofstream g("minusk.out");
int n,k;
int p[1000002],m[1000002];
int main()
{
    f>>n>>k;
    p[1]=1;
    if(k>1)
        m[1]=1;
    for(int i=2;i<=n;++i){
        p[i]=(p[i-1]+m[i-1]);
        m[i]=(p[i-1]+m[i-1]);
        if(i==k)
            m[i]-=m[i-k+1];
        else
            if(i>k)
                m[i]-=p[i-k];
        if(m[i]<0)
            m[i]=m[i]-(m[i]/2011-1)*2011;
        p[i]%=2011;
        m[i]%=2011;
    }
    g<<(p[n]+m[n])%2011;
    return 0;
}
