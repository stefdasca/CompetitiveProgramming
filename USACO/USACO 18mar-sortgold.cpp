/*
            USACO 18mar-sortgold

    Keep the sorted array in both another array and a set, and at each step
use a binary indexed tree to answer to the query: how many elements left of i are not bigger
than v[i], thus the answer being the maximal value from these queries.

*/

#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#define fi first
#define se second
#define pb push_back
#define pf push_front
#define mod 1000000007

using namespace std;

ifstream f("sort.in");
ofstream g("sort.out");

int n, v[100002], sorted[100002], aib[100002];
set<pair<int, int> >s;
void update(int poz)
{
    for(; poz <= n; poz += poz & (-poz))
        aib[poz]++;
}
int compute(int poz)
{
    int ans = 0;
    for(; poz; poz -= (poz & (-poz)))
        ans += aib[poz];
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    f >> n;
    for(int i = 1; i <= n; ++i)
        f >> v[i], sorted[i] = v[i], s.insert({v[i], i});
    sort(sorted + 1, sorted + n + 1);
    int countmoo = 1;
    for(int i = 1; i < n; ++i)
    {
        update((*s.begin()).second);
        countmoo = max(countmoo, i - compute(i));
        s.erase(s.begin());
    }
    g << countmoo;
    return 0;
}

