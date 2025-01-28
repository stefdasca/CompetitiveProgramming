/*
    USACO 25jan-silver-tablerecovery
    
    This problem has been quite strange in nature as we only had to look at where the values with frequency 1
are and realize that the original rows have stayed in the same place, maybe in a different order and a different
individual line order. This reduces the number of eligible grids for the answer to two, as we can uniquely
reconstruct the grids based on the info from that row. 

    All we had to do is to find whichever grid is smaller lexicografically, which is something that can be
done very easily.


*/

#include <iostream>
#include <vector>
#include <set>
 
using namespace std;
 
void solve() {
    int n;
    cin >> n;
    
    vector<vector<int>> grid(n+1, vector<int> (n+1));
    vector<vector<int>> grid2(n+1, vector<int> (n+1));
    vector<vector<int>> grid3(n+1, vector<int> (n+1));
    vector<int> frq(2*n+1);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> grid[i][j];
            frq[grid[i][j]]++;
        }
    }
    
    vector<int> vis(2*n+1), added(2*n+1);
    bool done = 0;
    for (int i = 1; i <= n; i++) {
        bool ok = 0;
        if (done) {
            break;
        }
        for (int j = 1; j <= n; j++) {
            if (frq[grid[i][j]] == 1) {
                ok = 1;
                done = 1;
            }
        }
        if (ok == 1) {
            for (int j = 1; j <= n; j++) {
                if (added[grid[i][j]]) {
                    grid2[i][j] = added[grid[i][j]];
                    continue;
                }
                int cnt = frq[grid[i][j]];
                if (vis[2 + cnt - 1]) {
                    added[grid[i][j]] = n+n-cnt+1;
                    grid2[i][j] = added[grid[i][j]];
                    vis[n+n-cnt+1] = 1;
                }
                else {
                    added[grid[i][j]] = 2 + cnt - 1;
                    grid2[i][j] = added[grid[i][j]];
                    vis[2 + cnt - 1] = 1;
                }
            }
        }
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (added[grid[i][j]]) {
                grid2[i][j] = added[grid[i][j]];
                continue;
            }
            int cnt = frq[grid[i][j]];
            if (vis[2 + cnt - 1]) {
                added[grid[i][j]] = n+n-cnt+1;
                grid2[i][j] = added[grid[i][j]];
                vis[n+n-cnt+1] = 1;
            }
            else {
                added[grid[i][j]] = 2 + cnt - 1;
                grid2[i][j] = added[grid[i][j]];
                vis[2 + cnt - 1] = 1;
            }
        }
    }
    
    if (grid2[1][1] <= n+1) { // here we can check the grids instead
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cout << grid2[i][j];
                if (j != n) {
                    cout << " ";
                }
            }
            cout << '\n';
        }
    }
    else {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                grid3[i][j] = 2*n - grid2[i][j] + 2;
                cout << grid3[i][j];
                if (j != n) {
                    cout << " ";
                }
            }
            cout << '\n';
        }
    }
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
