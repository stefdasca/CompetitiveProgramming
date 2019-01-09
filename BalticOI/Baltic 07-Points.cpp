/*
                Baltic 07-Points

    After doing some paperwork, one can find the recurrence relation which can be
transformed into a matrix. Since n can be up to 10^9, one needs to do exponentiation
in logarithmic time

*/

#include<bits/stdc++.h>
#define mod 1000000000
using namespace std;
int N;
long long M[6][6] =
{
	1,1,1, 1,0,0,
	2,2,2, 0,1,0,
	1,1,1, 0,0,1,

	1,1,1, 0,0,0,
	2,2,2, 0,0,0,
	1,1,1, 0,0,0
};

long long vstart[6] =
{
	0, 1, 0, 0, 2, 0
};

long long vend[6] =
{
	1, 1, 1, 1, 0, 1
};

void multMatrixVector(long long a[6][6], long long b[6])
{
	long long ans[6];
	for(int i = 0; i < 6; i++)
	{
		ans[i] = 0;
		for(int j = 0; j < 6; j++)
			ans[i] += a[i][j] * b[j];
		ans[i] %= mod;
	}
	for(int i = 0; i < 6; i++)
		b[i] = ans[i];
}
void multMatrixMatrix(long long a[6][6], long long b[6][6])
{
	long long ans[6][6];
	for(int i = 0; i < 6; i++)
		for(int j = 0; j < 6; j++)
		{
			ans[i][j] = 0;
			for(int k = 0; k < 6; k++)
				ans[i][j] += a[i][k] * b[k][j];
			ans[i][j] %= mod;
		}
	for(int i = 0; i < 6; i++)
		for(int j = 0; j < 6; j++)
			a[i][j] = ans[i][j];
}
long long multVectorVector(long long a[6], long long b[6])
{
	long long ans = 0;
	for(int i = 0; i < 6; i++)
		ans += a[i] * b[i];
	ans %= mod;
	return ans;
}
void lgput(long long base[6][6], int Exponent)
{
	long long copie[6][6];
	for(int i = 0; i < 6; i++)
		for(int j = 0; j < 6; j++)
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
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
	lgput(M, N - 2);
	multMatrixVector(M, vstart);
    cout << multVectorVector(vend, vstart);
	return 0;
}
