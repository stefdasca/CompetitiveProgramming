// https://cses.fi/problemset/task/1671/

#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<pair<int, int> > > graph(n+1); 
    for (int i = 1; i <= m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
    }
    
    vector<long long> cost(n+1, (1LL<<60));
    vector<int> vis(n+1);
    cost[1] = 0;
    priority_queue<pair<long long, int> > s;
    s.push({0, 1});
    
    while(!s.empty()) {
        pair<long long, int> smallest = s.top();
        s.pop();
        
        if (vis[smallest.second] == 1) {
            continue;
        }
        vis[smallest.second] = 1;
        
        for (int i = 0; i < (int) graph[smallest.second].size(); i++) {
            int nxt = graph[smallest.second][i].first;
            int val = graph[smallest.second][i].second;
            
            if (-smallest.first + val < cost[nxt]) {
                cost[nxt] = -smallest.first + val;
                s.push({-cost[nxt], nxt});
            }
        }
    }
    
    for (int i = 1; i <= n; i++) {
        cout << cost[i] << " ";
    }  
    return 0;
}
