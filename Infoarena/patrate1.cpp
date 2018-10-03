#include<fstream>
#include<algorithm>
using namespace std;
ifstream f("patrate1.in");
ofstream g("patrate1.out");
int n,h,ci,lmax,v[1002],v1[1002];
int main()
{
    f>>n>>h;
    for(int i=1;i<=n;++i)
    {
        int a,b;
        f>>a>>b;
        b=b+a-1;
        v[i]=a;
        v1[i]=b;
    }
    sort(v+1,v+n+1);
    sort(v1+1,v1+n+1);
    int x=1;
    int y=1;
    int l=0;
    int bg=0;
    while(x<=n)
    {
        if(v[x]<v1[y]){
            ++l,++x;
            if(l==h)
                bg=v[x-1];
        }
        else
            if(v[x]==v1[y])
                ++x,++y;
            else{
                if(l==h){
                    if(v1[y]-bg+1>lmax)
                        lmax=v1[y]-bg+1,ci=bg;
                }
                --l,++y;
            }
    }
    while(y<=n)
    {
        if(l==h){
            if(v1[y]-bg+1>lmax)
                lmax=v1[y]-bg+1,ci=bg;
            break;
        }
        --l,++y;
    }
    g<<ci<<" "<<lmax<<'\n';
    return 0;
}
