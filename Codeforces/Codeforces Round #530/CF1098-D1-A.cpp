/// 2222 by 1 february, thx

#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int n;
vector<int>v[100002];
long long sum[100002];
long long val[100002];
void dfs(int dad, int nod)
{
    if(sum[nod] != -1)
        val[nod] = sum[nod] - sum[dad];
    else
    {
        long long minsum = (1LL<<60);
        for(int j = 0; j < v[nod].size(); ++j)
            minsum = min(minsum, sum[v[nod][j]]);
        if(v[nod].size())
            val[nod] = minsum - sum[dad];
        sum[nod] = sum[dad] + val[nod];
    }
    for(int j = 0; j < v[nod].size(); ++j)
        dfs(nod, v[nod][j]);
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
    for(int i = 1; i <= n; ++i)
        cin >> sum[i];
    dfs(0, 1);
    long long ans = 0;
    for(int j = 1; j <= n; ++j)
        if(val[j] < 0)
        {
            cout << -1;
            return 0;
        }
        else
            ans += val[j];
    cout << ans;
    return 0;
}
