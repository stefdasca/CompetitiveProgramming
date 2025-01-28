/*
    USACO 25jan-bronze-astral

    First, if a and b are 0, counting the G and B is enough. 
    
    Otherwise, it's a matter of casework as we only care about how does the current value behave
with respect to its immediate surroundings. 

    If we have a B, we must make sure the square situated a to the left and b above is also colored, 
together with the current square. Otherwise, it's a -1 as the grid would be impossible.

    If we have a G, then we need to check whether the square situated a to the right and b below 
must be colored in both cases, otherwise it depends on whether we have any restriction from the square
above. 
    
    If we have a W, we don't do anything as the other cases are checked by default.
    
    At the end, we only count the number of squares we colored and this is our answer.
    
*/

#include <iostream>
#include <vector>
 
using namespace std;

void solve() {
    int n, a, b;
    cin >> n >> a >> b;
    swap(a, b);
    
    vector<vector<int>> coding(n+1, vector<int> (n+1));
    vector<vector<int>> old_grid(n+1, vector<int> (n+1));
    
    int total = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            char c;
            cin >> c;
            
            if (c == 'B') {
                coding[i][j] = 2;
                total++;
            }
            if (c == 'G') {
                coding[i][j] = 1;
                total++;
            }
        }
    }
    
    if (a == 0 && b == 0) {
        cout << total << '\n';
        return;
    }
    
    bool bad = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (coding[i][j] == 2) {
                if (i - a <= 0 || j - b <= 0) {
                    bad = 1;
                }
                else {
                    if (old_grid[i - a][j - b] == 0) {
                        bad = 1;
                    }
                    old_grid[i][j] = 1;
                }
            }
            if (coding[i][j] == 1) {
                if (i + a <= n && j + b <= n && coding[i + a][j + b] == 2) {
                    old_grid[i][j] = 1;
                }
                else {
                    if (i - a > 0 && j - b > 0 && old_grid[i - a][j - b] == 1) ;
                    else {
                        old_grid[i][j] = 1;
                    }
                }
            }
        }
    }
    
    if (bad == 1) {
        cout << -1 << '\n';
    }
    else {
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                ans += old_grid[i][j];
            }
        }
        
        cout << ans << '\n';
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
