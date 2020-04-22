#include<bits/stdc++.h>
#define god dimasi5eks
#pragma GCC optimize("O3")
#define fi first
#define se second
#define pb push_back
#define pf push_front

/// #define fisier 1

using namespace std;

typedef long long ll;

const int mod = 1000000007;
const double dancila = 3.14159265359; // PI
const double eps = 1e-9;


int combi[202][202];

int add(int a, int b)
{
	a += b;
	if(a >= mod)
		a -= mod;
	if(a < 0)
		a += mod;
	return a;
}
int main()
{

    #ifdef fisier
        ifstream cin("piruete.in");
        ofstream cout("piruete.out");
    #endif

	combi[0][0] = 1;
	for(int i = 1; i <= 200; ++i)
	{
		combi[i][0] = 1;
		for(int j = 1; j <= i; ++j)
			combi[i][j] = add(combi[i-1][j-1], combi[i-1][j]);
	}
	int t, n, k;
	cin >> t >> n >> k;
	t /= 2;
	int dp[t+2][2][2][n+2][n+2];
	int sp[t+2][2][n+2][n+2];
	memset(dp, 0, sizeof(dp));
	memset(sp, 0, sizeof(sp));
	dp[0][0][0][0][0] = 1;
	int ans = 0;
	int mtp = 0;
	for(int kk = 0; kk <= k; ++kk)
	{
		int mt = t;
        for(int dt = mtp; dt < t; ++dt)
			for(int lo = 0; lo <= n+1; ++lo)
				for(int ro = 0; ro <= n+1; ++ro)
				{
					if(dp[dt][0][0][lo][ro])
					{
						mt = min(mt, dt + (ro+1));
						if(ro < n)
						{
							if(dt + (ro+1) <= t)
								sp[dt + (ro+1)][1][lo][(ro+1)] = add(sp[dt + (ro+1)][1][lo][(ro+1)], dp[dt][0][0][lo][ro]);
						}
						if(dt + (n+1) <= t)
							dp[dt + (n+1)][0][1][lo][n+1] = add(dp[dt + (n+1)][0][1][lo][n+1], dp[dt][0][0][lo][ro]);
					}
					if(dp[dt][0][1][lo][ro])
					{
						mt = min(mt, dt + (lo+1));
						if(lo < n)
						{
							if(dt + (lo+1) <= t)
								sp[dt + (lo + 1)][0][lo+1][ro] = add(sp[dt + (lo + 1)][0][lo+1][ro], dp[dt][0][1][lo][ro]);
						}
						if(dt + (n+1) <= t)
							dp[dt + (n+1)][0][0][n+1][ro] = add(dp[dt + (n+1)][0][0][n+1][ro], dp[dt][0][1][lo][ro]);
					}
				}
		for(int tt = mt; tt <= t; tt++)
			for(int st = 0; st <= n+1; ++st)
				for(int dr = 0; dr <= n+1; ++dr)
				{
					if(tt >= 1 && st > 0)
						sp[tt][0][st][dr] = add(sp[tt][0][st][dr], sp[tt-1][0][st-1][dr]);
					if(st != n+1)
						dp[tt][1][0][st][dr] = add(dp[tt][1][0][st][dr], sp[tt][0][st][dr]);
					if(tt >= 1 && dr > 0)
						sp[tt][1][st][dr] = add(sp[tt][1][st][dr], sp[tt-1][1][st][dr-1]);
					if(dr != n+1)
						dp[tt][1][1][st][dr] = add(dp[tt][1][1][st][dr], sp[tt][1][st][dr]);
				}
		for(int i = 0; i <= n+1; ++i)
			for(int j = 0; j <= n+1; ++j)
			{
				ll ta = (dp[t][0][0][i][j] + dp[t][0][1][i][j]);
				if(!ta)
					continue;
				int fresp = max(0, n - i) + max(0, n - j);
				if(kk + fresp >= k)
				{
					ta = ta * combi[fresp][k - kk];
					ta %= mod;
					ans = add(ans, (int) ta);
				}
			}
		for(int i = mt; i <= t; ++i)
		{
			memset(sp[i], 0, sizeof(sp[i]));
			memcpy(dp[i][0], dp[i][1], sizeof(dp[i][1]));
			memset(dp[i][1], 0, sizeof(dp[i][1]));
		}
		mtp = mt;
	}
	cout << ans;
    return 0;
}
