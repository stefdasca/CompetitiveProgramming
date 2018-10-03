/// #bettercoderthanshebeautiful
#include<bits/stdc++.h>
using namespace std;
ifstream f("pentagrame.in");
ofstream g("pentagrame.out");
int n,m,napmax;
set<int>s;
struct sc
{
    char c[6];
    int nap;
};
sc v[50002];
bool test(sc a, sc b)
{
    return strcmp(a.c,b.c)<0;
}
deque<char>d;
char q[32];
int cmp(int mid)
{
    for(int j=0;j<=4;++j)
        if(d[j]>v[mid].c[j])
            return 1;
        else
            if(d[j]<v[mid].c[j])
                return -1;
    return 0;
}
int bin_search()
{
    int b=1;
    int e=n;
    while(b<=e)
    {
        int mid=(b+e)/2;
        int val=cmp(mid);
        if(val==0)
            return mid;
        if(val==1)
            b=mid+1;
        else
            e=mid-1;
    }
    return 0;
}
int main()
{
    f>>n>>m;
    for(int i=1;i<=n;++i)
        f>>v[i].c;
    sort(v+1,v+n+1,test);
    for(int i=1;i<=m;++i)
    {
        f>>q;
        s.clear();
        int L=strlen(q);
        d.clear();
        for(int j=0;j<=4;++j)
            d.push_back(q[j]);
        for(int j=4;j<L;++j)
        {
            int poz=bin_search();
            if(poz && s.find(poz)==s.end())
            {
                v[poz].nap++;
                napmax=max(napmax,v[poz].nap);
                s.insert(poz);
            }
            if(j!=L-1)
            {
                d.pop_front();
                d.push_back(q[j+1]);
            }
        }
    }
    int nr=0;
    for(int i=1;i<=n;++i)
        if(v[i].nap==napmax)
            ++nr;
    g<<nr<<'\n';
    for(int i=1;i<=n;++i)
        if(v[i].nap==napmax)
            g<<v[i].c<<'\n';
    return 0;
}
