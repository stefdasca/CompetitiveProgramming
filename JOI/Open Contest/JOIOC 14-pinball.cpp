/*
		JOIOC 14-pinball

	Firstly, let's normalize the pins in order to reduce the required memory and time. 
	
	It can be observed that if the pins don't touch 1 or n, we don't have a solution for the problem,
so we are going to solve the problem twice
	Now, we can use DP to solve this problem twice, once for each end of the board, and we are going to combine the answers
to get the solution.

	dp[i] = min answer if we consider only the pins from 1 to i
		* dp[i] = d[i] if the pin touches 1
				= min(inf, d[i] + query(a[i], b[i])) otherwise, where in query(a, b) we find the min value among
				the pins which have the hole in range [a[i], b[i]]
	
	The problem is solved in a similar fashion for the other end, and the overall complexity will be O(m log m).

*/
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
 
 
int n, m;
int a[100002], b[100002], c[100002], d[100002];
bool lc[100002], rc[100002];
 
ll aint[400002], dp[2][100002];
void update(int nod, int st, int dr, int poz, ll val)
{
	if(st == dr)
	{
		aint[nod] = min(aint[nod], val);
		return;
	}
	int mid = (st + dr) / 2;
	if(poz <= mid)
		update(nod << 1, st, mid, poz, val);
	else
		update(nod << 1|1, mid+1, dr, poz, val);
	aint[nod] = min(aint[nod << 1], aint[nod << 1|1]);
}
ll query(int nod, int st, int dr, int L, int R)
{
	if(dr < L || st > R)
		return (1LL<<60);
	if(L <= st && dr <= R)
		return aint[nod];
	int mid = (st + dr) / 2;
	return min(query(nod << 1, st, mid, L, R), query(nod << 1|1, mid+1, dr, L, R));
}
int main()
{
 
    #ifdef fisier
        ifstream f("input.in");
        ofstream g("output.out");
    #endif
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
	cin >> m >> n;
	set<int> dist;
	for(int i = 1; i <= m; ++i)
	{
		cin >> a[i] >> b[i] >> c[i] >> d[i];
		if(a[i] == 1)
			lc[i] = 1;
		if(b[i] == n)
			rc[i] = 1;
		dist.insert(c[i]);
	}
	
	map<int, int> tpoz;
    int p = 0;
    for (int i : dist)
        tpoz[i] = ++p;
    n = 0;
    for(int i = 1; i <= m; ++i)
    {
        a[i] = (*tpoz.lower_bound(a[i])).se;
        auto it = tpoz.upper_bound(b[i]);
        it--;
        b[i] = (*it).se;
        c[i] = tpoz[c[i]];
        n = max(n, b[i]);
    }
    for(int i = 0; i <= 1; ++i)
    {
		for(int nod = 1; nod <= 4*n; ++nod)
		    aint[nod] = (1LL<<60);
		for(int j = 1; j <= m; ++j)
		{
		    if((i == 0 && lc[j]) || (i == 1 && rc[j]))
		 	    dp[i][j] = d[j];
			else
			    dp[i][j] = min((1LL<<60), query(1, 1, n, a[j], b[j]) + d[j]);
			update(1, 1, n, c[j], dp[i][j]);
	    }
	}
	
	ll ans = (1LL<<60);
	for(int i = 1; i <= m; ++i)
		ans = min(ans, dp[0][i] + dp[1][i] - d[i]);
	if(ans == (1LL<<60))
		cout << -1;
	else
		cout << ans;
    return 0;
}
