#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#define mod 1000000007
using namespace std;
int n, x;
int cnt[102];
long long dp[1002];
long long v[102], mat[102][102];
void multMatrixMatrix(long long a[102][102], long long b[102][102])
{
	long long ans[102][102];
	for(int i = 1; i < 102; i++)
		for(int j = 1; j < 102; j++)
		{
			ans[i][j] = 0;
			for(int k = 1; k < 102; k++)
            {
				ans[i][j] += a[i][k] * b[k][j];
                ans[i][j] %= mod;
            }
		}
	for(int i = 1; i < 102; i++)
		for(int j = 1; j < 102; j++)
			a[i][j] = ans[i][j];
}
void lgput(long long base[102][102], int Exponent)
{
	long long copie[102][102];
	for(int i = 1; i < 102; i++)
		for(int j = 1; j < 102; j++)
        {
			copie[i][j] = base[i][j];
			if(i == j)
                base[i][j] = 1;
            else
                base[i][j] = 0;
        }
	while(Exponent)
	{
		if(Exponent & 1)
			multMatrixMatrix(base, copie);
		multMatrixMatrix(copie, copie);
		Exponent >>= 1;
	}
}
void multVectorMatrix(long long a[102], long long b[102][102])
{
	long long ans[102];
	for(int i = 1; i < 102; i++)
	{
		ans[i] = 0;
		for(int j = 1; j < 102; j++)
        {
			ans[i] += b[j][i] * a[j];
            ans[i] %= mod;
        }
	}
	cout << ans[101] << '\n';
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> x;
    for(int i = 1; i <= n; ++i)
    {
        int xx;
        cin >> xx;
        cnt[xx]++;
    }
    dp[0] = 1;
    for(int i = 0; i <= 99; ++i)
        for(int j = i+1; j <= i + 100; ++j)
            dp[j] = (dp[j] + dp[i] * cnt[j - i]) % mod;
    long long s = 0;
    for(int j = 0; j <= 100; ++j)
        s = (s + dp[j]) % mod;
    if(x <= 100)
    {
        s = 0;
        for(int j = 0; j <= x; ++j)
            s = (s + dp[j]) % mod;
        cout << s;
        return 0;
    }
    for(int i = 1; i <= 100; ++i)
        v[i] = dp[i];
    v[101] = s;
    for(int i = 1; i <= 100; ++i)
        mat[i][100] = mat[i][101] = cnt[100 - i + 1];
    mat[101][101] = 1;
    for(int i = 2; i <= 100; ++i)
        mat[i][i-1] = 1;
    lgput(mat, x - 100);
    multVectorMatrix(v, mat);
    return 0;
}
