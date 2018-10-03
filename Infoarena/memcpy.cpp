#include<bits/stdc++.h>
using namespace std;
ifstream f("memcpy.in");
ofstream g("memcpy.out");
const int MOD = 1000000007;
int n, m, x, y, x0, yy, dx, dy;
set<pair<int, int> > cells;
int main() {

    f>> n >> m >> x >> y >> x0 >> yy;
    dx = x0 - x;
    dy = yy - y;
    for (int i = x; i <= x + n - 1; i++)
        for (int j = y; j <= y + m - 1; j++)
            if (i + dx < x || i + dx >= x + n || j + dy < y || j + dy >= y + m)
                cells.insert(make_pair(i, j));
    int answer = 0;
    for (int i = 1; i <= n * m; i++) {
        pair<int, int> current = *cells.begin();
        answer += 1LL * i * current.first * current.second % MOD;
        answer %= MOD;
        cells.erase(current);
        if (current.first - dx >= x && current.first - dx <= x + n - 1 && current.second - dy >= y && current.second - dy <= y + m - 1)
            cells.insert(make_pair(current.first - dx, current.second - dy));

    }
    g<< answer << "\n";
    return 0;
}
