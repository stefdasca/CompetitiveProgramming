/*
    solution code by Stefan Dascalescu
    
    I will add the detailed writeup soon

*/

#include <iostream>
#include <vector>
 
using namespace std;
 
void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> v(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    
    vector<vector<int>> mini(n+1, vector<int> (n+1));
    for (int len = 1; len <= n; len++) {
        for (int start = 1; start + len - 1 <= n; start++) {
            if (len == 1) {
                mini[start][start] = 1;
            }
            else {
                mini[start][start + len - 1] = 100000;
                for (int pos = 1; pos <= len/2; pos++) {
                    if (len % pos == 0) {
                        bool ok = 1;
                        for (int i = start + pos; i <= start + len - 1; i++) {
                            if (v[i] != v[i - pos]) {
                                ok = 0;
                                break;
                            }
                        }
                        if (ok == 1) {
                            mini[start][start + len - 1] = min(mini[start][start + len - 1], mini[start][start + pos - 1]);
                        }
                    }
                }
                for (int split = start; split < start + len - 1; split++) {
                    mini[start][start + len - 1] = min(mini[start][start + len - 1], mini[start][split] + mini[split+1][start+len-1]);
                }
            }
        }
    }
    
    if (mini[1][n] <= k) {
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
    }
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
