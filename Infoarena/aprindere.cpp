#include<bits/stdc++.h>
using namespace std;
ifstream f("aprindere.in");
ofstream g("aprindere.out");
int n,m;
bool ap[1002];
struct inter
{
    int cost;
    vector<int>unde;
};
inter v[1002];
int mincost;
int main()
{
    f>>n>>m;
    for(int i=1;i<=n;++i)
        f>>ap[i];
    for(int i=1;i<=m;++i)
    {
        int c,t,nr;
        f>>c>>t>>nr;
        v[c+1].cost=t;
        for(int j=0;j<nr;++j)
        {
            int a;
            f>>a;
            v[c+1].unde.push_back(a+1);
        }
    }
    for(int i=1;i<=n;++i)
    {
        if(!v[i].cost)
            continue;
        if(ap[i]==0)
        {
            mincost+=v[i].cost;
            for(int j=0;j<v[i].unde.size();++j)
                ap[v[i].unde[j]]^=1;
        }
    }
    g<<mincost;
    return 0;
}
