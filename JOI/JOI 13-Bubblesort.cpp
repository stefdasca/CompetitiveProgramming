/*
                    JOI 13-BubbleSort

	* Let's consider the array as a list of points on a plane, where point (i, p[i]) is the point representing
the ith number in the array.

    * It is obvious that it's never optimal to swap positions i and j if p[i] <= p[j], so we will stick only to
the opposite case(we swap positions i and j, such that if i < j, then p[i] > p[j]).

	* During one such swap, we will consider the rectangle with opposite endpoints (i, p[i]) and (j, p[j]), thus the total number of inversions saved
is (number of points strictly within the rectangle) + (number of points within or on the rectangle) - 1 (we can compute this using BIT, if we normalize
the numbers in array before - each number will become equal with its position in the sorted permutation)

	* For a position i, we can find a strictly increasing subset of candidates, so we can prove that if r < s,
then optimal value of j for r < optimal value of j for s, thus we can use divide and conquer DP to solve this problem
in O(n log^2 n).


*/
#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#define fi first
#define se second
#define pb push_back
#define pf push_front
#define mod 1000000007

using namespace std;

typedef long long ll;

int n, p[100005], b[100005], aib[100005];
long long ans;
vector<int> v;

void upd(int nod, int x)
{
    ++nod;
    for(; nod <= n; nod += (nod & (-nod)))
        aib[nod] += x;
}
int compute(int nod)
{
    int ans = 0;
    for(; nod; nod -= (nod & (-nod)))
        ans += aib[nod];
    return ans;
}
void divide(int st, int dr, int optst, int optdr)
{
	if(st > dr)
    {
		for(int i = optst; i <= optdr; ++i)
			upd(p[i], 1);
		return;
	}
	int m1 = (st + dr) / 2;
	pair<int, int> m2;
	m2.fi = m2.se = -1;
	for(int i = v[st]; i < v[m1]; ++i)
		upd(p[i], -1);
	for(int i = optst; i <= optdr; ++i)
    {
		upd(p[i], 1);
        pair<int, int> potentialmax = {compute(p[v[m1]]) + compute(p[v[m1]] + 1) - compute(p[i]) - compute(p[i] + 1), i};
		m2 = max(potentialmax, m2);
	}
	ans=min(1LL - m2.fi, ans);
	for(int i = v[st]; i < v[m1]; ++i)
		upd(p[i], 1);
	for(int i = optst; i <= optdr; ++i)
		upd(p[i], -1);
	divide(st, m1 - 1, optst, m2.se);
	for(int i = v[m1]; i < v[m1+1]; ++i)
		upd(p[i], -1);
	upd(p[m2.se], -1);
	divide(m1 + 1, dr, m2.se, optdr);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; ++i)
        cin >> p[i];
    bool equality = 0, sorted = 1;
    for(int i = 1; i < n; ++i)
        if(p[i] == p[i-1])
            equality = 1;
        else
            if(p[i] < p[i-1])
                sorted = 0;
    if(sorted)
    {
        cout << 1 - equality << '\n';
        return 0;
    }
    for(int i = 0; i < n; ++i)
        b[i] = p[i];
	sort(b, b + n);
	for(int i = 0; i < n; ++i)
    {
		p[i] = lower_bound(b , b + n, p[i]) - b;
		if(i == 0 || p[i] > p[v.back()])
			v.push_back(i);
	}
	v.push_back(n);
    divide(0, v.size() - 2, 0, n - 1);
	for(int i = n - 1; i >= 0; --i)
    {
		ans += compute(p[i]);
		upd(p[i], 1);
	}
	cout << ans << "\n";
    return 0;
}
