// https://cses.fi/problemset/task/1676/

#include <iostream>
#include <vector>
 
using namespace std;
 
int maxi, cnt;
 
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
            cnt--;
            maxi = max(maxi, card[a]);
        }
};
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    
    dsu links; links.init(n);
    
    maxi = 1; 
    cnt = n;
    
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        
        links.Union(a, b);
        
        cout << cnt << " " << maxi << '\n';
    }
    return 0;
}
