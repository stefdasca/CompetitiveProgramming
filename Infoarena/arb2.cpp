#include<bits/stdc++.h>
using namespace std;
ifstream f("arb2.in");
ofstream g("arb2.out");
int n;
struct str
{
    int vecin, dist, cost;
};
vector<str>v[100002];
long long dp[100002], sol;
int len[100002];
void dfs(int dad, int nod)
{
    int maxlen = 0;
    for(int i = 0; i < v[nod].size(); ++i)
    {
        str x = v[nod][i];
        if(x.vecin == dad)
            continue;
        dfs(nod, x.vecin);
        len[x.vecin] += x.dist;
        if(x.cost < dp[x.vecin])
            dp[x.vecin] = x.cost;
        if(len[x.vecin] > maxlen)
            maxlen = len[x.vecin];
    }
    if(v[nod].size() == 1)
        dp[nod] = 999999999;
    for(int i = 0; i < v[nod].size(); ++i)
    {
        str x = v[nod][i];
        if(x.vecin == dad)
            continue;
        sol = sol + 1LL * (maxlen - len[x.vecin]) * dp[x.vecin];
        dp[nod] += dp[x.vecin];
    }
    len[nod] = maxlen;
}
int main()
{
    f >> n;
    for(int i = 1; i < n; ++i)
    {
        int a, b, c, d;
        f >> a >> b >> c >> d;
        v[a].push_back({b, c, d});
        v[b].push_back({a, c, d});
    }
    dfs(0, 1);
    g << sol;
    return 0;
}
