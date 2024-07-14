// https://www.infoarena.ro/problema/bellmanford

#include <bits/stdc++.h>
using namespace std;

int main() {
    
    ifstream cin("bellmanford.in");
    ofstream cout("bellmanford.out");
    
    int n, m;
    cin >> n >> m;
    
    vector<vector<pair<int, int> > > graph(n+1);
    for (int i = 1; i <= m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        
        graph[a].push_back({b, c});
    }
    
    vector<long long> costs(n+1, (1LL<<60));
    vector<int> cnt(n+1);
    
    costs[1] = 0;
    queue<int> q; 
    q.push(1);
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        
        for (int i = 0; i < (int) graph[node].size(); i++) {
            int nxt = graph[node][i].first;
            int c = graph[node][i].second;
            if (costs[node] + c < costs[nxt]) {
                costs[nxt] = costs[node] + c;
                q.push(nxt);
                
                cnt[nxt]++;
                if (cnt[nxt] > n) {
                    cout << "Ciclu negativ!" << '\n';
                    return 0;
                }
            }
        }
    }
    
    for (int i = 2; i <= n; i++) {
        cout << costs[i] << " ";
    }
    return 0;
}
