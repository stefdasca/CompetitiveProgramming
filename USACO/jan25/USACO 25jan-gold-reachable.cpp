/*

  Perform queries in reverse order, however you start off with connecting every pair of vertexes which have been removed using operation 1
as they weren't really removed. Then as you add them back, you keep merging the connected components using DSU while keeping track of
the actual size of the components.

*/
#include <iostream>
#include <vector>
 
using namespace std;
 
constexpr int NMAX = 200002;

int n, m;

vector<int> rad(NMAX), card(NMAX), truecnt(NMAX), removed(NMAX), trueremoved(NMAX);

int Find(int x) {
    if (rad[x] == x) {
        return x;
    }
    rad[x] = Find(rad[x]);
    return rad[x];
}

long long totalcnt = 0;

void Union(int a, int b) {
    if (a == b) {
        return;
    }
    if (card[a] < card[b]) {
        swap(a, b);
    }
    rad[b] = a;
    card[a] += card[b];
    totalcnt -= 1LL * truecnt[a] * (truecnt[a] - 1) / 2;
    totalcnt -= 1LL * truecnt[b] * (truecnt[b] - 1) / 2;
    truecnt[a] += truecnt[b];
    totalcnt += 1LL * truecnt[a] * (truecnt[a] - 1) / 2;
}
 
void addnode (int a) {
    totalcnt += truecnt[a];
    truecnt[a]++;
}

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    
    string s;
    cin >> s;

    s = ' ' + s;
    for (int i = 1; i <= n; i++) {
        trueremoved[i] = (s[i] == '0');
    }
    
    for (int i = 1; i <= n; ++i) {
        rad[i] = i;
        card[i] = 1;
    }
    
    vector<vector<int>> edges(n+1);
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    
    for (int i = 1; i <= n; i++) {
        for (auto x : edges[i]) {
            if (!trueremoved[i] && !trueremoved[x]) {
                Union(Find(i), Find(x));
            }
        }
    }
    
    vector<long long> ans(n+1);
    for (int i = n; i >= 1; i--) {
        if (trueremoved[i]) {
            trueremoved[i] = 0;
            for (auto x : edges[i]) {
                if (!trueremoved[i] && !trueremoved[x]) {
                    Union(Find(i), Find(x));
                }
            }
        }
        addnode(Find(i));
        ans[i] = totalcnt;
    }
    
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << '\n';
    }
    return 0;
}
