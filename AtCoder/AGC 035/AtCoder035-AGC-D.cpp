/*
            AtCoder035-AGC-D

    * Let's reverse the problem(start from the first and the last stack, and add stacks until you get the n stacks).

    * Thus, we can compute dp[i][j][ki][kj] = min(dp[i][p][ki][ki+kj] + dp[p][j][ki+kj][kj] + v[p] * (ki+kj)), where i < k < j.
dp[i][j][ki][kj] being the minimal possible sum we can obtain if we didn't have any elements between i and j, and the contributions of positions
i and j to the sum are ki and kj.

    * When we are going to add an element between i and j in this current version of the problem, its contribution to the sum
will be the sum of ki and kj, because it's equivalent to the remove move from the original version of our problem.

    * In order to get AC, one has to use maps to store the DP matrix, since the number of possible pairs of type(ki, kj) is at most 2^n,
which is good enough for AC.

*/
#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#define fi first
#define se second
#define pb push_back
#define pf push_front
#define mod 1000000007

using namespace std;
typedef long long ll;

ll n, v[20];

map<pair<ll, ll>, ll> mp[20][20];
ll solve(ll st, ll dr, ll xst, ll xdr)
{
    if(dr - st == 1)
        return 0;
    if(mp[st][dr].find({xst, xdr}) != mp[st][dr].end())
        return mp[st][dr][{xst, xdr}];
    ll ans = (1LL<<62);
    for(int i = st + 1; i < dr; ++i)
        ans = min(ans, solve(st, i, xst, xst+xdr) + solve(i, dr, xst+xdr, xdr) + v[i] * (xst+xdr));
    mp[st][dr][{xst, xdr}] = ans;
    return mp[st][dr][{xst, xdr}];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; ++i)
        cin >> v[i];
    cout << solve(0, n-1, 1, 1) + v[0] + v[n-1] << '\n';
    return 0;
}
