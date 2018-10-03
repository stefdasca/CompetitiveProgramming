#include<bits/stdc++.h>
using namespace std;
ifstream f("blaturi.in");
ofstream g("blaturi.out");
long long n,a,b,A,B,st,dr,nr_a,nr_b,sol,v[(1<<17)],i;
int main()
{
    f>>n;
    for(i=1;i<=n;v[i]+=v[i-1],++i)
        f>>v[i];
    f>>a>>b>>A>>B;
    sol=min(v[n]*a+(n-1)*b,v[n]*A+(n-1)*B);
    for(i=1;i<n;++i){
        if(i<n-i)
            sol=min(sol,v[i]*a+(v[n]-v[i])*A+(n-i-i-1)*B);
        if(i>n-i)
            sol=min(sol,v[i]*a+(v[n]-v[i])*A+(i+i-n-1)*b);
        if(i==n-i)
            sol=min(sol,v[i]*a+(v[n]-v[i])*A);
    }
    g<<sol<<'\n';
    return 0;
}
