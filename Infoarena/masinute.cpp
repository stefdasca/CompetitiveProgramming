#include<bits/stdc++.h>
using namespace std;
ifstream f("masinute.in");
ofstream g("masinute.out");
int q,v[2000002],a,b;
int main()
{
    f>>q;
    for(int i=1;i<=q;++i)
    {
        f>>a>>b;
        v[i]=max(a,b);
    }
    sort(v+1,v+q+1);
    int s=0,d=0;
    for(int i=1;i<=q;++i)
    {
        s=(s+v[i])%666013;
        if(v[i]==v[i-1])
            ++d;
    }
    g<<s<<" "<<d;
    return 0;
}
