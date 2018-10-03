/// First problem from 2018
/// #bettercoderthanshebeautiful
#include<bits/stdc++.h>
using namespace std;
ifstream f("plicuri.in");
ofstream g("plicuri.out");
int n,idx[100002],Max=1;
struct st
{
    int l,c;
};
st v[100002];
bool test(st a, st b)
{
    if(a.l==b.l)
        return a.c>b.c;
    return a.l<b.l;
}
int bin(int y)
{
    int st=1;
    int dr=Max;
    while(st<=dr)
    {
        int mid=(st+dr)/2;
        if(y<=v[idx[mid]].c)
            dr=mid-1;
        else
            st=mid+1;
    }
    return st;
}
int main()
{
    f>>n;
    for(int i=1;i<=n;++i)
    {
        f>>v[i].l>>v[i].c;
        if(v[i].l>v[i].c)
            swap(v[i].l,v[i].c);
    }
    sort(v+1,v+n+1,test);
    idx[1]=1;
    for(int i=2;i<=n;++i)
    {
        int bst=bin(v[i].c);
        idx[bst]=i;
        Max=max(Max,bst);
    }
    g<<Max;
    return 0;
}
