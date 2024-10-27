/*
In the context of the problem, we only care about points where a trip begins, ends and 0. 

Now, for each function, we know we have two choices.

a -> b (I will note this distance with d)
a -> (x -> y) -> b, with (x -> y) having no cost and x is 0. (I will note (a -> x) distance with d2)

If the teleports are not placed optimally, you shouldn't use them. Otherwise, we need to think where to place the second teleporter to make the distance lower. Basically, you want it around b.

Let's note the difference between d and d2 with x. Starting from (b - x + 1) to b, the distance will decrease liniarly. From (b+1) to (b+x), the distance will increase liniarly. From (b+x+1),
it will no longer increase. 

These events will be stored in a map and then we will have to perform prefix sums to take in account the differences in delta.
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <map>

using namespace std;
 
int main() {
    
    ifstream cin("teleport.in");
    ofstream cout("teleport.out");
    
    int n;
    cin >> n;
    
    vector<pair<int, int>> arr(n+1);
    map<int, long long> slope;
    
    slope[0] = 0;
    
    long long total = 0;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i].first >> arr[i].second;
        if (slope.find(arr[i].first) == slope.end()) {
            slope[arr[i].first] = 0;
        }
        if (slope.find(arr[i].second) == slope.end()) {
            slope[arr[i].second] = 0;
        }
        int dist = abs(arr[i].first - arr[i].second);
        total += dist;
        int dist2 = abs(arr[i].first);
        if (dist2 < dist) {
            slope[arr[i].second - (dist - dist2) + 1]--; // distance decreases
            slope[arr[i].second + 1] += 2; // distance increases so we also have to cancel the decrease
            slope[arr[i].second + (dist - dist2) + 1]--; // distance becomes flat again
        }
    }
    long long ans = total;
    long long sumslopes = 0;
    long long delta = 0;
    int prv = -(1<<30);
    for (auto x : slope) {
        if (prv != -(1<<30)) {
            sumslopes += delta * (x.first - prv);
        }
        delta += x.second;
        prv = x.first;
        
        ans = min(ans, total + sumslopes);
    }
    
    cout << ans << '\n';
    return 0;
}
