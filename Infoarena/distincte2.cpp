/// #bettercoderthanshebeautiful
#include<bits/stdc++.h>
using namespace std;
ifstream f("distincte2.in");
ofstream g("distincte2.out");
int n,nr,q;
bool wi[1000002];
int sp[1000002];
int main()
{
    f>>n>>q;
    for(int i=1;i<=n;++i)
    {
        f>>nr;
        wi[nr]=1;
    }
    for(int i=1;i<=1000000;++i)
        sp[i]=sp[i-1]+wi[i];
    for(int i=1;i<=q;++i)
    {
        int a,b;
        f>>a>>b;
        g<<sp[b]-sp[a-1]<<'\n';
    }
    return 0;
}
