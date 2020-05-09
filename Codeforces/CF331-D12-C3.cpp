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

map<pair<ll, int>, pair<ll, int> > mp;

pair<ll, int> solve(ll n, int mx)
{
	if(n == 0) 
		return {0, 0};
	if(n < 10) 
	{
		pair<ll, int> ans = {1, 0};
		if(n < mx) 
			ans.se = (mx-n);
		return ans;
	}
	pair<ll, int> state = {n, mx};
	if(mp.find(state) != mp.end()) 
		return mp[state];
	long long step = 1;
	while(step <= n/10) 
		step *= 10;
	pair<ll, int> ans = make_pair(0, 0);
    while(1) 
    {
		int cf = n/step;
		int newmx = mx;
		if(cf > newmx) 
			newmx = cf;
		pair<ll, int> cur = solve(n % step, newmx);
		ans.fi += cur.fi;
		n -= n % step;
		if(cur.se > 0)
			n -= cur.se; 
		else 
		{
			n -= newmx;
			if(newmx > 0) 
				ans.fi++;
		}
		if(cf == 0)
			break;
	}
	ans.second = -n;
	mp[state] = ans;
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

	long long n;
	cin >> n;
	pair<long long, int> result = solve(n, 0);
	cout << result.first << '\n';
    return 0;
}
