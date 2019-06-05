#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int n;
vector<int>v[200002];
int weight[200002],last_w[200002],lvl[200002],next_w[200002];
void DFS(int node, int parent)
{
    lvl[node] = lvl[parent] + 1;
    weight[node] = 1;
    last_w[node] = node;
    int maxx = 0;
    for(int i = 0; i < v[node].size(); ++i)
    {
        int vecin = v[node][i];
        if(vecin == parent)
            continue;
        DFS(vecin, node);
        weight[node] += weight[vecin];
        if(weight[vecin] > maxx)
        {
            maxx = weight[vecin];
            last_w[node] = last_w[vecin];
            next_w[node] = vecin;
        }
    }
}
void search_node(int root, int dx)
{
    cout << "d " << last_w[root] << endl;
    int dist;
    cin >> dist;
    int dmiddle = (lvl[last_w[root]] + dx - dist) / 2;
    int node = root;
    while(lvl[node] - 1 != dmiddle)
        node = next_w[node];
    if(dx == dmiddle)
        cout << "! " << node << endl;
    else
    {
        cout << "s " << node << endl;
        cin >> node;
        search_node(node,dx);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 1; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    int d;
    cout << "d " << 1 << endl;
    cin >> d;
    DFS(1, 0);
    search_node(1, d);
    return 0;
}
