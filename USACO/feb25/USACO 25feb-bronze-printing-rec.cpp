/*
    solution code by Stefan Dascalescu
    
    I will add the detailed writeup soon

*/

#include <iostream>
#include <vector>
 
using namespace std;
 
vector<int> v;
int rec (int L, int R, vector<vector<int>> &mini) {
    if (L == R) {
        mini[L][R] = 1;
    }
    if (mini[L][R] != 100000) {
        return mini[L][R];
    }
    int len = R - L + 1;
    for (int pos = 1; pos <= len/2; pos++) {
        if (len % pos == 0) {
            bool ok = 1;
            for (int i = L + pos; i <= R; i++) {
                if (v[i] != v[i - pos]) {
                    ok = 0;
                    break;
                }
            }
            if (ok == 1) {
                mini[L][R] = min(mini[L][R], rec(L, L + pos - 1, mini));
            }
        }
    }
    for (int split = L; split < R; split++) {
        mini[L][R] = min(mini[L][R], rec(L, split, mini) + rec(split+1, R, mini));
    }
    return mini[L][R];
}
void solve() {
    int n, k;
    cin >> n >> k;
    v.resize(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    vector<vector<int>> mini(n+1, vector<int> (n+1, 100000));
    rec(1, n, mini);
    
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
