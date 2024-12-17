/*
    We will solve this independently for each distinct value 
    
    First, we know that if we have few distinct positions, we can run this fast by brute forcing the changing points and seeing when things actually start moving around.
    
    Also we know that if we have a lot of distinct positions, the number of sequences drops fast.
    
    So we'll use the best out of both parts and brute force this for first ~50 moves, followed by binary searching the change points as they get fewer and fewer 

*/
#include <iostream>
#include <vector>
 
using namespace std;
 
void solve() {
    int n; 
    cin >> n;
    
    vector<int> v(n+1);
    vector<vector<int>> positions(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        positions[v[i]].push_back(i);
    }
    
    vector<int> ans(n+1), ans2(n+1);
    for (int i = 1; i <= n; i++) {
        if (!positions[i].size()) {
            continue;
        }
        int contrib;
        for (int sz = 1; sz <= min(n, 50); sz++) {
            int lst = positions[i][0];
            int cntt = 1;
            for (int j = 1; j < (int) positions[i].size(); j++) {
                if (positions[i][j] - lst > sz) {
                    cntt++;
                    lst = positions[i][j];
                }
            }
            if (sz == 1) {
                ans[1] += cntt;
            }
            else {
                ans[sz] -= (contrib - cntt);
            }
            contrib = cntt;
        }
        vector<int> beginnings = {positions[i][0]};
        int smallest = n+1;
        for (int j = 1; j < (int) positions[i].size(); j++) {
            if (positions[i][j] - beginnings.back() > min(n, 50)) {
                smallest = min(smallest, positions[i][j] - beginnings.back());
                beginnings.push_back(positions[i][j]);
            }
        }
        while (beginnings.size() > 1) {
            int j = 0; 
            int cnt = 1;
            int smallest2 = n+1;
            while (j < (int) positions[i].size()) {
                int L = j;
                int R = (int) positions[i].size() - 1;
                int ans = R+1;
                while (L <= R) {
                    int mid = (L + R) / 2; 
                    if (positions[i][mid] - positions[i][j] > smallest) {
                        ans = mid;
                        R = mid - 1;
                    }
                    else {
                        L = mid + 1;
                    }
                }
                if (ans < (int) positions[i].size()) {
                    smallest2 = min(smallest2, positions[i][ans] - beginnings[cnt-1]);
                    beginnings[cnt] = positions[i][ans];
                    cnt++;
                }
                j = ans;
            }
            ans[smallest] -= (beginnings.size() - cnt);
            smallest = smallest2; 
            while ((int) beginnings.size() > cnt) {
                beginnings.pop_back();
            }
        }   
    }
    for (int i = 1; i <= n; i++) {
        ans[i] += ans[i-1];
        cout << ans[i] << '\n';
    }
    
}
 
int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t = 1;
   // cin >> t;
    
    while (t--) {
        solve();
    }
    return 0;
}
