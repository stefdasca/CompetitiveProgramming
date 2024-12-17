/*
    The answer from the example is the smallest sum of 3 values in the array, the sample is completely useless so let's move to some actual tests
    
    If Bessie builds something with too big of a sum early on, Elsie will eat it. However, she should be able to get n/2+1 values together because of
how the game works. Given this, let's try to get her the smallest sum of n/2+1 values and see what happens.

    Looks like it actually works :)

*/

#include <iostream>
#include <vector>

using namespace std;
 
void solve() {
    int n;
    cin >> n;
    
    vector<int> v(n+1);
    
    long long sum = 0, mini = (1LL<<60);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        sum += v[i];
    }
    
    long long ps = 0;
    for (int i = 1; i <= n; i++) {
        ps += v[i];
        if (i > n/2+1) {
            ps -= v[i-n/2-1];
        }
        if (i >= n/2+1) {
            mini = min(mini, ps);
        }
    }
    cout << mini << " " << sum - mini << '\n';
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
