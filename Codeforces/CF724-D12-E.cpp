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

ll n, c;
ll p[10002], s[10002];
ll dp[2][10002];
int main()
{
	#ifdef fisier
		ifstream cin("input.in");
		ofstream cout("output.out");
	#endif
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n >> c;
	for(int i = 1; i <= n; ++i)
		cin >> p[i];
	for(int i = 1; i <= n; ++i)
		cin >> s[i];
	ll ans = 0;
	for(int i = 1; i <= n; ++i)
	{
		for(int j = 0; j <= n; ++j)
		{
			if(j == 0)
				dp[1][j] = p[i] + dp[0][j];
			else
				dp[1][j] = min(dp[0][j-1] + s[i], dp[0][j] + p[i] + c * j);
		}
		memcpy(dp[0], dp[1], sizeof(dp[1]));
		memset(dp[1], 0, sizeof(dp[1]));
	}
	ans = dp[0][0];
	for(int j = 1; j <= n; ++j)
		ans = min(ans, dp[0][j]);
	cout << ans;
	return 0;
}
