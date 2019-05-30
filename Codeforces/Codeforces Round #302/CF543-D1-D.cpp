#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#define mod 1000000007
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
long long rand_seed()
{
	long long a = rng();
    return a;
}
int n;
long long pw(long long b, int e)
{
    long long sol = 1;
    while(e)
    {
        if(e & 1)
            sol = (sol * b) % mod;
        b = (b * b) % mod;
        e >>= 1;
    }
    return sol;
}
vector<int>v[200002];
long long dp[3][200002];
long long ans[200002];
void dfs(int nod)
{
    dp[0][nod] = 1;
    dp[1][nod] = 1;
    if(!v[nod].size())
        return;
    for(int i = 0; i < v[nod].size(); ++i)
    {
        int vecin = v[nod][i];
        dfs(vecin);
        long long aa = (dp[0][vecin] + dp[1][vecin]) % mod;
        dp[1][nod] = (dp[1][nod] * aa) % mod;
    }
}
void dfs2(int nod, long long prod)
{
    ans[nod] = (prod * dp[1][nod]) % mod;
    long long prd = 1;
    deque<long long>pre;
    deque<long long>suf;
    pre.push_back(1);
    for(int i = 0; i < v[nod].size(); ++i)
    {
        int vecin = v[nod][i];
        long long aa = (dp[0][vecin] + dp[1][vecin]) % mod;
        prd = (prd * aa) % mod;
        pre.push_back(prd);
    }
    suf.push_back(1);
    prd = 1;
    for(int i = v[nod].size() - 1; i >= 0; --i)
    {
        int vecin = v[nod][i];
        long long aa = (dp[0][vecin] + dp[1][vecin]) % mod;
        prd = (prd * aa) % mod;
        suf.push_front(prd);
    }
    for(int i = 0; i < v[nod].size(); ++i)
    {
        int vecin = v[nod][i];
        long long nww = (pre[i] * suf[i+1]) % mod;
        dfs2(vecin, (prod * nww + 1) % mod);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 2; i <= n; ++i)
    {
        int x;
        cin >> x;
        v[x].push_back(i);
    }
    dfs(1);
    dfs2(1, 1);
    for(int i = 1; i <= n; ++i)
        cout << ans[i] << " ";
    return 0;
}
