#include<bits/stdc++.h>
using namespace std;
ifstream f("zigzag2.in");
ofstream g("zigzag2.out");
int n,k;
int v[1000002];
int Mistakes[1000002],sz;
inline bool good(int nr)
{
    return ( (v[nr-1]>v[nr] && v[nr]<v[nr+1]) || (v[nr-1]<v[nr] && v[nr]>v[nr+1]) );
}
int main()
{
    f>>n>>k;
    for(int i=1;i<=n;++i)
        f>>v[i];
    for(int i=2;i<n;++i)
        if(!good(i))
            Mistakes[++sz]=i;
    int stp=1;
    int M=0;
    long long sol=0;
    for(int i=2;i<=n;++i)
    {
        if(i-stp+1>=3)
            sol=sol+(i-stp-1);
        if(Mistakes[M+1]==i)
        {
            ++M;
            if(M>k)
                stp=Mistakes[M-k];
        }
    }
    g<<sol;
    return 0;
}

