/*
    editorial = https://codeforces.com/blog/entry/66506?#comment-505659
*/
#include<bits/stdc++.h>
using namespace std;
int subtask, n, dist[3002][3002];
int nr;
pair<int, int> ans[3002];
vector<int>v[3002];
int tt[3002], color[3002];
int Find(int nod)
{
    if(tt[nod] == nod)
        return nod;
    return tt[nod] = Find(tt[nod]);
}
void Union(int a, int b)
{
    if(Find(a) == Find(b))
        return;
    ans[++nr] = {a, b};
    v[a].push_back(b);
    v[b].push_back(a);
    a = Find(a);
    b = Find(b);
    tt[a] = b;
}

int cnt[3002], viz[3002];
int newcolor = 0;

void give_color(int grupa, int nod, int p)
{
    if(cnt[color[nod]] == 0 && dist[grupa][nod] == dist[grupa][p])
        color[grupa] = color[nod];
    if(p != -1)
        cnt[color[nod]]++;
    for(int i = 0; i < v[nod].size(); i++)
    {
        int vecin = v[nod][i];
        if(viz[vecin] == 0 || vecin == p)
            continue;
        give_color(grupa, vecin, nod);
    }
    if(p != -1)
        cnt[color[nod]]--;
}

void dfs(int nod, int dad)
{
    viz[nod] = 1;
    give_color(nod, nod, -1);
    if(color[nod] == 0)
        color[nod] = ++newcolor;
    for(int i = 0; i < v[nod].size(); i++)
    {
        int vecin = v[nod][i];
        if(vecin == dad)
            continue;
        dfs(vecin, nod);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> subtask;
    cin >> n;
    for(int i = 1; i <= n; ++i)
        tt[i] = i;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j)
        {
            cin >> dist[i][j];
            if(dist[i][j] == 1)
                Union(i, j);
        }
    vector<int>noduri;
    for(int i = 1; i <= n; ++i)
        if(Find(i) == i)
            noduri.push_back(i);
    for(int i = 0; i < noduri.size(); ++i)
    {
        int nod = noduri[i];
        for(int j = i+1; j < noduri.size(); ++j)
        {
            int vecin = noduri[j];
            if(dist[nod][vecin] == 2)
                Union(nod, vecin);
        }
    }
    cnt[0] = 1;
    dfs(1, 0);
    for(int i = 1; i <= n; ++i)
        cout << color[i] << " ";
    cout << '\n';
    for(int i = 1; i < n; ++i)
        cout << ans[i].first << " " << ans[i].second << '\n';
    return 0;
}
