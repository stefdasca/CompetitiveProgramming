// https://www.infoarena.ro/problema/ctc

#include<bits/stdc++.h>
using namespace std;
ifstream f("ctc.in");
ofstream g("ctc.out");
int n, m, nr;
bool viz[100002], viz2[100002];
vector<int>v[100002], tr[100002], ctc[100002];
stack<int>s;
void dfs(int nod)
{
    viz[nod] = 1;
    for(int j = 0; j < v[nod].size(); ++j)
    {
        int vecin = v[nod][j];
        if(!viz[vecin])
            dfs(vecin);
    }
    s.push(nod);
}
void dfs2(int nod)
{
    viz2[nod] = 1;
    ctc[nr].push_back(nod);
    for(int j = 0; j < tr[nod].size(); ++j)
    {
        int vecin = tr[nod][j];
        if(!viz2[vecin])
            dfs2(vecin);
    }
}
int main()
{
    f >> n >> m;
    for(int i = 1; i <= m; ++i)
    {
        int a, b;
        f >> a >> b;
        v[a].push_back(b);
        tr[b].push_back(a);
    }
    for(int i = 1; i <= n; ++i)
        if(!viz[i])
            dfs(i);
    while(!s.empty())
    {
        int nod = s.top();
        s.pop();
        if(!viz2[nod])
        {
            ++nr;
            dfs2(nod);
        }
    }
    g << nr << '\n';
    for(int i = 1; i <= nr; g << '\n', ++i)
        for(int j = 0; j < ctc[i].size(); ++j)
            g << ctc[i][j] << " ";
    return 0;
}
