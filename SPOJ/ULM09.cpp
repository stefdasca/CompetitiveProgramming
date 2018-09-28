#include<bits/stdc++.h>
using namespace std;
int n,m;
struct muchii
{
    int a,b,c;
};
muchii v[200002];
int dad[200002];
long long cm;
bool cmp(muchii a, muchii b)
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
    while(cin>>n>>m)
    {
        if(n==0 && m==0)
            break;
        for(int i=1;i<=n;++i)
            dad[i]=i;
        cm=0;
        for(int i=1;i<=m;++i)
        {
            cin>>v[i].a>>v[i].b>>v[i].c;
            ++v[i].a,++v[i].b;
            cm+=v[i].c;
        }
        sort(v+1,v+m+1,cmp);
        int j=0;
        for(int i=1;j<n && i<=m;++i)
        {
            int x=arb(v[i].a);
            int y=arb(v[i].b);
            if(x!=y)
            {
                ++j;
                cm-=v[i].c;
                dad[x]=v[i].b;
            }
        }
        cout<<cm<<'\n';
    }
    return 0;
}
