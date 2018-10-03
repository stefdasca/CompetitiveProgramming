#include<bits/stdc++.h>
using namespace std;
ifstream f("tree.in");
ofstream g("tree.out");
int n,root,sol;
vector<int>v[200002];
bool good[200002];
void dfs(int nr)
{
    int nrr=0;
    for(int i=0;i<v[nr].size();++i)
    {
        int vec=v[nr][i];
        dfs(vec);
        if(!good[vec])
            ++nrr;
    }
    if(nrr>=2)
    {
        sol+=nrr-1;
        good[nr]=1;
    }
    else
        if(nrr==1 && nr==root)
            ++sol;
}
int main()
{
    f>>n;
    for(int i=1;i<=n;++i)
    {
        int nr;
        f>>nr;
        v[nr].push_back(i);
        if(nr==0)
            root=i;
    }
    dfs(root);
    g<<2*sol-1;
    return 0;
}
