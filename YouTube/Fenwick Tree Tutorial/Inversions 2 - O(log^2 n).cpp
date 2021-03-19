#include<bits/stdc++.h>
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
 
ll n, v[200002], fenwick[200002];
 
void add(int node, ll val) 
{
	for(; node <= n; node += (node & (-node)))
		fenwick[node] += val;
}
 
ll query(int node)
{
	ll ans = 0;
	for(; node; node -= (node & (-node)))
		ans += fenwick[node];
	return ans;
}
 
int sol[200002];
 
 
int solve(int poz, int cnt)
{
	int L = 1;
	int R = n;
	int ans = 0;
	while(L <= R)
	{
		int mid = (L + R) / 2;
		int val = poz - query(mid - 1);
		if(val >= cnt)
			ans = mid, L = mid + 1;
		else
			R = mid - 1;
	}
	return ans;
}
int main()
{
	#ifdef fisier
		ifstream cin("input.in");
		ofstream cout("output.out");
	#endif
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> v[i];
	for(int i = 1; i <= n; ++i)
		add(i, 1);
	for(int i = n; i >= 1; --i)
	{
		sol[i] = solve(i, v[i] + 1);
		add(sol[i], -1);
	}
	for(int i = 1; i <= n; ++i)
		cout << sol[i] << " ";
	return 0;
}
