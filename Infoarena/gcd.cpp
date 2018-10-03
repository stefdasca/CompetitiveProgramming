#include<bits/stdc++.h>
using namespace std;
ifstream f("gcd.in");
ofstream g("gcd.out");
int t;
int n,m,mod;
int gcd(int a, int b)
{
    int c=0;
    while(b)
    {
        c=a%b;
        a=b;
        b=c;
    }
    return a;
}
int main()
{
    f>>t;
    for(;t;--t)
    {
        f>>n>>m>>mod;
        long long ex=gcd(n,m);
        long long sol=1;
        long long b=2;
        for(;ex;ex>>=1)
        {
            if(ex&1)
                sol=(sol*b)%mod;
            b=(b*b)%mod;
        }
        --sol;
        if(sol<0)
            sol+=mod;
        g<<sol<<'\n';
    }
    return 0;
}
