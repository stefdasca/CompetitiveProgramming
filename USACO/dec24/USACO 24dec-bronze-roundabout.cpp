/*
    Observation 1: the outcome of rounding can be simulated for the first few numbers and we can try identifying some pattern
    
    Observation 2: After running the numbers up to 10000, we can see the following numbers which work:
    
    * 45 - 49
    * 445 - 499
    * 4445 - 4999 
    etc.
    
    We can try each interval and see how many numbers fit in restrictions
    
    For small n, we can simulate the algorithm for each number and precompute the valid numbers

*/

#include <iostream>
using namespace std;
 
void brute_force() {
    int p10 = 10;
    for (int i = 1; i <= 10000; i++) {
        int rounding = i;
        if (rounding % p10 >= p10/2) {
            rounding += (p10 - i%p10);
        }
        else {
            rounding -= rounding % p10;
        }
        
        int chain = i;
        for (int pp = 10; pp <= p10; pp *= 10) {
            int rounding2 = chain;
            if (rounding2 % pp >= pp/2) {
                rounding2 += (pp - chain%pp);
            }
            else {
                rounding2 -= rounding2 % pp;
            }
            chain = rounding2;
        }
        
        if (rounding != chain) {
            cout << i << " " << rounding << " " << chain << '\n';
        }
        
        if (i >= p10) {
            p10 *= 10;
        }
    }
}

void solve() {
    long long n;
    cin >> n;
    
    long long va = 45, vb = 49;
    long long ans = 0;
    
    while (va <= n) {
        if (vb <= n) {
            ans += (vb - va + 1);
        }
        else {
            ans += (n - va + 1);
        }
        va = va * 10 - 5; // 445 = 45 * 10 - 5
        vb = vb * 10 + 9; // 499 = 49 * 10 + 9
    }
    
    cout << ans << '\n';
}

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // brute_force();
    int t;
    cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}
