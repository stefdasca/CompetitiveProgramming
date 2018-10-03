#include<bits/stdc++.h>
#define ross 9999991
using namespace std;
ifstream f("dirichlet.in");
ofstream g("dirichlet.out");
int n;
long long rs=1,aux=1;
int main()
{
    f>>n;
    for(long long i=n+2;i<=n+n;++i)
        rs=(rs*i)%ross;
    for(long long i=1;i<=n;++i)
        aux=(aux*i)%ross;
    long long b=ross-2;
    long long ans=1;
    long long a=aux;
    while(b){
        if(b&1)
            ans=(ans*a)%ross;
        a=(a*a)%ross,b/=2;
    }
    g<<(rs*ans)%ross;
    return 0;
}
