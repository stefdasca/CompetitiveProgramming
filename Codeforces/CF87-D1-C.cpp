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
 
int n, dp[100002];
int mini[100002];
int main()
{
 
    #ifdef fisier
        ifstream f("input.in");
        ofstream g("output.out");
    #endif
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
	int n;
	cin >> n;
	for(int i = 3; i <= n; ++i)
	{
		set<int> s;
		int plc0 = -1;
		for(int sp = 2; sp <= 1000; ++sp)
		{
			int dif = sp * (sp-1) / 2;
			if(i <= dif)
				break;
			if((i - dif) % sp == 0)
			{
				int xv = 0;
				for(int j = (i-dif) / sp; j <= (i-dif) / sp + sp - 1; ++j)
					xv ^= dp[j];
				if(!xv && plc0 == -1)
					plc0 = sp;
				s.insert(xv);
			}
		}
		while(s.find(dp[i]) != s.end())
			++dp[i];
		mini[i] = plc0;
	}
	cout << (dp[n] != 0 ? mini[n] : -1);
    return 0;
}
