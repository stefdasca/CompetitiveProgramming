#include<bits/stdc++.h>
using namespace std;
ifstream f("copaci.in");
ofstream g("copaci.out");
int n;
struct points
{
    long long x,y;
};
points v[100002];
long long s;
long long gcd(long long a, long long b)
{
    while(b)
    {
        long long c=a%b;
        a=b;
        b=c;
    }
    return a;
}
int main()
{
    f>>n;
    for(int i=1;i<=n;++i)
        f>>v[i].x>>v[i].y;
    v[n+1].x=v[1].x;
    v[n+1].y=v[1].y;
    for(int i=1;i<=n;++i)
        s=s+v[i].x*v[i+1].y-v[i+1].x*v[i].y;
    s=llabs(s*0.5);
    long long se=0;
    for(int i=1;i<=n;++i)
        se=se+gcd(llabs(v[i+1].x-v[i].x),llabs(v[i+1].y-v[i].y));
    s=s-se/2+1;
    g<<s;
    return 0;
}
