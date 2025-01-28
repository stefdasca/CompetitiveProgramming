/*
    USACO 25jan-bronze-mooin2

    We want to count the number of distinct subsequences of type abb. If they didn't have to be distinct,
we could think solely at the frequencies and count the product of frequencies. However, this isn't possible
so we need to be more strategic about it. 
    
    Thus, in order to avoid double counting, we want to start counting triples as late as possible, and this
is where we can adjust the position of the b's we will check. Therefore, we want to look at the latest two b's
in the array for every distinct value and then count how many distinct values exist before them in the array.

    In order to optimize this process, we can keep a rolling count of distinct values which will lead to finding
the answer fast.
    
*/

#include <iostream>
#include <vector>
 
using namespace std;

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    vector<int> v(n+1);
    vector<int> frq(n+1), frq2(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        frq2[v[i]]++;
    }
    
    long long ans = 0;
    int cntdistinct = 0;
    for (int i = 1; i <= n; i++) {
        frq2[v[i]]--;
        if (frq2[v[i]] == 1) {
            ans += 1LL * (cntdistinct - (frq[v[i]] > 0));
        }
        frq[v[i]]++;
        if (frq[v[i]] == 1) {
            cntdistinct++;
        }
    }
    
    cout << ans << '\n';
    return 0;
}
