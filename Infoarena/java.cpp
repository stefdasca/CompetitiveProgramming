/// #bettercoderthanshebeautiful
#include<bits/stdc++.h>
#define dim 200005
using namespace std;
ifstream f("java.in");
ofstream g("java.out");
int t,dreapta[dim],stanga[dim],st,dr,m,a,b;
bool marked[dim],ok;
vector<int>v[dim];
bool dfs(int nod)
{
    if(marked[nod])
        return 0;
    marked[nod] = 1;
    for (int i = 0; i < v[nod].size(); i ++)
    {
        int vecin = v[nod][i];
        if (!dreapta[vecin])
        {
            stanga[nod] = vecin;
            dreapta[vecin] = nod;
            return 1;
        }
    }
    for (int i = 0; i < v[nod].size(); i ++)
    {
        int vecin = v[nod][i];
        if (dfs (dreapta[vecin]))
        {
            stanga[nod] = vecin;
            dreapta[vecin] = nod;
            return 1;
        }
    }
    return 0;
}
void HK()
{
    ok =1;
    while (ok)
    {
        memset(marked,0,st+2);
        ok = false;
        for (int i =1; i <= st; i ++)
            if (!stanga[i]  && dfs(i))
                ok =1;
    }
}
int main()
{
    f>>t;
    for(;t;--t)
    {
        memset(dreapta,0,sizeof(dreapta));
        memset(stanga,0,sizeof(stanga));
        memset(marked,0,sizeof(marked));
        f>>st>>dr>>m;
        for(int i=1;i<=m;i++)
        {
            f>>a>>b;
            v[a].push_back(b);
        }
        HK();
        int cuplaje =0;
        for (int i =1; i <= st; i ++)
            if(stanga[i])
                cuplaje++;
        for(int i=1;i<=st;++i)
            v[i].clear();
        g<<cuplaje<<'\n';
    }
    return 0;
}
