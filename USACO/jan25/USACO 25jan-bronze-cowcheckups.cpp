/*
    USACO 25jan-bronze-cowcheckups

    A brute force solution would invert every subarray and count in O(n) how many matching pairs we have, which
runs in total in O(n^3) that passes the first subtask.

    Our goal is to speed up the process of computing the number of matching pairs without having to do the entire
process.

    Now, we can compute for prefixes and suffixes the number of matching pairs without much difficulty and store
them in some prefix sum like structures. However, how do we deal with the parts that actually invert?

    Let's analyze what happens in a sequence (i, j) -> we have everything from i to j changing its place. 
    
    Now, the question is, what's a very similar sequence in terms of behavior? After some analyze, we can
conclude that (i-1, j+1) is very similar as it's basically (i, j) but with i-1 and j+1 inverted as well.

    Therefore, we can count the number of matching pairs for (i, j) as the number of matching pairs for 
(i+1, j-1) plus whatever happens when we invert i and j (the positions). Now, after we do this precomputation,
all we have to do is to iterate over all sequences and rely on the counts computed, together with the prefix/suffix
sums and we got the answer.
    
*/

#include <iostream>
#include <vector>
 
using namespace std;

int cnt[7502][7502];

int goodprefix[7502], goodsuffix[7502], frq[7502];
 
int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    vector<int> v(n+1), v2(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> v2[i];
        if (v[i] == v2[i]) {
            goodprefix[i]++;
            goodsuffix[i]++;
        }
    }
    
    for (int i = 1; i <= n; i++) {
        goodprefix[i] += goodprefix[i-1];
    }
    for (int i = n; i >= 1; i--) {
        goodsuffix[i] += goodsuffix[i+1];
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            if (i != j) {
                cnt[i][j] += (v[i] == v2[j]) + (v[j] == v2[i]);
            }
            else {
                cnt[i][j] += (v[i] == v2[j]);
            }
        }
    }
    
    for (int len = 1; len <= n; len++) {
        for (int L = 1; L + len - 1 <= n; L++) {
            cnt[L-1][L+len] += cnt[L][L+len-1];
        }
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            int total_good = cnt[i][j] + goodprefix[i-1] + goodsuffix[j+1];
            frq[total_good]++;
        }
    }
    
    for (int i = 0; i <= n; i++) {
        cout << frq[i] << '\n';
    }
    
    return 0;
}
