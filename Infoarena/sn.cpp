/// #bettercoderthanshebeautiful
#include<bits/stdc++.h>
using namespace std;
ifstream f("sn.in");
ofstream g("sn.out");
int l,n,mxs,mxa;
int a,b;
int main()
{
    f>>l>>n;
    for(int i=1;i<=n;++i)
    {
        f>>a>>b;
        if(mxs<=mxa)
            g<<0<<'\n',mxs=b;
        else
            g<<1<<'\n',mxa=b;
    }
    return 0;
}
