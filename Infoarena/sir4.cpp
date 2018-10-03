#include<fstream>
#include<cstring>
#include<algorithm>
using namespace std;
ifstream f("sir4.in");
ofstream g("sir4.out");
long long xo,A,B,M,Q;
char c[10002];
int n[10002];
struct queries
{
    long long nrq,mod,val;
};
queries v[1002];
bool test(queries a, queries b)
{
    return a.mod<b.mod;
}
bool test1(queries a, queries b)
{
    return a.nrq<b.nrq;
}
int main()
{
    f>>xo>>A>>B>>M>>Q;
    long long nr=(xo*A+B)%M;
    int per=1;
    while(nr!=xo){
        nr=(nr*A+B)%M;
        ++per;
    }
    for(int i=1;i<=Q;++i)
    {
        v[i].nrq=i;
        f>>c;
        int l=strlen(c);
        for(int j=0;j<l;++j)
            n[j]=c[j]-'0';
        n[l]=0;
        for(int j=0;j<l;++j)
            n[j+1]+=(n[j]%per)*10;
        v[i].mod=n[l]/10;
    }
    sort(v+1,v+Q+1,test);
    nr=xo;
    per=0;
    for(int i=1;i<=Q;++i)
    {
        while(v[i].mod>per)
        {
            nr=(nr*A+B)%M;
            ++per;
        }
        v[i].val=nr;
   }
   sort(v+1,v+Q+1,test1);
   for(int i=1;i<=Q;++i)
    g<<v[i].val<<" ";
    return 0;
}
