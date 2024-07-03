#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct edges {
    int a, b, c;
};
edges v[200001];

bool cmp (edges a, edges b) {
    return a.c < b.c;
}

class dsu{
    private:
        int n;
        vector<int> parent, card; 
    public:
        void init (int sz) {
            n = sz;
            parent.resize(n+1);
            card.resize(n+1);
            for (int i = 1; i <= n; i++) {
                parent[i] = i;
                card[i] = 1;
            }
        }
        int Find (int x) {
            if (parent[x] == x) {
                return x;
            }
            return parent[x] = Find(parent[x]);
        }
        void Union (int a, int b) {
            a = Find(a); b = Find(b);
            if (a == b) {
                return;
            }
            if (card[b] > card[a]) {
                swap(a, b);
            }
            parent[b] = a;
            card[a] += card[b];
        }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    
    for (int i = 0; i < m; i++) {
        cin >> v[i].a >> v[i].b >> v[i].c;
    }
    sort(v, v + m, cmp);
    
    dsu links; links.init(n);
    
    long long cost = 0;
    int mch = 0;
    for (int i = 0; i < m; i++) {
        if (links.Find(v[i].a) != links.Find(v[i].b)) {
            cost += v[i].c;
            mch++;
            links.Union(v[i].a, v[i].b);
        }
    }
    
    if (mch == n-1) {
        cout << cost << '\n';
    }
    else {
        cout << "IMPOSSIBLE\n";
    }
    return 0;
}
