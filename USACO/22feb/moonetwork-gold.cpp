/*
    if for a given point we know the closest points with a X coordinate larger than the current one and distinct Y, we can use Kruskal's algorithm to solve the problem. 
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    vector<vector<pair<int, int>>> vec(11);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first >> a[i].second;
        vec[a[i].second].push_back({a[i].first, i});
    }
    vector<array<long long, 3>> edges;
    for (auto &x : vec) {
        sort(x.begin(), x.end());
    }
    // for every point we consider all Y coordinates and binary search for the closest points to the current point and then we create the edge
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= 10; ++j) {
            int l = 0, r = (int)vec[j].size() - 1;
            int to = -1;
            while (l <= r) {
                int mid = (l + r) / 2;
                if (vec[j][mid].first >= a[i].first + (j == a[i].second)) {
                    to = vec[j][mid].second;
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
            if (to != -1) {
                long long A = (a[i].first - a[to].first);
                long long B = (a[i].second - a[to].second);
                edges.push_back({A * A + B * B, i, to});
            }
        }
    }
    
    sort(edges.begin(), edges.end());
    vector<int> leader(n);
    vector<vector<int>> members(n);
    for (int i = 0; i < n; ++i) {
        leader[i] = i;
        members[i].push_back(i);
    }
    auto merge = [&] (int x, int y) {
        x = leader[x];
        y = leader[y];
        if (x == y) return 0;
        for (int mem : members[x]) {
            leader[mem] = y;
            members[y].push_back(mem);
        }
        return 1;
    };
    long long ans = 0;
    for (int i = 0; i < edges.size(); ++i) {
        if (merge(edges[i][1], edges[i][2])) {
            ans += edges[i][0];
        }
    }
    cout << ans << '\n';
    return 0;
}
