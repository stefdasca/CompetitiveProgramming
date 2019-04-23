/*
        Baltic 16-Bosses

    Make the given input a directed graph, where if employee i accepts node j as boss, create an edge between j and i
    Then, do a BFS from each node and for each new node found, add to the answer (level of its dad + 1), so that we
won't need to do DFS anymore

*/
#include<bits/stdc++.h>
using namespace std;
int n, cost, ans = (1<<30);
vector<int>v[5002];
int viz[5002];
int s;
void bfs(int nod)
{
    memset(viz, 0, sizeof(viz));
    viz[nod] = 1;
    queue<int>q;
    q.push(nod);
    cost = 1;
    while(!q.empty())
    {
        int t = q.front();
        q.pop();
        for(int j = 0; j < v[t].size(); ++j)
        {
            int vecin = v[t][j];
            if(!viz[vecin])
            {
                s++;
                viz[vecin] = viz[t] + 1;
                cost += viz[vecin];
                q.push(vecin);
            }
        }
    }
}
int main()
{
    cin >> n;
    for(int i = 1; i <= n; ++i)
    {
        int k;
        cin >> k;
        for(int j = 1; j <= k; ++j)
        {
            int nr;
            cin >> nr;
            v[nr].push_back(i);
        }
    }
    for(int i = 1; i <= n; ++i)
    {
        s = 0;
        cost = 0;
        bfs(i);
        if(s == n-1)
            ans = min(ans, cost);
    }
    cout << ans;
    return 0;
}
