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
        graph[b].push_back({a, c});
    }
    
    vector<int> cost(n+1, (1<<30));
    cost[1] = 0;
    set<pair<int, int> > s;
    s.insert({0, 1});
    
    long long MST = 0;
    int added = 0;
    while(!s.empty()) {
        pair<int, int> smallest = *s.begin();
        s.erase(smallest);
        
        MST += smallest.first;
        cost[smallest.second] = 0;
        added++;
        for (int i = 0; i < (int) graph[smallest.second].size(); i++) {
            int nxt = graph[smallest.second][i].first;
            int val = graph[smallest.second][i].second;
            
            if (val < cost[nxt]) {
                if (s.find({cost[nxt], nxt}) != s.end()) {
                    s.erase({cost[nxt], nxt});
                }
                cost[nxt] = val;
                s.insert({cost[nxt], nxt});
            }
        }
    }
    
    if (added == n) {
        cout << MST << '\n';
    }
    else {
        cout << "IMPOSSIBLE" << '\n';
    }  
    return 0;
}
