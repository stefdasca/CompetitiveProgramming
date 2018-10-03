#include<bits/stdc++.h>
using namespace std;
ifstream f("inter.in");
ofstream g("inter.out");
int n,m;
struct poz
{
    int nr,pinit;
};
poz v[1002];
bool test(poz a, poz b)
{
    return a.pinit<b.pinit;
}
int main()
{
    f>>n>>m;
    for(int i=1;i<=n;++i)
        v[i].nr=i,v[i].pinit=i;
    for(int i=1;i<=m;++i)
    {
        int x,y;
        f>>x>>y;
        if(x>y)
            swap(x,y);
        v[x].pinit++;
        v[y].pinit--;
    }
    sort(v+1,v+n+1,test);
    for(int i=1;i<=n;++i)
        g<<v[i].nr<<" ";
    return 0;
}
