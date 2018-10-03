/// #bettercoderthanshebeautiful
#include<bits/stdc++.h>
using namespace std;
ifstream f("subset.in");
ofstream g("subset.out");
int n;
long long nr,qq;
int main()
{
    f>>n>>nr;
    for(int i=1;qq<nr && i<=n;++i)
    {
        if(nr>qq+(1LL<<(n-i)))
            qq+=(1LL<<(n-i));
        else
            g<<i<<" ",++qq;
    }
    return 0;
}
