/// #bettercoderthanshebeautiful
#include<bits/stdc++.h>
using namespace std;
ifstream f("magicsequence.in");
ofstream g("magicsequence.out");
int n,fs,ls,t;
int main()
{
    f>>t;
    for(;t;--t)
    {
        f>>n;
        fs=ls=0;
        for(int i=1;i<=n;++i)
        {
            int nr;
            f>>nr;
            if(fs==0)
                fs=nr;
            ls=nr;
        }
        if(fs>ls)
            g<<"NO"<<'\n';
        else
            g<<"YES"<<'\n';
    }
    return 0;
}
