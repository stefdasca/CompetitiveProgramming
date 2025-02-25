/*
    solution code by Stefan Dascalescu
    
    Given that n is small, thinking at brute force solutions is natural, which is what I did too. Therefore, I have solve(i, j) which computes the minimum number of print statements to print values from ith to jth.

    If there is some value x such that v[i] = v[i-x] for all i in range (i+x, j) within that range, we got a period and solve(i, j) can be reduced to solve(i, i+x-1).

    We can also choose to split solve(i, j) in two and add up the answers. At the end, we consider the best option and check if solve(1, n) <= k.

    https://www.youtube.com/watch?v=amp4yB3ykho

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
