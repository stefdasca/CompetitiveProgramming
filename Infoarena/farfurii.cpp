#include<bits/stdc++.h>
using namespace std;
ifstream f("farfurii.in");
ofstream g("farfurii.out");
long long n,nr,i,k;
int main()
{
    f>>n>>k;
    for(i=1;i<=n;++i){
        long long s=1ll*(n-i)*(n-i-1)/2;
        if(s<=k){
            g<<i+k-s<<" ";
            nr=i+k-s;
            break;
        }
        else
            g<<i<<" ";
    }
    for(int j=n;j>=i;--j)
        if(j!=nr)
            g<<j<<" ";
    return 0;
}
