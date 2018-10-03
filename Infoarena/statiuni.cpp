#include<bits/stdc++.h>
using namespace std;
ifstream f("statiuni.in");
ofstream gg("statiuni.out");
struct Location { int prev, cur, dist; };
int n, k, pos[100001];
vector<int> g[100001];
queue<Location> q;
int main() {
    f >> n >> k;
    for (int i = 1, x, y; i < n; ++i) {
        f>> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for (int i = 1; i <= n; ++i) {
        if (g[i].size() == 1) {
            pos[i]++;
            q.push({0, i, 0});
        }
    }
    while(!q.empty()){
        Location loc = q.front();
        q.pop();
        int x = loc.cur;
        int prev = loc.prev;
        int dist = loc.dist;
        for (int i = 0; i < g[x].size(); ++i) {
            int y = g[x][i];
            if (y == prev)
                continue;
            if(dist<k && pos[y] < 2){
                pos[y]++;
                q.push({x, y, dist+1});
            }
        }
    }
    int sol = 0;
    for (int i = 1; i <= n; ++i)
        if (pos[i] >= 2)
            sol++;
    gg<<sol;
    return 0;
}
