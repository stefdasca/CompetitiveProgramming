#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#define mod 1000000007
using namespace std;
int n, m;
int ans = 0;
vector<pair<int, pair<int, int> > >adj[1002];
unordered_map<int, bool> vis1[1002], vis2[1002];
priority_queue< pair< pair<int, int>, pair<int, int> > > q;
void dijkstra()
{
    q.push({{1e7, 1}, {0, 1e7}});
    while(!q.empty())
    {
        auto state = q.top();
        int node = state.first.second;
        int l = state.second.first;
        int r = state.second.second;
        q.pop();
        if(vis1[node][l] || vis2[node][r] || state.first.first < ans)
            continue;
        vis1[node][l] = 1, vis2[node][r] = 1;
        if(node == n)
        {
            ans = max(ans, state.first.first+1);
            continue;
        }
        for(int i = 0; i < adj[node].size(); ++i)
        {
            int v = adj[node][i].first;
            int nl = adj[node][i].second.first;
            int nr = adj[node][i].second.second;
            int L = max(nl, l);
            int R = min(nr, r);
            if(max(nl, l) > min(nr, r))
                continue;
            q.push({{R-L, v}, {L, R}});
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    // shuffle(permutation.begin(), permutation.end(), rng);
    cin >> n >> m;
    for(int i = 1; i <= m; ++i)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        adj[a].push_back({b, {c, d}});
        adj[b].push_back({a, {c, d}});
    }
    dijkstra();
    if(ans == 0)
        cout << "Nice work, Dima!";
    else
        cout << ans;
    return 0;
}
