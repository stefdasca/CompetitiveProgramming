/*

            HackerRank billboards

    Instead of finding what ranges to take, find what should you remove.

    This can be solved quite easily using deque and sliding window.

*/
#include<bits/stdc++.h>
#define god dimasi5eks
#pragma GCC optimize("O3")
#define fi first
#define se second
#define pb push_back
#define pf push_front
#define mod 1000000007
#define dancila 3.14159265359
#define eps 1e-9

using namespace std;

typedef long long ll;

ll dp[100002], v[100002];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    for(int i = 1; i <= n; ++i)
        cin >> v[i];
    ++k;
    ll sum = 0;
    deque<int> d;
    ll mnn = (1LL<<60);
    if(k == n+1)
        mnn = 0;
    for(int i = 1; i <= n; ++i)
    {
        if(!d.empty() && d.front() == i - k - 1)
            d.pop_front();
        sum += v[i];
        if(i <= k)
            dp[i] = v[i];
        else
            dp[i] = v[i] + dp[d.front()];
        while(!d.empty() && dp[i] <= dp[d.back()])
            d.pop_back();
        d.push_back(i);
        if(i + k > n)
            mnn = min(mnn, dp[i]);
    }
    cout << sum - mnn;
    return 0;
}
