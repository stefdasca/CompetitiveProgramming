/// #bettercoderthanshebeautiful
#include<bits/stdc++.h>
using namespace std;
ifstream f("prefix.in");
ofstream g("prefix.out");
int t,L;
int prefix[1000002];
char c[1000002];
int main()
{
    f>>t;
    for(;t;--t)
    {
        int poz=0;
        f>>(c+1);
        int L=strlen(c+1);
        int k=0;
        memset(prefix,0,sizeof(prefix));
        for(int i=2;i<=L;++i)
        {
            while(k && c[i]!=c[k+1])
                k=prefix[k];
            if(c[i]==c[k+1])
                ++k;
            prefix[i]=k;
        }
        for(int i=1;i<=L;++i)
            if(prefix[i] && i%(i-prefix[i])==0)
                poz=i;
        g<<poz<<'\n';
    }
    return 0;
}
