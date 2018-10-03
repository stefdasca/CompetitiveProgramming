#include<bits/stdc++.h>
using namespace std;
ifstream f("oz.in");
ofstream g("oz.out");
long long n,v[10002];
int m,a,b,d;
long long lcm(long long a,long long b)
{
   long long x1=a;
    long long x2=b;
    long long c;
    while(x2)
    {
        c=x1%x2;
        x1=x2;
        x2=c;
    }
    long long prd=a*b/x1;
    return prd;
}
long long dc(long long a,long long b)
{
    long long c;
    while(b)
    {
        c=a%b;
        a=b;
        b=c;
    }
    return a;
}
struct q
{
    long long a,b,d;
};
q v1[100002];
int main()
{
    f>>n>>m;
    for(int i=1;i<=n;++i)
        v[i]=1;
    for(int i=1;i<=m;++i)
    {
        f>>a>>b>>d;
        v1[i].a=a;
        v1[i].b=b;
        v1[i].d=d;
        v[a]=lcm(v[a],d);
        v[b]=lcm(v[b],d);
    }
    for( int i = 1; i <= m; i++ ){
        if( dc( v[ v1[i].a ], v[ v1[i].b ] ) != v1[i].d ){
            g<< "-1\n";
            return 0;
        }
    }
    for(int i=1;i<=n;++i)
        if(v[i]>2e9){
            g<<-1;return 0;
        }
    for(int i=1;i<=n;++i)
        g<<v[i]<<" ";
}
