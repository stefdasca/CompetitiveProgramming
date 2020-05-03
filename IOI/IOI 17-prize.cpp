#include<bits/stdc++.h>
#include "prize.h"
#define god dimasi5eks
#pragma GCC optimize("O3")
#define fi first
#define se second
#define pb push_back
#define pf push_front
 
// #define fisier 1
 
using namespace std;
 
typedef long long ll;
 
const int mod = 1000000007;
const double dancila = 3.14159265359; // PI 
const double eps = 1e-9;
 
int ans;
map<int, pair<int, int> > m[200002];
pair<int, int> qu(int x)
{
	vector<int> v = ask(x);
	return {v[0], v[1]};
}
 
void solve(int st, int dr)
{
	if(ans != -1 || st > dr)
		return;
 
	int mid = (st + dr) / 2;
	pair<int, int> cur = qu(mid);
	int sum = cur.fi + cur.se;
	if(sum == 0)
	{
		ans = mid;
		return;
	}
	
	auto it = m[sum].upper_bound(mid);
	bool L = 1, R = 1;
	if(it != m[sum].begin())
	{
		it--;
		if(cur.se == it -> se.se)
			L = 0;
		it++;
	}
	if(it != m[sum].end())
	{
		if(cur.se == it -> se.se)
			R = 0;
	}
	m[sum][mid] = cur;
	if(L)
		solve(st, mid - 1);
	if(R)
		solve(mid + 1, dr);
}
 
int find_best(int n)
{
	ans = -1;
	solve(0, n - 1);
	return ans;
}
