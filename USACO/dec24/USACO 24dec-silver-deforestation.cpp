/*
    First, sort the array. Then, when we think at the subtask with t = 1, we want to cover all intervals with as few points as possible. 
    
    Therefore, we want to delay the moment we add values as much as possible. Since we keep things in sorted order, we can do some binary searches at each step to see how much we really need to add.
    
    We will sort intervals by end point and keep values not taken yet in the set. Values are not distinct so multiset is necessary.
    
    I think there are nicer ways of storing how many values are in a set between two values but ordered set does the job just as well.

*/

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;
 
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> order_set;

void solve() {
    int n, k;
    cin >> n >> k;
    
    vector<int> v(n+1);
    multiset<int> untaken;
    
    order_set taken;
    
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    sort(v.begin() + 1, v.begin() + n + 1);
    
    vector<pair<int, pair<int, int>>> ranges(k+1);
    for (int i = 1; i <= k; i++) {
        cin >> ranges[i].second.first >> ranges[i].first >> ranges[i].second.second;
    }
    sort(ranges.begin() + 1, ranges.begin() + k + 1);
    
    int pos = 1;
    for (int i = 1; i <= k; i++) {
        while (pos <= n && v[pos] <= ranges[i].first) {
            untaken.insert(v[pos]);
            pos++;
        }
        
        int cnt = taken.size() - taken.order_of_key(ranges[i].second.first);
        
        while (cnt < ranges[i].second.second) {
            int vx = *untaken.rbegin();
            untaken.erase(untaken.lower_bound(vx));
            taken.insert(vx);
            cnt++;
        }
    }
    
    cout << (int) untaken.size() + (n - pos + 1) << '\n';
}
 
int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--) {
        solve();
    }
    return 0;
}
