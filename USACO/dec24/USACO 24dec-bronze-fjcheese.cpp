/*
    So the brick block can be 1x1xn, 1xnx1 or nx1x1, we can keep track of the number of empty slots and the answer gets bigger
    
    We'll need some 2D arrays for each orientation (x, y), (x, z) and (y, z) and count it like that (basically, find how many positions in the grids have only empty things)

*/

#include <iostream>
#include <vector>

using namespace std;

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, q;
    cin >> n >> q;
    
    vector<vector<int>> xy(n, vector<int> (n)), xz(n, vector<int> (n)), yz(n, vector<int> (n));
    
    int ans = 0;
    while (q--) {
        int x, y, z;
        cin >> x >> y >> z;
        
        xy[x][y]++;
        if (xy[x][y] == n) {
            ans++;
        }
        xz[x][z]++;
        if (xz[x][z] == n) {
            ans++;
        }
        yz[y][z]++;
        if (yz[y][z] == n) {
            ans++;
        }
        
        cout << ans << '\n';
    }
    
    return 0;
}
