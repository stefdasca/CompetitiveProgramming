// based on https://cses.fi/problemset/task/2086/ 

#include <iostream>
#include <vector>
 
std::vector<std::vector<long long>> dp, sq;

// the main idea when it comes to d&c dp is to observe that if the quadrangle inequality holds 
// (or in layman terms, opt[i][j] <= opt[i][j+1] for all possible positions, we can apply this
// optimization

void divide (int layer, int L, int R, int optL, int optR) {
    if (L > R) {
        return;
    }
    long long bst = (1LL<<60);
    int whoo = -1;
    int mid = (L + R) / 2;
    for (int i = optL; i <= std::min(mid-1, optR); i++) {
        if (dp[layer-1][i] + sq[i+1][mid] < bst) {
            bst = dp[layer-1][i] + sq[i+1][mid];
            whoo = i;
        }
    }
    dp[layer][mid] = bst;
    divide(layer, L, mid-1, optL, whoo);
    divide(layer, mid+1, R, whoo, optR);
}
 
int main() {
    int n, k;
    std::cin >> n >> k;
    
    std::vector<int> v(n+1);
    for (int i = 1; i <= n; i++) {
        std::cin >> v[i];
    }
    
    dp.resize(k+1, std::vector<long long> (n+1));
    sq.resize(n+1, std::vector<long long> (n+1));
    
    for (int i = 1; i <= n; i++) {
        int sum = 0;
        for (int j = i; j <= n; j++) {
            sum += v[j];
            sq[i][j] = 1LL * sum * sum;
        }
    }
    
    for (int i = 1; i <= n; i++) {
        dp[1][i] = sq[1][i];
    }
    
    for (int i = 2; i <= k; i++) {
        for (int pos = 0; pos + 1 < i; pos++) {
            dp[i-1][pos] = (1LL<<60);
        }
        divide(i, i, n, i-1, n);
    }
    
    std::cout << dp[k][n] << '\n';
    return 0;
}
