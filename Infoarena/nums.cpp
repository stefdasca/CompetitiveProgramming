#include<bits/stdc++.h>
using namespace std;
ifstream f("nums.in");
ofstream g("nums.out");
int n;
int aib[100002];
bool prs[100002];
int arr[100002],pos[100002];
struct qx
{
    int tip,pos,ps;
    string x;
};
qx v[100002];
int cate=0;
struct str
{
    string x;
};
str v2[100002];
void add(int nod)
{
    for(;nod<=cate;nod+=(nod&(-nod)))
        aib[nod]++;
}
int compute(int nod)
{
    int sol=0;
    for(;nod;nod-=(nod&(-nod)))
        sol+=aib[nod];
    return sol;
}
bool cmp(int a, int b)
{
    if(v2[a].x.size()!=v2[b].x.size())
        return v2[a].x.size()<v2[b].x.size();
    for(int i=0;i<v2[a].x.size();++i)
        if(v2[a].x[i]!=v2[b].x[i])
            return v2[a].x[i]<v2[b].x[i];
    return a<b;
}
bool cmp2(int a, int b)
{
    if(v2[a].x.size()!=v2[b].x.size())
        return 1;
    for(int i=0;i<v2[a].x.size();++i)
        if(v2[a].x[i]!=v2[b].x[i])
            return 1;
    return 0;
}
int main()
{
    f>>n;
    for(int i=1;i<=n;++i)
    {
        f>>v[i].tip;
        if(v[i].tip==1)
        {
            f>>v[i].x;
            ++cate;
            v[i].ps=cate;
            arr[cate]=cate;
            v2[cate].x=v[i].x;
        }
        else
            f>>v[i].pos;
    }
    sort(arr+1,arr+cate+1,cmp);
    int x=1;
    for(int i=2;i<=cate;++i)
        if(cmp2(arr[i],arr[x])!=0)
            arr[++x]=arr[i];
    for(int i=1;i<=x;++i)
        pos[arr[i]]=i;
    for(int i=1;i<=n;++i)
    {
        if(v[i].tip==1)
        {
            if(pos[v[i].ps]!=0)
                add(pos[v[i].ps]);
            continue;
        }
        int ii = 0;
        int p = 1;
        while(p*2<=x)
            p*=2;
        while(p)
        {
            if(ii+p<=x && aib[p + ii]<v[i].pos)
            {
                v[i].pos-=aib[p+ii];
                ii += p;
            }
            p /= 2;
        }
        ii++;
        g<<v2[arr[ii]].x<<'\n';

    }
    return 0;
}
