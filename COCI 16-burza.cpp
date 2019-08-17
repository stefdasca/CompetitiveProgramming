/*
        COCI 16-burza

    * If k^2 >= n, the answer is DA.

    * Otherwise, let's define a bitmask dp, dp[i][mask] = 1 if we can cover the first i leaves using nodes forming that mask.
(leave = node at height k). In order to compute the transitions easier, we are going to do a dfs to find the dfs order of the tree
(left_i = leftmost leaf in subtree of i, right_i = rightmost leaf in subtree of i)

    * From this point on, the transition is pretty simple, for every starting left point, we're going to update the dp matrix according to
the previous states.

    * Let's say we want to go to cover the next leaves and we are at position i and mask j. From dp[i][j] we can go to all dp[right_x][j + 2^level_x],
where level_x is the level of node x.

    * If we found that we can cover all the leaves using some bitmask, the answer is DA. Otherwise, it's NE.


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


int add(int a, int b)
{
    ll x = a+b;
    if(x >= mod)
        x -= mod;
    if(x < 0)
        x += mod;
    return x;
}
ll mul(ll a, ll b)
{
    return (a*b) % mod;
}

ll pw(ll a, ll b)
{
    ll ans = 1;
    while(b)
    {
        if(b & 1)
            ans = (ans * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return ans;
}
vector<int>v[402], q[402];
int n, k, level[402], st[402], dr[402], pz;
void dfs(int dad, int nod)
{
    if(nod)
        level[nod] = level[dad] + 1;
    if(level[nod] == k-1)
    {
        st[nod] = pz++;
        dr[nod] = pz;
        return;
    }
    st[nod] = pz;
    for(int i = 0; i < v[nod].size(); ++i)
    {
        int vecin = v[nod][i];
        if(vecin == dad)
            continue;
        dfs(nod, vecin);
    }
    dr[nod] = pz;
}
bool dp[402][(1<<20)];
bool solve()
{
    dp[0][0] = 1;
    for(int i = 1; i < n; ++i)
        q[st[i]].push_back(i);

    for(int i = 0; i < pz; ++i)
    {
        for(int j = 0; j < (1<<k); ++j)
        {
            if (!dp[i][j])
                continue;
            for(int jj = 0; jj < q[i].size(); ++jj)
            {
                int it = q[i][jj];
                if (!(j >> level[it] & 1))
                    dp[dr[it]][j | (1<<level[it])] = 1;
            }
        }
    }
    for(int j = 0; j < (1<<k); ++j)
        if (dp[pz][j])
            return 1;

    return 0;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;
    if(k * k >= n)
    {
        cout << "DA\n";
        return 0;
    }
    for(int i = 1; i < n; ++i)
    {
        int a, b;
        cin >> a >> b;
        --a, --b;
        v[a].pb(b);
        v[b].pb(a);
    }
    level[0] = -1;
    dfs(-1, 0);
    cout << (solve() ? "DA" : "NE");
    return 0;
}
