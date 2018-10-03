#include<bits/stdc++.h>
using namespace std;
ifstream f("distincte.in");
ofstream g("distincte.out");
int n,k,m,v[100002];
long long ans[100002];
const int mod = 666013;
long long sum;
struct qu
{
    int L, R, pi;
};
qu a[100002];
bool cmp(qu a, qu b)
{
    return a.R<b.R;
}
long long aib[100002];
void add(int nod, int val)
{
    for(;nod<=n;nod+=nod&(-nod))
        aib[nod]+=val;
}
long long compute(int nod)
{
    long long sol=0;
    for(;nod;nod-=(nod&(-nod)))
        sol+=aib[nod];
    return sol;
}
int lst[100002];
int main()
{
    f>>n>>k>>m;
    for(int i=1;i<=n;++i)
        f>>v[i];
    for(int i=1;i<=m;++i)
        f>>a[i].L>>a[i].R, a[i].pi=i;
    sort(a+1, a+m+1, cmp);
    for(int i=1;i<=m;++i)
    {
        for(int j=a[i-1].R+1;j<=a[i].R;++j)
        {
            if(lst[v[j]])
                add(lst[v[j]],-v[j]);
            add(j,v[j]);
            lst[v[j]]=j;
        }
        ans[a[i].pi]=(compute(a[i].R)-compute(a[i].L-1))%mod;
    }
    for(int i=1;i<=m;++i)
        g<<ans[i]<<'\n';
    return 0;
}
