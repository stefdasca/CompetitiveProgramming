#include<bits/stdc++.h>
using namespace std;
ifstream f("noname3.in");
ofstream g("noname3.out");
long long n,s;
int v[1000002];
int vad[1000002];
int main()
{
    f>>n>>s;
    if(s<n*(n+1)/2)
        g<<-1;
    else
    {
        for(int i=1;i<=n;++i)
            v[i]=i,s-=i;
        vad[1]+=s/n;
        s%=n;
        vad[n-s+1]++;
        for(int i=1;i<=n;++i)
            vad[i]+=vad[i-1];
        for(int i=1;i<=n;++i)
            g<<v[i]+vad[i]<<" ";
    }
    return 0;
}
