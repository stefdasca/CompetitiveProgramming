#include<bits/stdc++.h>
#define mod 1000003
using namespace std;
ifstream f("grigo.in");
ofstream g("grigo.out");
long long n,sol[100002],m,z;
bool nek[100002];
int main()
{
    f>>n>>m;
    for(int i=1;i<=m;++i)
        f>>z,nek[z]=1;
    sol[1]=1;
    for(long long i=2;i<=n;++i)
        if(nek[i])
            sol[i]=sol[i-1];
        else
            sol[i]=((i-1)*sol[i-1])%mod;
    g<<sol[n];
    return 0;
}
