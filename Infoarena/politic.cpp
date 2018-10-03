#include<bits/stdc++.h>
using namespace std;
ifstream f("politic.in");
ofstream g("politic.out");
long long n,sol,nr,v[100002],nr1,nr2;
int main()
{
    f>>n;
    f>>nr1;
    nr=1;
    v[1]=1;
    for(int i=2;i<=n;++i)
    {
        f>>nr2;
        if(nr2-nr1==1)
            ++v[nr];
        else
        {
            ++nr;
            v[nr]=1;
        }
        nr1=nr2;
    }
    g<<nr<<'\n';
    int b=0;
    int e=0;
    int s=0;
    while(e<=nr)
    {
        while(s<=n/2 && e<=nr)
            s+=v[++e];
        if(e<=nr)
            sol+=(nr-e+1);
        s-=v[++b];
    }
    g<<sol;
    return 0;
}
