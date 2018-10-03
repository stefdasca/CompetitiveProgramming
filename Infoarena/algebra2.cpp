/// #bettercoderthanshebeautiful
/// n^(n*(n+1)/2)
#include<bits/stdc++.h>
#define mod 1000000009
using namespace std;
ifstream f("algebra2.in");
ofstream g("algebra2.out");
long long n,a,b;
long long v[52],len;
long long pw(long long b)
{
    long long sol=1;
    while(len)
    {
        if(v[1]&1)
            sol=(sol*b)%mod;
        for(int i=len;i>=1;--i){
            v[i-1]+=10*(v[i]&1);
            v[i]>>=1;
        }
        if(v[len]==0)
            --len;
        b=((b%mod)*(b%mod))%mod;
    }
    return sol;
}
int main()
{
    f>>n;
    a=n;
    b=n+1;
    if(a%2==0)
        a/=2;
    else
        b/=2;
    while(a)
    {
        v[++len]=a%10;
        a/=10;
    }
    for(int i=1;i<=len;++i)
        v[i]*=b;
    for(int i=1;i<=len;++i)
        if(v[i]>9)
        {
            v[i+1]+=v[i]/10;
            v[i]%=10;
            if(i+1>len)
                ++len;
        }
    g<<pw(n);
    return 0;
}
