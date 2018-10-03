#include<bits/stdc++.h>
using namespace std;
ifstream f("color2.in");
ofstream g("color2.out");
int n,win[17002],win2[17002];
vector<int>phts[17002];
void dfs(int nod)
{
    win[nod]=1;
    for(int i=0;i<phts[nod].size();++i)
    {
        dfs(phts[nod][i]);
        if(win[phts[nod][i]])
            win[nod]=0;
    }
}
void dfs2(int x)
{
    for(int i=0;i<phts[x].size();i++)
    {
        if(win2[x]==0 || win[phts[x][i]]==1)
            win2[phts[x][i]]=1;
        dfs2(phts[x][i]);
    }
}
int main()
{
    f>>n;
    for(int i=1;i<n;++i)
    {
        int a,b;
        f>>a>>b;
        phts[a].push_back(b);
    }
    win2[1]=1;
    dfs(1);
    dfs2(1);
    int sol=0;
    for(int i=1;i<=n;++i)
        if(win[i]+win2[i]==2)
            ++sol;
    g<<sol<<'\n';
    for(int i=1;i<=n;++i)
        if(win[i]+win2[i]==2)
            g<<i<<" ";
    return 0;
}

