/*
  For each value from 1 to n we will only care at some point about its most recent occurence. At a given position, we will basically want to count the number of distinct values we had so far between positions prev[i] and i.

  This can easily be done using fenwick tree or segment tree.
*/

#include <bits/stdc++.h>
using namespace std;

int n, v[200002], fenwick[200002], lst[200002];

void add(int node, int val)
{
    for(; node <= n; node += (node & (-node)))
        fenwick[node] += val;
}
int compute(int node)
{
    int ans = 0;
    for(; node; node -= (node & (-node)))
        ans += fenwick[node];
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> v[i];
    
    long long ans = 0;
    for(int i = 1; i <= n; i++)
    {
        if(lst[v[i]])
            add(lst[v[i]], -1);
        ans += compute(i) - compute(lst[v[i]]);
        add(i, 1);
        lst[v[i]] = i;
    }
    
    cout << ans << '\n';
    return 0;
}
