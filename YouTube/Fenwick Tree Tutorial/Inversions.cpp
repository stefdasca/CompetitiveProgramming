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
 
int n, fen[100002];
 
void add(int nod)
{
	for(; nod <= n; nod += (nod & (-nod)))
		fen[nod]++;
}
 
int compute(int nod)
{
	int ans = 0;
	for(; nod; nod -= (nod & (-nod)))
		ans += fen[nod];
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
	{
		int val;
		cin >> val;
		cout << (i-1) - compute(val) << " ";
		add(val);
	}
	return 0;
}
