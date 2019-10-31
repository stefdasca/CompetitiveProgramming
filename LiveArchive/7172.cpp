/*
                LiveArchive 7172

    * For each edge (u, v, v is a child of u), if we visit x nodes in the subtree of v, so there are k - x nodes outside of the subtree to visit,
therefore, we would use edge min(x, k-x) * 2 times.

    * Let dp[u][K] is the maximum length of journey if we choose K nodes in the subtree of u, so we need to find dp[1][k]. Using a recursive algorithm,
we will reconstruct the tree.

    - For each u and K, we have the following cases, based on whether u has left child and/or sibling:

     1. u doesn't have left child or sibling => u is a leaf and it has no siblings => K is for u

     2. u only has left child => K is for subtree of u, we can choose u and pass K-1 to the child or pass all K to child

     3. u only has sibling => 0 or 1 of K is for u (because u is a leaf), remaining thing is for v

     4. u has both left child and sibling => part of K is for subtree of u, remaining thing is for v

     Even though the runtime of the algorithm seems to be O(t * n * k^2), in practice it's working much faster because not every node
fits in the condition 4.

*/
#include<bits/stdc++.h>
#define god dimasi5eks
#pragma GCC optimize("O3")
#define fi first
#define se second
#define pb push_back
#define pf push_front
#define mod 1000000007

using namespace std;

typedef long long ll;

int t, n, k, leftChild[1002], sibling[1002], num[1002], num2[1002];
pair<int, int> par[1002];
ll dp[1002][102];
vector<pair<int, int> >v[1002];
void dfs(int dad, int nod)
{
    num[nod] = 1;
    int pre = -1;
    for(int i = 0; i < v[nod].size(); ++i)
    {
        int vecin = v[nod][i].fi;
        int cost = v[nod][i].se;
        if(vecin != dad)
        {
            if(pre == -1)
                leftChild[nod] = vecin;
            else
                sibling[pre] = vecin;
            pre = vecin;
            par[vecin] = {nod, cost};
            dfs(nod, vecin);
            num[nod] += num[vecin];
        }
    }
}
void dfs2(int nod)
{
    num2[nod] = 1;
    if(leftChild[nod] != -1)
    {
        dfs2(leftChild[nod]);
        num2[nod] += num2[leftChild[nod]];
    }
    if(sibling[nod] != -1)
    {
        dfs2(sibling[nod]);
        num2[nod] += num2[sibling[nod]];
    }
}
ll solve(int nod, int K)
{
    if(K < 0)
        return -1e15;
    if(K == 0)
        return 0;
    if(num2[nod] < K)
        return -1e15;
    if(dp[nod][K] != -1)
        return dp[nod][K];

    ll ans = 0;

    if(leftChild[nod] == -1 && sibling[nod] == -1)
    {
        ll e = 0;
        if(par[nod].fi)
            e = 1LL * par[nod].se * min(K, k - K + 1) * 2;
        ans = e;
    }

    if(leftChild[nod] != -1 && sibling[nod] == -1)
    {
        int vec = leftChild[nod];
        int remain = n - num[nod];
        ll e = 0;
        if(par[nod].fi && remain >= k - K + 1)
            e = 1LL * par[nod].se * min(K, k - K + 1) * 2;
        if(nod == 1)
            ans = solve(vec, K) + e;
        else
            ans = max(solve(vec, K), solve(vec, K-1)) + e;
    }

    if (leftChild[nod] == -1 && sibling[nod] != -1)
    {
        int vec = sibling[nod];
        int remain = n - num[nod];

        for(int i = 0; i <= 1; ++i)
        {
            ll e = 0;
            if(par[nod].fi && remain >= k - i + 1)
                e = 1LL * par[nod].se * min(i, k - i + 1) * 2;
            ans = max(ans, solve(vec, K - i) + e);
        }
    }

    if(leftChild[nod] != -1 && sibling[nod] != -1)
    {
        int p = leftChild[nod];
        int vec = sibling[nod];
        int remain = n - num[nod];
        for(int i = 0; i <= K; ++i)
        {
            ll e = 0;
            if(par[nod].fi && remain >= k - i + 1)
                e = 1LL * par[nod].se * min(i, k - i + 1) * 2;
            ans = max(ans, max(solve(p, i), solve(p, i-1)) + solve(vec, K - i) + e);
        }
    }
    return dp[nod][K] = ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    for(int x = 1; x <= t; ++x)
    {
        cin >> n >> k;
        for(int i = 1; i <= n; ++i)
        {
            v[i].clear();
            leftChild[i] = sibling[i] = -1;
        }
        for(int i = 2; i <= n; ++i)
        {
            int a, b;
            cin >> a >> b;
            v[i].pb({a, b});
            v[a].pb({i, b});
        }
        dfs(0, 1);
        dfs2(1);
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= k; ++j)
                dp[i][j] = -1;
        cout << "Case " << x << ": " << solve(1, k) << '\n';
    }
    return 0;
}

