#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
long long rand_seed()
{
	long long a = rng();
    return a;
}
long long ans;
int n;
vector<pair<long long, long long> >v[100002];
long long dp[3][100002];
void dfs(int dad, int nod)
{
    long long sum = 0;
    long long mxx = 0, mxx2 = 0;
    for(int i = 0; i < v[nod].size(); ++i)
    {
        int vecin = v[nod][i].first;
        long long dist = v[nod][i].second;
        if(vecin == dad)
            continue;
        dfs(nod, vecin);
        sum += dp[0][vecin];
        long long pp = dp[1][vecin] + dist;
        if(pp - dp[0][vecin] > mxx)
            mxx2 = mxx, mxx = pp - dp[0][vecin];
        else
            if(pp - dp[0][vecin] > mxx2)
                mxx2 = pp - dp[0][vecin];
    }
    dp[1][nod] = sum + mxx;
    dp[0][nod] = sum + mxx + mxx2;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 1; i < n; ++i)
    {
        long long a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({b, c});
        v[b].push_back({a, c});
    }
    dfs(0, 1);
    cout << max(dp[0][1], dp[1][1]) << '\n';
    return 0;
}

