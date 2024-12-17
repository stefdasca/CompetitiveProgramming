/*
    Same as https://kilonova.ro/problems/539 - https://github.com/stefdasca/statement-translator/blob/main/Kilonova/0500-0599/Processed_0539.md
*/
#include <algorithm>
#include <iostream>
#include <vector>
#include <set>

using namespace std;

using ll = long long;

struct jobs {
    int l, d, idx;
    bool operator < (const jobs& e) const {
        return this->d < e.d;
    }
};

void solve() {
    int n; 
    cin >> n;
    std::vector <jobs> v(n), tmp(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i].d >> v[i].l;
        v[i].d += v[i].l;
        v[i].idx = i;
        tmp[i] = v[i];
    }

    sort(v.begin(), v.end());
    set <pair <int, int>> s;
    vector <int> sch;
    for (int i = n - 1; i >= 0; --i) {
        int t = v[i].d;
        if (i > 0) {
            t -= v[i-1].d;
        }
        s.insert({v[i].l, v[i].idx});

        while (t and !s.empty()) {
            auto it = s.begin();
            if (it-> first <= t) {
                t -= it-> first;
                sch.emplace_back(it-> second);
            } else {
                s.insert({it-> first - t, it-> second});
                t = 0;
            }
            s.erase(it);
        }
    }

    cout << sch.size() << "\n";
}
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t = 1;
    cin >> t;
    
    while (t--) {
        solve();
    }
    return 0;
}
