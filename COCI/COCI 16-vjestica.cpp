/*
                COCI 16-vjestica

    * n is small, so we can run bitmask dp
    * given a subset of strings, we can choose to either put them together in a single root or split them into two groups,
we can implement this recursively and get the answer
    * thus, the complexity will be O(3^n), since we will iterate in every mask of every mask. in order to avoid TLE, 
one has to memorize the answer for a mask.

*/
#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

typedef long long ll;

int n, frq[30][30], dp[(1<<17)], viz[(1<<17)];
string s[20];
int prf(int msk)
{
    int mn[28];
    for(int i = 0; i <= 25; ++i)
        mn[i] = (1<<30);
    for(int i = 0; i < n; ++i)
    {
        if(msk & (1<<i))
            for(int j = 0; j <= 25; ++j)
                mn[j] = min(mn[j], frq[i][j]);
    }
    int ans = 0;
    for(int j = 0; j <= 25; ++j)
        ans += mn[j];
    return ans;
}
int solve(int i)
{
    if(viz[i])
        return dp[i];
    viz[i] = 1;
    int x = prf(i);
    vector<int>v;
    for(int j = 0; j < n; ++j)
        if(i & (1<<j))
            v.push_back(j);
    if(v.size() == 1)
    {
        dp[i] = x;
        return dp[i];
    }
    dp[i] = (1<<29);
    for(int j = i & (i-1); j; j = i & (j-1))
        dp[i] = min(dp[i], solve(j) + solve(i ^ j) - x);
    return dp[i];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; ++i)
    {
        cin >> s[i];
        for(int j = 0; j < s[i].size(); ++j)
            frq[i][s[i][j] - 'a']++;
    }
    cout << solve((1<<n) - 1) + 1 << '\n';
    return 0;
}
