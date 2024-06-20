#include <bits/stdc++.h>
 
using namespace std;
 
const int mod = 998244353;
 
int pascal[1002][1002];
 
long long fact[100002], inv[100002];
 
long long pw(long long b, long long e)
{
	long long ans = 1;
 
	while(e)
	{
		if(e & 1)
			ans = (ans * b) % mod;
		b = (b * b) % mod;
		e >>= 1;
	}
 
	return ans;
}
 
long long C(int n, int k)
{
	long long ans = fact[n];
	ans *= inv[k];
	ans %= mod;
	ans *= inv[n-k];
	ans %= mod;
	return ans;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
 

  // generating permutations
	vector<int> v;
 
	for(int i = 1; i <= 10; i++)
		v.push_back(i);
  
	do{
		// 
	}while(next_permutation(v.begin(), v.end()));
   

  // computing n choose k using pascal's triangle
	pascal[0][0] = 1;
 
	for(int i = 1; i <= 1000; i++)
	{
		pascal[i][0] = 1;
		for(int j = 1; j <= i; j++)
		{ 
			// comb(i, j) = comb(i-1, j) + comb(i-1, j-1)
			pascal[i][j] = pascal[i-1][j] + pascal[i-1][j-1];
		}
	}
 
	// C(n, k) - we can compute factorials and modular inverses
 
	// C(n, k) = C(n, n-k)
 
	// modular inverse = x^(-1) which for prime mod is x^(mod-2) according to Fermat's little theorem
 
	fact[0] = 1;
 
	for(int i = 1; i <= 100000; i++)
		fact[i] = (fact[i-1] * i) % mod;
 
	inv[0] = 1;
 
	for(int i = 1; i <= 100000; i++)
	{
		inv[i] = pw(fact[i], mod-2);
	}
 
	int n, k;
	cin >> n >> k;
 
	cout << C(n, k);

    // finding all subsets of a set of n values
  
	for(int i = 0; i < (1<<n); i++)
	{
		for(int j = 0; j < n; j++)	
			if(i & (1<<j))
			{
				// 
			}
	}
	return 0;
}
