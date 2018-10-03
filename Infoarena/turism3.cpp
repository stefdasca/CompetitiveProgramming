/// #bettercoderthanshebeautiful
#include<bits/stdc++.h>
using namespace std;
ifstream f("turism3.in");
ofstream g("turism3.out");
int n,k,m,nr,x;
int v[20002];
int sum;
int main()
{
    f>>n>>k>>m;
    for(int i=1;i<=m;++i)
    {
        v[i]+=v[i-1];
        f>>nr;
        for(int j=1;j<=nr;++j)
        {
            f>>x;
            if(v[i]<k)
            {
                v[i]++;
                sum+=x;
                v[i+x]--;
            }
        }
    }
    int q=m;
    while(v[q])
    {
        v[q+1]+=v[q];
        ++q;
    }
    q=q/n+(q%n>0);
    g<<sum<<" "<<q<<'\n';
    return 0;
}
