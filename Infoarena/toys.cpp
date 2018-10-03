#include<bits/stdc++.h>
using namespace std;
ifstream f("toys.in");
ofstream g("toys.out");
int n,d,m;
int s,x,y,z,v;
int max1=0;
long long MaxT=0;
int ar[2000002];
int vp,ap=1;
int main()
{
    f>>n>>d>>m;
    f>>s>>x>>y>>z>>v;
    vp=s;
    for(int i=1;i<=n;++i)
    {
        if(i>1){
            int vvp=vp;
            vp=(1LL*vvp*x+1LL*(i-1)*y)%(d-1)+1;
            ap=(1LL*z*vvp+1LL*v*(i-1))%2;
        }
        if(ap==1)
            ar[i]=d+vp;
        else
            ar[i]=d-vp;
    }
    int r=m%n;
    int val=(m/n)+(r>0);
    if(r==0)
        r=n;
    nth_element(ar+1,ar+r,ar+n+1);
    MaxT=ar[r]+1LL*val*2*d-d;
    g<<MaxT;
    return 0;
}
