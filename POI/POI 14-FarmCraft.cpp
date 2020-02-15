/*
        POI 14-FarmCraft

    We can solve this problem using dp on trees.

    Let dp[i] be the best time we can achieve if we have only the tree rooted at node i(if i = 1, then we will install the game
on node i after we install it everywhere else, otherwise we can install it right now).

    Then, in order to compute dp[i] based on the dp values of its sons, we are going to assume for each of its sons that it's the last son taken
(we go to every other son's subtree and then go to that son) and sort the nodes based on value of dp[i] + 2 * (subtree size of father - subtree size of i)
for each son i. Then, in decreasing order, we are going to update the max answer based on this sorting order.

    Basically, we are going to iterate through the sons in decreasing order of the worst case time.
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

// #define fisier 1

using namespace std;

int n, timp[500002];

int dp[500002], ans, sts[500002];
vector<int> v[500002];

void dfs(int dad, int nod)
{
    if(nod == 1)
        dp[nod] = 2 * (n-1) + timp[nod];
    else
        dp[nod] = timp[nod];
    sts[nod] = 1;
    vector<pair<int, int> >vec;
    for(int i = 0; i < v[nod].size(); ++i)
    {
        int vecin = v[nod][i];
        if(vecin == dad)
            continue;
        dfs(nod, vecin);
        sts[nod] += sts[vecin];
        vec.pb({dp[vecin], vecin});
    }
    for(int i = 0; i < vec.size(); ++i)
        vec[i].fi = vec[i].fi + 2 * (sts[nod] - sts[vec[i].se]);
    sort(vec.begin(), vec.end());
    int tot = 0;
    for(int i = vec.size() - 1; i >= 0; --i)
    {
        tot++;
        dp[nod] = max(dp[nod], tot + dp[vec[i].se]);
        tot += 2 * sts[vec[i].se] - 1;
    }
}
int main()
{

    #ifdef fisier
        ifstream f("input.in");
        ofstream g("output.out");
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> timp[i];
    for(int i = 1; i < n; ++i)
    {
        int a, b;
        cin >> a >> b;
        v[a].pb(b);
        v[b].pb(a);
    }
    dfs(0, 1);
    cout << dp[1];
    return 0;
}
