/// #bettercoderthanshebeautiful
#include<bits/stdc++.h>
#define dim 300005
using namespace std;
ifstream f("circulatie.in");
ofstream g("circulatie.out");
int dreapta[dim],stanga[dim],n,a,b;
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
void HopcroftKarp()
{
    ok =1;
    while (ok)
    {
        memset(marked,0,n+2);
        ok = false;
        for (int i =1; i <=n; i ++)
            if (!stanga[i]  && dfs(i))
                ok =1;
    }
}
int main()
{
    f>>n;
    for(int i=1;i<=3*n;i++)
    {
        f>>a>>b;
        v[a].push_back(b);
    }
    HopcroftKarp();
    for (int i = 1; i <=n; i ++)
        for(int j=0;j<=2;++j)
            if(v[i][j]==stanga[i])
                g<<i<<" "<< stanga[i]<<" "<<-2<<'\n';
            else
                g<<i<<" "<<v[i][j]<<" "<<1<<'\n';
    return 0;
}
