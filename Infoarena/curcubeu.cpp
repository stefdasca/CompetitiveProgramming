/// #bettercoderthanshebeautiful
#include<bits/stdc++.h>
#define MaxD 1000002
using namespace std;
ifstream f("curcubeu.in");
ofstream g("curcubeu.out");
int n,col[MaxD],urm[MaxD];
struct q
{
    int a,b,c;
};
q v[MaxD];
int main()
{
    f>>n>>v[1].a>>v[1].b>>v[1].c;
    if(v[1].a>v[1].b)
        swap(v[1].a,v[1].b);
    for(int i=2;i<n;++i)
    {
        long long x=1LL*v[i-1].a*i%n;
        long long y=1LL*v[i-1].b*i%n;
        long long z=1LL*v[i-1].c*i%n;
        if(x>y)
            swap(x,y);
        v[i].a=x;
        v[i].b=y;
        v[i].c=z;
    }
    for(int i=n-1;i>=1;--i)
        for(int j=v[i].a;j<=v[i].b;)
            if(!col[j])
            {
                col[j]=v[i].c;
                urm[j]=v[i].b+1;
                ++j;
            }
            else
                j=urm[j];
    for(int i=1;i<n;++i)
        g<<col[i]<<'\n';
}
