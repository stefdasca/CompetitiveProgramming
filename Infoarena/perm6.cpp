#include<bits/stdc++.h>
using namespace std;
ifstream f("perm6.in");
ofstream g("perm6.out");
int n,k;
int m[46][1036];
struct nrmare
{
    int v[100],l;
};
nrmare v[47*1037];
void sum(int add, int ads)
{
    v[add].l=max(v[add].l,v[ads].l);
    for(int i=1;i<=v[ads].l;++i)
        v[add].v[i]+=v[ads].v[i];
}
void rec(int add)
{
    for(int i=1;i<=v[add].l;++i)
        if(v[add].v[i]>9)
        {
            v[add].v[i+1]+=v[add].v[i]/10;
            v[add].v[i]%=10;
            if(v[add].v[v[add].l+1]>0)
                ++v[add].l;
        }
}
int main()
{
    f>>n>>k;
    int ad=1;
    for(int i=1;i<=n;++i)
        for(int j=0;j<=i*(i-1)/2;++j)
            m[i][j]=ad++;
    v[1].v[1]=1;
    v[1].l=1;
    for(int i=2;i<=n;++i)
        for(int j=0;j<=i*(i-1)/2;++j){
            for(int q=0;q<i && q<=j;++q)
                sum(m[i][j],m[i-1][j-q]);
            rec(m[i][j]);
        }
    for(int i=v[m[n][k]].l;i>=1;--i)
        g<<v[m[n][k]].v[i];
    return 0;
}
