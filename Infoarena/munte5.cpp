#include<bits/stdc++.h>
#define Nmax 64002
#define mod 12343
using namespace std;
ifstream f("munte5.in");
ofstream g("munte5.out");
int fr[Nmax+2],Ans=1,dif,mx,cat,mmm,ok=1;
int n;
int main()
{
    f>>n;
    for(int i=1;i<=n;++i)
    {
        int nr;
        f>>nr;
        if(!fr[nr])
            ++dif;
        if(nr>mx)
        {
            mx=nr;
            cat=0;
        }
        if(nr==mx)
            ++cat;
        ++fr[nr];
        if(fr[nr]>1)
            mmm=1;
        if(fr[nr]>2)
            ok=0;
    }
    if(cat>1 || !ok)
    {
        g<<0;
        return 0;
    }
    for(int i=1;i<=64000;++i)
        if(i!=mx && fr[i]==2)
            --dif;
    for(int i=1;i<dif;++i)
        Ans=(Ans*2)%mod;
    g<<Ans-(dif==n)*2<<'\n';
    return 0;
}
