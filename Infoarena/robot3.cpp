#include<fstream>
#include<algorithm>
using namespace std;
ifstream f("robot3.in");
ofstream g("robot3.out");
int n,m,l,c,nr;
char ch;
struct pcts
{
    short l,c,ord;
    int val;
};
pcts v[5002];
bool test(pcts a, pcts b)
{
    if(a.l==b.l)
        return a.c<b.c;
    return a.l<b.l;
}
bool test1(pcts a, pcts b)
{
    return a.ord<b.ord;
}
int main()
{
    f>>n>>m>>l>>c;
    v[1].l=l,v[1].c=c;
    v[1].ord=1;
    for(int i=2;i<=1+m;++i){
        f>>ch;
        if(ch=='N')
            v[i].l=v[i-1].l-1,v[i].c=v[i-1].c,v[i].ord=i;
        if(ch=='V')
            v[i].l=v[i-1].l,v[i].c=v[i-1].c-1,v[i].ord=i;
        if(ch=='S')
            v[i].l=v[i-1].l+1,v[i].c=v[i-1].c,v[i].ord=i;
        if(ch=='E')
            v[i].l=v[i-1].l,v[i].c=v[i-1].c+1,v[i].ord=i;
    }
    sort(v+1,v+m+2,test);
    int p=1;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
        {
            f>>nr;
            if(v[p].l==i && v[p].c==j)
            {
                v[p].val=nr;
                ++p;
            }
        }
    sort(v+1,v+m+2,test1);
    int cce=0;
    for(int i=1;i<=m+1;++i){
        cce=cce+v[i].val-1;
        if(cce>=0){
            if(i<m+1)
                l=v[i+1].l,c=v[i+1].c;
        }
        else
            break;
    }
    g<<l<<" "<<c<<'\n';
    return 0;
}
