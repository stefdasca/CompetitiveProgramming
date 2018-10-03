/// #bettercoderthanshebeautiful
#include<bits/stdc++.h>
using namespace std;
ifstream f("examen.in");
ofstream g("examen.out");
int n,a,b;
long long xm[100002];
long long xa[100002],Sx,Sp;
void solve(int a, int b)
{
    for(int i=2;i<=n;++i,a+=2,b+=2)
    {
        int ta=a%n;
        if(ta==0)
            ta=n;
        int ts=(a+1)%n;
        if(ts==0)
            ts=n;
        int tb=b%n;
        if(tb==0)
            tb=n;
        xa[tb]=xm[ts]-xa[ta];
    }
}
int main()
{
    f>>n;
    if(n%4==0){
        g<<-1;
        return 0;
    }
    for(int i=1;i<=n;++i)
        f>>xm[i],Sx+=xm[i];
    for(int i=1;i<=n;i+=4)
        Sp+=xm[i]+xm[i+1];
    if(n%4==1)
    {
        xa[1]=Sp-Sx/2;
        a=1;
        b=3;
        solve(1,3);
    }
    if(n%4==3)
    {
        xa[n]=Sp-Sx/2;
        a=n;
        b=n+2;
        solve(n,n+2);
    }
    if(n%4==2)
    {
        Sx=0;
        for(int i=2;i<=n;i+=2)
            Sx+=xm[i];
        Sx/=2;
        for(int i=2;i<=n-4;i+=4)
            Sx-=xm[i];
        xa[n-1]=Sx;
        Sx=0;
        for(int i=1;i<=n;i+=2)
            Sx+=xm[i];
        Sx/=2;
        for(int i=3;i<=n-3;i+=4)
            Sx-=xm[i];
        xa[n]=Sx;
        for(int i=n-1;i>=2;--i)
            xa[i-1]=xm[i]-xa[i+1];
    }
    for(int i=1;i<=n;++i)
        g<<xa[i]<<" ";
    return 0;
}
