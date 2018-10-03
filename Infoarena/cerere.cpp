#include <bits/stdc++.h>
using namespace std;
ifstream f("cerere.in");
ofstream g("cerere.out");
int i,x,y,t,n;
bool T[100001]; // daca are un tata
int k[100001]; // daca poate rezolva
int s[100001]; // stramosi
int sol[100001]; // vectorul de solutii
vector <int> v[100001]; // lista de relatii tata-fiu
void dfs(int x)
{
    s[++t]=x;
    if(k[x])
        sol[x]=sol[s[t-k[x]]]+1;
    for(int i=0;i<v[x].size();++i)
        dfs(v[x][i]);
    --t;
}
int main()
{
    f>>n;
    for(i=1;i<=n;++i)
        f>>k[i];
    for(i=1;i<n;++i)
    {
        f>>x>>y;
        v[x].push_back(y);
        T[y]=1;
    }
    for(i=1;T[i];++i);
    dfs(i);
    for(i=1;i<=n;++i)
        g<<sol[i]<<" ";
    return 0;
}
