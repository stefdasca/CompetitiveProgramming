/// Goodbye until the day we meet again

#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int n;
long long amount[300002], maxanswer;
vector<pair<long long, long long> >v[300002];
long long dp[300002];
void dfs(int dad, int nod)
{
    int who = 0;
    for(int i = 0; i < v[nod].size(); ++i)
    {
        int vecin = v[nod][i].first;
        if(vecin == dad)
            continue;
        int cost = v[nod][i].second;
        dfs(nod, vecin);
        if(dp[vecin] - cost > dp[nod])
            dp[nod] = dp[vecin] - cost, who = vecin;
    }
    dp[nod] += amount[nod];
    for(int i = 0; i < v[nod].size(); ++i)
    {
        int vecin = v[nod][i].first;
        if(vecin == dad || vecin == who)
            continue;
        int cost = v[nod][i].second;
        if(cost < dp[nod])
           maxanswer = max(maxanswer, dp[nod] - cost + dp[vecin]);
        if(cost < dp[vecin])
           maxanswer = max(maxanswer, dp[nod] - cost + dp[vecin]);
    }
    maxanswer = max(maxanswer, dp[nod]);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> amount[i], maxanswer = max(maxanswer, amount[i]);
    for(int i = 1; i < n; ++i)
    {
        long long a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({b, c});
        v[b].push_back({a, c});
    }
    dfs(0, 1);
    cout << maxanswer;
    return 0;
}
