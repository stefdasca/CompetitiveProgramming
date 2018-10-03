#include<bits/stdc++.h>
using namespace std;
ifstream f("lacate.in");
ofstream g("lacate.out");
int n,v[502];
int main()
{
    f>>n;
    g<<(n-1)*n/2<<" "<<n-1<<'\n';
    for(int i=1;i<n;++i)
        g<<i<<" ",v[i]=i;
    g<<'\n';
    int coef=n-2;
    for(int i=2;i<=n;++i)
    {
        for(int j=1;j<n;g<<v[j]<<" ",++j)
            if(j==i-1)
                continue;
            else
                if(j<i-1)
                    ++v[j];
                else
                    v[j]+=coef;
        g<<'\n';
        --coef;
    }
    return 0;
}
