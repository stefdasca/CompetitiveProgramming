/// #bettercoderthanshebeautiful
#include<bits/stdc++.h>
using namespace std;
ifstream f("senat.in");
ofstream g("senat.out");
int n,m;
vector<int>v[102];
int stanga[102],dreapta[102],marked[102];
char c[1002];
bool dfs(int nod)
{
    if(marked[nod])
        return 0;
    marked[nod]=1;
    for(int i=0;i<v[nod].size();++i)
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
int main()
{
    f>>n;
    f>>m;
    for(int i=1;i<=m;++i)
    {
        f.get();
        f.get(c,1002);
        int nr=0;
        int L=strlen(c);
        for(int j=0;j<L;++j)
            if(c[j]!=' ')
                nr=nr*10+c[j]-'0';
            else
                if(nr>0)
                    v[i].push_back(nr),nr=0;
        v[i].push_back(nr),nr=0;
    }
    bool ok=1;
    while(ok)
    {
        ok=0;
        for(int i=1;i<=m;++i)
            marked[i]=0;
        for(int i=1;i<=m;++i)
            if(!stanga[i] && dfs(i)){
                ok=1;
                break;
            }
    }
    int nrc=0;
    for(int i=1;i<=m;++i)
        if(stanga[i])
            ++nrc;
    if(nrc<m)
        g<<0;
    else
        for(int i=1;i<=m;++i)
            g<<stanga[i]<<'\n';
    return 0;
}
