#include<fstream>
#include<bitset>
using namespace std;
ifstream f("banda1.in");
ofstream g("banda1.out");
int n,b;
bitset<1001>v[1001];
int pp,n1,r;
int l=0;
void banda1()
{
    for(int i=1;i<=n;++i)
    {
        bool ok=1;
        for(int j=1;j<=n && ok;++j)
            ok=v[i][j];
        if(ok==1){
            ++l;
            if(l*n>n1 && l>1)
                n1=l*n,r=1,pp=l;
        }
        else
            l=0;
    }
}
void banda2()
{
    for(int i=1;i<=n;++i)
    {
        bool ok=1;
        for(int j=1;j<=n && ok;++j)
            ok=v[j][i];
        if(ok==1){
            ++l;
            if(l*n>=n1 && l>1)
                n1=l*n,r=2,pp=l;
        }
        else
            l=0;
    }
    l=0;
}
void banda3()
{
    int X=n,Y=1;
    int nr1=0;
    l=0;
    for(;(X!=1 || Y!=n+1);)
    {
        bool ok=1;
        int x=X,y=Y;
        for(;x<=n && y<=n && ok;++x,++y)
            ok=v[x][y],++nr1;
        if(ok==1){
            ++l;
            if(nr1>=n1 && l>1)
                n1=nr1,r=3,pp=l;
        }
        else
        {
            nr1=0;
            l=0;
        }
        if(X>1)
            --X;
        else
            ++Y;
    }
}
void banda4()
{
    int X=n,Y=n;
    int nr1=0;
    l=0;
    for(;(X!=1 || Y!=0);)
    {
        bool ok=1;
        int x=X,y=Y;
        for(;x<=n && y && ok;++x,--y)
            ok=v[x][y],++nr1;
        if(ok==1){
            ++l;
            if(nr1>=n1 && l>1)
                n1=nr1,r=4,pp=l;
        }
        else
        {
            nr1=0;
            l=0;
        }
        if(X>1)
            --X;
        else
            --Y;
    }
}
int main()
{
    f>>n;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j){
            f>>b;
            v[i][j]=b;
        }
    banda1();
    banda2();
    banda3();
    banda4();
    g<<r<<'\n'<<pp<<'\n'<<n1;
    return 0;
}
