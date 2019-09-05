/*
        NOI-Singapore 19-Feast

    * We can solve this problem using Aliens trick(there are plenty of tutorials online which describe aliens)

*/
#include<bits/stdc++.h>
#define fi first
#define se second
#pragma GCC optimize("O3")
using namespace std;

typedef long long ll;

int n, k, ct;
ll v[300002], prefix[300002], sol;

pair<ll, ll> dp[300002]; // max sum, number of subarrays

pair<ll, ll> opt(ll penalty)
{
	memset(dp, 0, sizeof(dp));
	pair<ll, ll> ms = {0, 0}; // the optimal pair so far
	for(int i = 0; i < n; ++i)
    {
        pair<ll, ll> cs = {dp[i].fi-prefix[i], dp[i].se}; // a new candidate pair, we create it based on the value of dp[i]
        if((cs.fi > ms.fi) || (cs.fi == ms.fi && cs.se < ms.se))
            ms = cs;
        pair<ll, ll> nd = {ms.fi - penalty + prefix[i+1], ms.se+1}; // a candidate pair for dp[i+1], we create it based on the optimal pair ms
        // dp[i+1] = max(dp[i], nd)
        dp[i+1] = dp[i];
        if((nd.fi > dp[i].fi) || (nd.fi == dp[i].fi && nd.se < dp[i].se))
            dp[i+1] = nd;
	}
	return dp[n];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;
    for(int i = 1; i <= n; ++i)
    {
        cin >> v[i];
        prefix[i] = prefix[i-1] + v[i];
    }
    // the binary search function necessary for aliens to work
    // we search for the optimal lambda, bigger lambda -> smaller number of arrays necessary
    ll lb = 0, rb = 3e14;
    while(lb < rb)
    {
        ll mid = (lb + rb) / 2;
        if(opt(mid).se <= k)
            rb = mid;
        else
            lb = mid + 1;
    }
    pair<ll, ll> ans = opt(lb);
    cout << ans.fi + k * lb << '\n';
    return 0;
}
