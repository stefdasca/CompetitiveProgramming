#include <bits/stdc++.h>
using namespace std;
ifstream f ("petrica.in");
ofstream g ("petrica.out");
const int nmax=2*1e2+3;
vector <int> v[nmax];
bool viz[nmax];
int rez[nmax],st[5],n,x,y,sol=1e9,pop[nmax],min1,mij;
void dfs(int nod)
{
    viz[nod]=1;
    rez[nod]=pop[nod];
    for(int i=0;i<v[nod].size();++i)
    {
        if(!viz[v[nod][i]])
        {
            dfs(v[nod][i]);
            rez[nod]+=rez[v[nod][i]];
        }
    }
}
void back(int k)
{
    if(k==3)
    {
        viz[st[1]]=viz[st[2]]=1;
        dfs(1);
        min1=1e9;
        for(int i=2;i<=n;++i)
        {
            if(i!=st[1] && i!=st[2] && viz[i])
            {
                x=rez[1]-rez[i];
                if(abs(x-rez[i])<min1)
                {
                    min1=abs(x-rez[i]);
                    mij=i;
                }
            }
        }
        dfs(st[1]);
        dfs(st[2]);
        for(int i=2;i<=n;++i)
            viz[i]=0;
        x=max(max(rez[1]-rez[mij],rez[st[1]]),max(rez[st[2]],rez[mij]));
        y=min(min(rez[1]-rez[mij],rez[st[1]]),min(rez[st[2]],rez[mij]));
        sol=min(sol,x-y);
    }
    else
        for(int i=st[k-1]+1;i<=n;++i)
        {
            st[k]=i;
            back(k+1);
        }
}
int main()
{
    f>>n;
    for(int i=1;i<=n;++i)
        f>>pop[i];
    for(int i=1;i<n;++i)
    {
        f>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    st[0]=1;
    back(1);
    g<<sol;
    return 0;
}
