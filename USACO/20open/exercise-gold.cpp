/*

US Open 2020 Gold exercise (https://usaco.org/index.php?page=viewproblem2&cpid=1043) by https://stefdasca.ro/

We want to find the sum of all cycle sizes for all permutations. Given that n is relatively small, we can think at various O(n^2) solutions, and this gives us the motivation to try a DP approach.

Now we can define dp[i] as the sum of all cycle sizes for all permutations of length i, but we need to find a way to avoid duplicate counting. In order to achieve this, let's think at what the cycle size is like.

If we have something like 2 1 4 5 3, every 6 steps, the permutation gets back to its original state, and this is true because we have cycles of lengths 2 and 3, and their LCM is 6. 

Therefore, it makes sense to run a DP and iterate over the prime numbers and their powers to compute the sum of these lengths (other numbers can be decomposed as sum of smaller values, for example we can get a 12 out of a 4 and 3, with a smaller sum).

The overall time complexity is O(n^2) with a very good constant and this is fast enough to give us full credit.

*/

#include <fstream>
#include <vector>
 
using namespace std;

int main() {
    ifstream cin("exercise.in");
    ofstream cout("exercise.out");
    
    
    int n, mod;
    cin >> n >> mod;
    
    vector<long long> dp(n+1);
    
    dp[0] = 1;
    for (int i = 2; i <= n; i++) {
        bool pr = 1;
        
        for (int j = 2; j * j <= i; j++) {
            if (i % j == 0) {
                pr = 0;
            }
        }
        
        if (pr) {
            for (int j = n; j >= 0; j--) {
                for (int val = i; val + j <= n; val *= i) {
                    dp[j + val] += 1LL * dp[j] * val;
                    dp[j + val] %= mod;
                }
            }
        }
    }
    
    long long sum = 0;
    for (int i = 0; i <= n; i++) {
        sum += dp[i];
    }
    
    cout << sum % mod << '\n';
    return 0;
}
