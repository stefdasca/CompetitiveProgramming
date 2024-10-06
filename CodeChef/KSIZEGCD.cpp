/*
    First we know that ans[i] >= ans[i+1] for all i from 1 to n-1. Now we can't brute force this since the constraints are too big.

    However, if you fix the starting point of each subarray, there are at most log n changes for the overall gcd 
    (number of prime factors is at most log n)
    
    So we can now use sparse table to precompute gcds for all lengths which are powers of two and use them to binary search the changes.

*/

#include <iostream>
#include <vector>
using namespace std;

int gcd (int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd (b, a%b);
}

const int MAXN = 100005;
vector <int> logs(MAXN);

int main() {
	
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    for (int i = 2; i < MAXN; i++) {
        logs[i] = logs[i/2] + 1;
    }
    
    int t;
    cin >> t;
    
    for (; t; t--) {
        int n;
        cin >> n;
        
        vector <int> v(n+1);
        for (int i = 1; i <= n; i++) {
            cin >> v[i];
        }
        
        vector<vector<int>> rmq(logs[n] + 1, vector<int> (n+1));
        for (int i = 1; i <= n; i++) {
            rmq[0][i] = v[i];
        }
        for (int layer = 1; layer <= logs[n]; layer++) {
            for (int pos = 1; pos + (1<<layer) - 1 <= n; pos++) {
                rmq[layer][pos] = gcd(rmq[layer-1][pos], rmq[layer-1][pos + (1<<(layer-1))]);
            }
        }
        
        vector <int> ans(n+1);
        for (int i = 1; i <= n; i++) {
            int pos = i;
            int val = v[i];
            while (pos <= n) {
                int L = pos;
                int R = n;
                int lastequal = L;
                while (L <= R) {
                    int mid = (L + R) / 2;
                    int layer = logs[mid - i + 1];
                    int divisor = gcd(rmq[layer][i], rmq[layer][mid - (1<<layer) + 1]);
                    if (divisor == val) {
                        lastequal = mid;
                        L = mid + 1;
                    }
                    else {
                        R = mid - 1;
                    }
                }
                ans[lastequal - i + 1] = max(ans[lastequal - i + 1], val);
                if (lastequal < n) {
                    int layer = logs[lastequal - i + 2];
                    val = gcd(rmq[layer][i], rmq[layer][lastequal + 1 - (1<<layer) + 1]);
                }
                pos = lastequal + 1;
            }
        }
        
        for (int i = n-1; i >= 1; i--) {
            ans[i] = max(ans[i], ans[i+1]);
        }
        for (int i = 1; i <= n; i++) {
            cout << ans[i] << " ";
        }
        cout << '\n';
    }
}
