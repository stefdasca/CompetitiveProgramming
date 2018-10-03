/// Flowers are great at the beginning
/// but in the end, all of them will fade
#define eps 1e-10
#include<bits/stdc++.h>
using namespace std;
ifstream f("flori2.in");
ofstream g("flori2.out");
int t,n,z;
double pd[1002];
struct points
{
    int L,C;
};
points v[1002];
int main()
{
    f>>t;
    for(;t;--t)
    {
        f>>n;
        for(int i=1;i<=n;++i)
            f>>v[i].L>>v[i].C;
        if(n<=2){
            g<<n<<'\n';
            continue;
        }
        else
        {
            int max1=0;
            for(z=1;z<=n;++z)
            {
                for(int i=1;i<=n;++i)
                    pd[i]=(v[z].C-v[i].C+0.0)/(v[z].L-v[i].L+0.0);
                sort(pd+1,pd+n+1);
                int r=1;
                for(int i=2;i<=n;++i){
                    if(pd[i]-pd[i-1]<=eps)
                        ++r;
                    else
                        r=1;
                    max1=max(max1,r);
                }
            }
            g<<min(max1+1,n)<<'\n';
        }
    }
    return 0;
}
