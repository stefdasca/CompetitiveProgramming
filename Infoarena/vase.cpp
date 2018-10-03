#include<bits/stdc++.h>
using namespace std;
ifstream f("vase.in");
ofstream g("vase.out");
int n,col;
long long s,ss;
struct OrangeParasite
{
    int nr;
    char o;
};
OrangeParasite v[100002];
int main()
{
    f>>n;
    for(int i=1;i<=n;++i)
    {
        f>>v[i].nr>>v[i].o;
        s+=v[i].nr;
        ss+=v[i].nr;
    }
    f>>col;
    g<<s/2<<'\n';
    s=0;
    for(int i=1;i<col;++i)
        s+=v[i].nr;
    long long xa=0,xb=0;
    if(v[col].o=='D')
        xb=s+v[col].nr,xa=s;
    else
        xa=0,xb=v[col].nr;
    for(int i=col+1;i<=n;++i)
        if(v[i].o=='S')
            xa+=v[i].nr,xb+=v[i].nr;
    if(xa<ss/2){
        g<<ss/2-xa<<" "<<"S"<<'\n';
        if(xb==ss/2)
            g<<0<<" "<<"S"<<'\n';
        else
            if(xb<ss/2)
                g<<ss/2-xb<<" "<<"S"<<'\n';
            else
                g<<xb-ss/2<<" "<<"D"<<'\n';
    }
    else
        g<<xb-ss/2<<" "<<"D"<<'\n'<<xa-ss/2<<" "<<"D"<<'\n';
    return 0;
}
