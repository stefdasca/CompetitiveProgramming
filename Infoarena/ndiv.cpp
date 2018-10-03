#include<bits/stdc++.h>
using namespace std;
ifstream f("ndiv.in");
ofstream g("ndiv.out");
long long a,b,v[100002];
int main()
{
    f>>a>>b;
    --a;
    long long sol1=0,sol2=0,i;
    int l=0;
    for(i=1;i*i<=a;++i){
        v[++l]=i;
        if(i!=a/i)
            v[++l]=a/i;
    }
    sort(v+1,v+l+1);
    for(i=1;i<=l;++i)
        sol1+=v[i]*(v[l-i+1]-v[l-i]);
    l=0;
    for(i=1;i*i<=b;++i){
        v[++l]=i;
        if(i!=b/i)
            v[++l]=b/i;
    }
    sort(v+1,v+l+1);
    for(i=1;i<=l;++i)
        sol2+=v[i]*(v[l-i+1]-v[l-i]);
    g<<sol2-sol1;
    return 0;
}
