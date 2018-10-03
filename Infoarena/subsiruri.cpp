#include<bits/stdc++.h>
using namespace std;
ifstream f("subsiruri.in");
ofstream g("subsiruri.out");
int n,v[1002];
int sclm[1002];
int sol[1002];
int main()
{
    f>>n;
    for(int i=1;i<=n;++i)
        f>>v[i];
    for(int i=1;i<=n;++i)
        sol[i]=1,sclm[i]=1;
    for(int i=2;i<=n;++i)
        for(int j=1;j<i;++j)
            if(v[j]<v[i])
                if(sclm[j]+1>sclm[i])
                {
                    sclm[i]=sclm[j]+1;
                    sol[i]=sol[j]%9901;
                }
                else
                    if(sclm[j]+1==sclm[i])
                        sol[i]=(sol[i]+sol[j])%9901;
    int lmax=0;
    int s=0;
    for(int i=1;i<=n;++i)
        if(sclm[i]>lmax)
            lmax=sclm[i],s=sol[i];
        else
            if(sclm[i]==lmax)
                s=(s+sol[i])%9901;
    g<<lmax<<'\n'<<s;
    return 0;
}
