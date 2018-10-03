#include<bits/stdc++.h>
#define Nmax 500005
using namespace std;
ifstream f("reguli.in");
ofstream g("reguli.out");
long long pi[Nmax],b[Nmax],N,x[Nmax],q;
int main()
{
    f>>N;
    for(int i=1;i<=N;i++)
        f>>x[i];
    for(int i=2;i<=N;i++)
        b[i-1]=x[i]-x[i-1];
    N--;
    for(int i=2;i<=N;i++)
    {
        while(q && b[q+1]!=b[i])
            q=pi[q];
        if(b[q+1]==b[i])
            q++;
        pi[i]=q;
    }
    g<<N-pi[N]<<'\n';
    for(int i=1;i<=N-pi[N];i++)
        g<<b[i]<<'\n';
    return 0;
}
