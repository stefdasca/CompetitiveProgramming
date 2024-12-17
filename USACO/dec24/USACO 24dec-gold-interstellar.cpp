/*
    idea: we can start from a O(n^2) dp where we keep 2 dp's, dp[i] = # of ways to end at i if we get blue on i and dp2[i] the same but with white. 
    
    the n^2 solution is fairly simple, from i-1 you can go to i for whites if you can have a white and for blues, if we can add an interval between x and i, we add dp[x-1] to the answer
    
    in order to optimize, we can observe for each i how far we can go to the left due to the red restriction and also how far can we use it for other states due to the blue restriction

*/
#include <iostream>
#include <vector>
#include <set>
 
using namespace std;
 
vector<long long> fenwickeven, fenwickodd;

void add (int node, int val, int n, vector<long long> &fenwick) {
    for (; node <= n; node += (node & (-node))) {
        fenwick[node] += val;
    }
}

long long compute (int node, vector<long long> &fenwick) {
    if (node < 0) {
        return 0;
    }
    long long ans = 0;
    for (; node; node -= (node & (-node))) {
        ans += fenwick[node];
    }
    return ans%1000000007;
}

void solve() {
    
    int n; 
    cin >> n;
    
    string st;
    cin >> st;
    
    int mod = 1000000007;
    
    fenwickeven.resize(n+1);
    fenwickodd.resize(n+1); 
    
    vector<int> cntR(n+1), cntB(n+1);
    for (int i = 1; i <= n; i++) {
        cntR[i] = cntR[i-1];
        cntB[i] = cntB[i-1];
        if (st[i-1] == 'B') {
            cntB[i]++;
        }
        if (st[i-1] == 'R') {
            cntR[i]++;
        }
        
    }
    
    vector<long long> dpW(n+1), dp(n+1);
    vector<long long> dpW2(n+1), dp2(n+1);
    dpW[0] = 1;
    dpW2[0] = 1;
    set<pair<int, int > > s;
    for (int i = 1; i <= n; i++) {
        while (!s.empty() && (*s.begin()).first == i) {
            pair<int, int> val = *s.begin();
            s.erase(val);
            if (val.second % 2 == 0) {
                add(val.second, -(dp2[val.second] + dpW2[val.second]), n, fenwickeven);
            }
            else {
                add(val.second, -(dp2[val.second] + dpW2[val.second]), n, fenwickodd);
            }
        }
        if (i >= 2) {
            int L2 = 0;
            int R2 = i/2;
            int ans2 = n;
            while (L2 <= R2) {
                int mid = (L2 + R2) / 2;
                if (cntR[i] - cntR[i-mid]) {
                    ans2 = mid;
                    R2 = mid - 1;
                }
                else {
                    L2 = mid + 1;
                }
            }
            int trueend = i - ans2*2;
            if (i % 2 == 0) {
                dp2[i] = compute(i, fenwickeven) - compute(trueend, fenwickeven) + mod;
            }
            else {
                dp2[i] = compute(i, fenwickodd) - compute(trueend, fenwickodd) + mod;
            }
        }
        if (i % 2 == 0) {
            if (cntR[i] - cntR[i/2] == 0 && cntB[i/2] == 0) {
                dp2[i] += dpW2[0] + dp2[0];
            }
        }
        if (st[i-1] == 'X') {
            dpW2[i] = dp2[i-1] + dpW2[i-1];
        }
        dp2[i] %= mod;
        dpW2[i] %= mod;
        
        
        int L = i+1;
        int R = n;
        int ans = n+1;
        while (L <= R) {
            int mid = (L + R) / 2;
            if (cntB[mid] - cntB[i]) {
                ans = mid;
                R = mid - 1;
            }
            else {
                L = mid + 1;
            }
        }
        s.insert({ans + (ans - i), i});
        if (i % 2 == 0) {
            add(i, dp2[i] + dpW2[i], n, fenwickeven);
        }
        else {
            add(i, dp2[i] + dpW2[i], n, fenwickodd);
        }
    }
    
    cout << (dp2[n] + dpW2[n]) % mod << '\n';
}
 
int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t = 1;
   // cin >> t;
    
    while (t--) {
        solve();
    }
    return 0;
}
