/*
    solution code by Stefan Dascalescu
    
    I will add the detailed writeup soon

*/

#include <iostream>
#include <vector>
 
using namespace std;

int upds (int x, int y, int n, vector<vector<char>> &grid) {
    int cntA = 0, cntB = 0;
    vector<pair<int, int>> points = 
    {{x, y}, {n-x+1, y}, {x, n-y+1}, {n-x+1, n-y+1}};
    
    for (int i = 0; i < 4; i++) {
        if (grid[points[i].first][points[i].second] == '.') {
            cntA++;
        }
        else {
            cntB++;
        }
    }
    
    return min(cntA, cntB);
}
int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, u;
    cin >> n >> u;
    
    vector<vector<char>> grid(n+1, vector<char> (n+1));
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        for (int j = 1; j <= n; j++) {
            grid[i][j] = s[j-1];
        }
    }
    
    int cnt = 0;
    for (int i = 1; i <= n/2; i++) {
        for (int j = n/2+1; j <= n; j++) {
            cnt += upds(i, j, n, grid);
        }
    }
    
    cout << cnt << '\n';
    for (; u; u--) {
        int x, y;
        cin >> x >> y;
        
        cnt -= upds(x, y, n, grid);
        if (grid[x][y] == '.') {
            grid[x][y] = '*';
        }
        else {
            grid[x][y] = '.';
        }
        cnt += upds(x, y, n, grid);
        
        cout << cnt << '\n';
    }
    return 0;
}
