/// #bettercoderthanshebeautiful
#include<bits/stdc++.h>
using namespace std;
ifstream f("readunare.in");
ofstream g("readunare.out");
struct ch
{
    char q[5000000];
    int len;
};
ch v[20];
char a[4002],b[4002];
int nv[12];
int main()
{
    f>>a;f>>b;
    v[0].q[0]='{';
    v[0].q[1]='}';
    v[0].len=2;
    for(int i=1;i<=19;++i)
    {
        v[i].q[0]='{';
        for(int j=i-1;j>=0;--j)
        {
            strcat(v[i].q,v[j].q);
            if(j>0)
                strcat(v[i].q,",");
        }
        v[i].len=strlen(v[i].q);
        v[i].q[v[i].len]='}';
        ++v[i].len;
    }
    int L=strlen(a);
    int nr=0;
    for(int i=0;i<=10;++i)
        if(v[i].len==L){
            nr+=i;
            break;
        }
    L=strlen(b);
    for(int i=0;i<=10;++i)
        if(v[i].len==L){
            nr+=i;
            break;
        }
    if(nr<20)
        g<<v[nr].q<<'\n';
    else
    {
        g<<"{";
        for(int i=19;i>=0;--i)
        {
            g<<v[i].q;
            if(i>0)
                g<<",";
        }
        g<<"}";
    }
    return 0;
}
