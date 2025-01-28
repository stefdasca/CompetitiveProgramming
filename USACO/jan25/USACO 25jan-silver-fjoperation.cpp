/*
    USACO 25jan-silver-fjoperation
    
    This problem is very similar in style to 2018 february teleportation, as we want to find for
each value from the input the modulo m and then for each number, we can think at computing the
number of operations required to reach that modulo. If we plot on a chart the number of operations
required to achieve each remainder, the chart goes up, then down and up or the other way around, and
the rate of change is liniar. 

    This gives us the incentive to think at using difference arrays for the slopes and use the same trick
from Teleportation to compute the sum of deltas while taking in account the various casework out there.

    Teleportation code: https://github.com/stefdasca/CompetitiveProgramming/blob/master/USACO/USACO%2018feb-silver-teleportation.cpp


*/

#include <iostream>
#include <vector>
#include <map>
 
using namespace std;
 
int m;
int deltapos (int a, int b) {
    if (b >= a) {
        return b-a;
    }
    return m+b-a;
}

int deltaneg (int a, int b) {
    if (a >= b) {
        return a-b;
    }
    return m+a-b;
}

void solve() {
    int n;
    cin >> n >> m;
    
    // 7 18
    // 8 12 10 5 11 5 0
    
    vector<int> vals(n+1);
    map<long long, int> diff;
    long long sum = 0;
    long long deltasums = 0;
    for (int i = 1; i <= n; i++) {
        cin >> vals[i];
        vals[i] %= m;
        if (vals[i] != 0) {
            sum += min(deltapos(vals[i], 0), deltaneg(vals[i], 0));
        }
        int val_1 = min(deltapos(vals[i], 1), deltaneg(vals[i], 1));
        int val_0 = min(deltapos(vals[i], 0), deltaneg(vals[i], 0));
        int start = 0;
        
        if (val_1 == val_0) {
            val_1 = min(deltapos(vals[i], 2), deltaneg(vals[i], 2));
            val_0 = min(deltapos(vals[i], 1), deltaneg(vals[i], 1));
            start++;
        }
        
        if (val_1 > val_0) {
            diff[start]++;
            int peak = m/2 - val_0;
            diff[peak]--;
            int xpeak = min(deltapos(vals[i], peak+1), deltaneg(vals[i], peak+1));
            if (xpeak == m/2) {
                diff[peak+1]--;
            }
            else {
                diff[peak]--;
            }
            if (vals[i] != 0) {
                diff[vals[i]] += 2;
            }
        }
        if (val_1 < val_0) {
            diff[start]--;
            diff[vals[i]] += 2;
            int peak = vals[i] + m/2;
            diff[peak]--;
            int xpeak = min(deltapos(vals[i], peak+1), deltaneg(vals[i], peak+1));
            if (xpeak == m/2) {
                diff[peak+1]--;
            }
            else {
                diff[peak]--;
            }
        }
    }
    
    if (m == 1) {
        cout << 0 << '\n';
        return;
    }
    
    long long ans = sum;
    
    int prv = 0;
    for (auto x : diff) {
        if (x.first >= m) {
            break;
        }
        sum += 1LL * deltasums * (x.first - prv);
        ans = min(ans, sum);
        deltasums += x.second;
        prv = x.first;
    }
    
    sum += 1LL * deltasums * (m-1-prv);
    ans = min(ans, sum);
    
    cout << ans << '\n';
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
