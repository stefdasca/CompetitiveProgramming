/// #bettercoderthanshebeautiful
#include<bits/stdc++.h>
using namespace std;
ifstream f("zlego.in");
ofstream g("zlego.out");
int t;
int n,va[250002],P[250002];
long long sol[250002];
int main()
{
    f>>t;
    for(;t;--t)
    {
        f>>n;
        for(int i=1;i<=n;++i)
            f>>va[i];
        for(int i=1;i<=n;++i)
            f>>sol[i];
        int q=0;
        for(int i=2;i<=n;++i)
        {
            while(q>0 && va[q+1]!=va[i])
                q=P[q];
            if(va[q+1]==va[i])
                q++;
            P[i]=q;
        }
        for(int i=n;i>=1;--i)
            sol[P[i]]+=sol[i];
        for(int i=1;i<=n;++i)
            g<<sol[i]<<'\n';
    }
    return 0;
}
