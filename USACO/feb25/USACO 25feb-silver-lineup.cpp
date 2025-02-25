/*
    solution code by Stefan Dascalescu
    
    First, you start with finding the construction assuming no moves are allowed, which can be done easily using a suffix maximum array. 
    
    A key observation is that it can be proven that you want to move one of the numbers from this construction somewhere to the left in order to potentially improve the sequence printed.
    
    When choosing, you want to go for the first one which would result in at least one more number being added to the answer.

    video link: https://www.youtube.com/watch?v=szeIh8GRTHY

*/

#include <iostream>
#include <vector>
 
using namespace std;
 
void solve() {
    int n;
    cin >> n;
    
    vector<int> v(n+1), maxi(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    maxi[n] = v[n];
    for (int i = n-1; i >= 1; i--) {
        maxi[i] = max(maxi[i+1], v[i]);
    }
    
    vector<int> to_print;
    vector<int> ans;
    for (int i = 1; i <= n; i++) {
        if (v[i] == maxi[i]) {
            ans.push_back(i);
        }
    }
    
    int prv = 0;
    bool okx = 0;
    for (int i = 0; i < ans.size(); i++) {
        int mx2 = -1;
        if (i + 1 < ans.size()) {
            mx2 = v[ans[i+1]];
        }
        int mx = 0;
        for (int j = prv+1; j < ans[i]; j++) {
            mx = max(mx, v[j]);
        }
        if (mx >= mx2) {
            for (int j = 0; j <= i; j++) {
                to_print.push_back(v[ans[j]]);
            }
            for (int j = prv+1; j < ans[i]; j++) {
                maxi[j] = v[j];
            }
            for (int j = ans[i] - 2; j >= prv+1; j--) {
                maxi[j] = max(maxi[j], maxi[j+1]);
            }
            for (int j = prv+1; j < ans[i]; j++) {
                if (v[j] == maxi[j] && v[j] >= mx2) {
                    to_print.push_back(v[j]);
                }
                maxi[j] = v[j];
            }
            for (int j = i+1; j < ans.size(); j++) {
                to_print.push_back(v[ans[j]]);
            }
            okx = 1;
            break;
        }
        prv = ans[i];
    }
    if (okx == 0) {
        for (auto x : ans) {
            to_print.push_back(v[x]);
        }
    }
    for (int i = 0; i < (int) to_print.size(); i++) {
        cout << to_print[i];
        if (i+1 < to_print.size()) {
            cout << " ";
        }
    }
    cout << '\n';
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
