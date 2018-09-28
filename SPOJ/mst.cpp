/// #bettercoderthanshebeautiful
#include<bits/stdc++.h>
using namespace std;
int n,m;
int dad[10002];
struct edges
{
    int a,b,c;
};
edges v[100002];
bool cmp(edges a, edges b)
{
    return a.c<b.c;
}
int arb(int nod)
{
    if(dad[nod]==nod)
        return nod;
    return dad[nod]=arb(dad[nod]);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n>>m;
    for(int i=1;i<=m;++i)
        cin>>v[i].a>>v[i].b>>v[i].c;
    sort(v+1,v+m+1,cmp);
    for(int i=1;i<=n;++i)
        dad[i]=i;
    int j=0;
    long long cm=0;
    for(int i=1;j<n && i<=m;++i)
        if(arb(v[i].a)!=arb(v[i].b))
        {
            ++j;
            cm+=v[i].c;
            dad[arb(v[i].a)]=v[i].b;
        }
    cout<<cm;
    return 0;
}
