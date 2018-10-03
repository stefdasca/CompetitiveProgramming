#include<bits/stdc++.h>
#define mod 29989
using namespace std;
ifstream f("frunze.in");
ofstream g("frunze.out");
int r,n,p,i,j,k,a[51][51];
inline int s(int n,int m)
{   if(m==1 || m==n)
        return 1;
    if(!a[n][m])
        a[n][m]=(s(n-1,m-1)+m*s(n-1,m))%mod;
    return a[n][m];
}
int main()
{   f>>n>>p;
    r=s(n-2,n-p);
    for(i=p+1;i<=n;++i)
        r=(r*i)%mod;
    g<<r;
    return 0;
}
