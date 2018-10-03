#include<bits/stdc++.h>
using namespace std;
ifstream f("transformari.in");
ofstream g("transformari.out");
int n;
int ecd(int n, int i)
{
    if(i==1)
        return n-1;
    if(i==0)
        return 1000002;
    return n / i + ecd (i, n % i);
}
int main()
{
    f>>n;
    int minm=1000002;
    for(int i=1;i<=n;++i)
        minm=min(minm,ecd(n,i));
    g<<minm;
    return 0;
}
