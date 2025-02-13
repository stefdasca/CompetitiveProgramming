## Brute force ideas

A slow but obvious solution consists of iterating for each query through the entire array and add 1 to the answer for every farm which closes down after Bessie decides to visit it. However, this won't work for the larger test cases as the complexity would be $O(n \cdot q)$.

## A step forward using frequency arrays

The second subtask suggests a potential solution which relies on grouping values that behave the same (there are only $400$ distinct combinations). Thus, we can store a frequency array for each of these combinations and reduce the runtime significantly, which allows us to get this subtask.

## Full solution 1 - precomputing all queries

For a given position $i$, Bessie can visit it if she wakes up before time $c_i - t_i$. Therefore, we know that the range of possible valid times is $[0, c_i - t_i - 1]$. With this information in mind, we can count the number of farms she can visit if she wakes up at time 0, while keeping track using an array of the times when she will no longer be able to visit certain farms.

After that, we can have a single traversal from 0 to $10^6$ to calculate the answers for all possible timings using a cummulative sum and then for each query, all we have to do is to check whether the number of farms Bessie can visit is at least equal to the parameter from the input, printing YES or NO depending on the case.

The total complexity of this algorithm is $O(MAX + n + q)$, where $MAX$ is the highest possible time in the input.

## Full solution 2 - binary search

We will again precompute the values $c_i - t_i$ and sort this array. Now, for a given query, all we want to do is to binary search the smallest value in the array larger than $S$ and count how many such positions are there.

Given that we have a sorting which takes $O(n \log \ n)$ and we use $O(\log \ n)$ operations per query, this solution should also be fast enough.

## Source codes

The source codes in C++ and Python can be seen below, both use the idea from solution 1.

```cpp
#include <iostream>
using namespace std;

int c[200002], t[200002], fr[1000002], ps[1000002];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, q;
    cin >> n >> q;
    
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
    }
    
    for (int i = 1; i <= n; i++) {
        cin >> t[i];
        if (c[i] - t[i] - 1 >= 0) {
            ps[0]++, fr[c[i] - t[i]]--; // we cover range [0, c[i] - t[i] - 1]
        }
    }
    
    for (int i = 1; i <= 1000000; i++) { // creating cummulative sums
        ps[i] = ps[i-1] + fr[i];
    }
    
    for (int i = 1; i <= q; i++) {
        int v, s;
        cin >> v >> s;
        if (ps[s] >= v) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
    return 0;
}
```

```py
n, q = map(int, input().split())
c = list(map(int, input().split()))
t = list(map(int, input().split()))

times = [0] * 1000001

cnt = 0
for i in range(n):
    if c[i] - t[i] > 0:
       times[c[i] - t[i]] -= 1 # Bessie can no longer visit the farm if she wakes up too late
       cnt += 1

times[0] = cnt # how many farms can Bessie visit if she wakes up at 0
for i in range (1, 1000001):
    times[i] = times[i] + times[i-1]
  
for i in range (q):
    v, s = map(int, input().split())
    if times[s] >= v:
        print("YES")
    else:
        print("NO")
```
