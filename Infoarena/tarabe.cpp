#include<bits/stdc++.h>
using namespace std;
ifstream f("tarabe.in");
ofstream g("tarabe.out");
long long n,k;
struct pr
{
    long long a,b;
};
pr v[200002];
bool check(long long maxx)
{
    long long ramas=k;
    for(int i=1;i<=n;++i)
    {
        if(maxx<v[i].a)
            continue;
        ramas=ramas-(maxx-v[i].a)/v[i].b-1;
    }
    if(ramas<=0)
        return 1;
    return 0;
}
int main()
{
    f>>n>>k;
    for(int i=1;i<=n;++i)
        f>>v[i].b>>v[i].a;
    long long b=1;
    long long e=1000000000;
    long long sol;
    while(b<=e)
    {
        long long mid=(b+e)/2;
        if(check(mid))
            sol=mid,e=mid-1;
        else
            b=mid+1;
    }
    long long result=0;
    long long cate=0;
    for(int i=1;i<=n;++i)
    {
        if(v[i].a>sol)
            continue;
        long long aa=(sol-v[i].a)/v[i].b+1;
        cate+=aa;
        result=result+aa*v[i].a;
        result=result+v[i].b*aa*(aa-1)/2;
    }
    g<<result-(cate-k)*sol;
    return 0;
}
