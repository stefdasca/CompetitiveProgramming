#include<bits/stdc++.h>
#define zeros(x) ((x^(x-1))&x)
using namespace std;
ifstream f("datorii.in");
ofstream g("datorii.out");
int n,m,nr,AIB[16002];
int op,poz,val;
void Add(int x, int quantity)
{
    int i;

    for (i = x; i <= n; i += zeros(i))
        AIB[i] += quantity;
}
int Compute(int x)
{
    int i, ret = 0;

    for (i = x; i > 0; i -= zeros(i))
        ret += AIB[i];
    return ret;
}
int main()
{
    f>>n>>m;
    for(int i=1;i<=n;++i)
    {
        f>>nr;
        Add(i,nr);
    }
    for(int i=1;i<=m;++i)
    {
        f>>op>>poz;
        if(op==0){
            f>>val;
            Add(poz,-val);
        }
        if(op==1){
            f>>val;
            g<<Compute(val)-Compute(poz-1)<<'\n';
        }
    }
    return 0;
}
