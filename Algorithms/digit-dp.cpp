#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
// comparing the digits in order to see the state we update
int cmp(int a, int b) {
    if (a < b) {
        return 0;
    }
    if (a > b) {
        return 1;
    }
    return 2;
}
    
long long solve (long long n) {
    if(n <= 9) {
        return n+1;
    }
    
    vector<int> d; // n's digits
    long long n2 = n;
    while(n2) {
        d.push_back(n2%10);
        n2 /= 10;
    }   
    reverse(d.begin(), d.end());
    
    long long ans = 1;
    
    vector<vector<vector<long long> > > dp(20, vector<vector<long long> >(10, vector<long long> (3)));
    
    for (int i = 1; i < 10; i++) {
        dp[1][i][cmp(i, d[0])] = 1;
    }
    
    for (int i = 1; i < (int) d.size(); i++) {
        for (int curr = 0; curr < 10; curr++) {
            for (int state = 0; state < 3; state++) {
                for (int nxt = 0; nxt < 10; nxt++) {
                    if (curr == nxt) {
                        continue;
                    }
                    if (state == 2) {
                        dp[i+1][nxt][cmp(nxt, d[i])] += dp[i][curr][state];
                    }
                    else {
                        dp[i+1][nxt][state] += dp[i][curr][state];
                    }
                }
            }
        }
    }
    
    for (int i = 1; i <= (int) d.size(); i++) {
        for (int curr = 0; curr < 10; curr++) {
            for (int state = 0; state < 3; state++) {
                if (i < (int) d.size() || state != 1) {
                    ans = ans + dp[i][curr][state];
                }
            }
        }
    }
    
    return ans;
}
 
int main() {
    
    long long a, b;
    cin >> a >> b;
    
    cout << solve(b) - solve(a-1) << '\n'; // [a, b] = [0, b] - [0, a-1]
    
    return 0;
}
