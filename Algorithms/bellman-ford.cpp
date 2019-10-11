// https://www.infoarena.ro/problema/bellmanford

#include<bits/stdc++.h>
using namespace std;
ifstream f("bellmanford.in");
ofstream g("bellmanford.out");
int n, m, viz[50005], d[50005];
bool is[50005];
struct nod
{
    int x, c;
};
vector <nod> v[50005];
queue <int> q;
int bellmanford(int x)
{
    q.push(x);
    viz[x] = 1;
    d[x] = 0;
    is[x] = 1;
    while(!q.empty())
    {
        x = q.front();
        q.pop();
        is[x] = 0;
        for(int i = 0; i < v[x].size(); i++)
        {
            int y = v[x][i].x;
            if(d[y] > d[x] + v[x][i].c)
            {
                d[y] = d[x] + v[x][i].c;
                viz[y]++;
                if(viz[y] >= n-1)
                    return 0;
                if(!is[y])
                {
                    q.push(y);
                    is[y]=1;
                }
            }
        }
    }
    return 1;
}
int main()
{
    f >> n >> m;
    for(int i = 1; i <= m; i++)
    {
        int x, y, c;
        f >> x >> y >> c;
        v[x].push_back({y, c});
    }
    for(int i = 1; i <= n; i++)
        d[i] = (1 << 30);
    if(bellmanford(1) == 0)
        g << "Ciclu negativ!";
    else
        for(int i = 2; i <= n; i++)
            g << d[i] << " ";
    return 0;
}
