/*
    USACO 25jan-silver-cowcheckup
    
    In order to solve this problem, we can mainly think at computing the individual contribution of
every position to the final answer. We can do this by computing for every number from 1 to n the positions
it shows up and this can be expanded with prefix sums as we think at the fact that the maximum contribution
of a pair (i, j) to the answer is min(i, n-i+1, j, n-j+1). As we consider this, we can think at performing
binary search to find the positions j which can contribute less than what i does and then subtract them from
the total number of positions from that number so that we can find the full contribution.


*/

#include <iostream>
#include <vector>
 
using namespace std;
 
void solve() {
    int n;
    cin >> n;
    
    vector<int> v(n+1), v2(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> v2[i];
    }
    
    
    vector<vector<long long>> pos(n+1), ps(n+1);
    for (int i = 1; i <= n; i++) {
        pos[v[i]].push_back(i);
        ps[v[i]].push_back(i);
    }
    
    for (int i = 1; i <= n; i++) {
        for (int pos = 1; pos < (int) ps[i].size(); pos++) {
            ps[i][pos] += ps[i][pos-1];
        }
    }
    
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        if (v[i] == v2[i]) { // ranges outside
            ans += 1LL * (i-1) * i / 2; 
            ans += 1LL * (n-i) * (n-i+1) / 2; 
        }
        // binary search for positions <= i
        int L = 0;
        int R = (int) pos[v2[i]].size() - 1;
        int ansx = -1;
        while (L <= R) {
            int mid = (L + R) / 2;
            if (pos[v2[i]][mid] <= min(n-i+1, i)) {
                ansx = mid;
                L = mid + 1;
            }
            else {
                R = mid - 1;
            }
        }
        if (ansx != -1) {
            ans += ps[v2[i]][ansx];
        }
        // binary search for positions >= n-i+1
        L = 0;
        R = (int) pos[v2[i]].size() - 1;
        int ansx2 = -1;
        while (L <= R) {
            int mid = (L + R) / 2;
            if (pos[v2[i]][mid] >= max(i, n-i+1)) {
                ansx2 = mid;
                R = mid - 1;
            }
            else {
                L = mid + 1;
            }
        }
        if (ansx2 != -1) {
            ans += 1LL * (pos[v2[i]].size() - ansx2) * (n+1) - ps[v2[i]].back();
            if (ansx2 > 0) {
                ans += ps[v2[i]][ansx2 - 1];
            }
        }
        int total = pos[v2[i]].size();
        if (ansx != -1) {
            total -= (ansx + 1);
        }
        if (ansx2 != -1) {
            total -= (pos[v2[i]].size() - ansx2);
        }
        ans += 1LL * min(n - i + 1, i) * total;
    }
    
    cout << ans << '\n';
}
 
int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t = 1;
    
    while (t--) {
        solve();
    }
    return 0;
}
