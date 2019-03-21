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
int n, k;
long long nr[102][100002], gg[102][100002];
vector<pair<int, int> >v[100002];
vector<int>cc[100002];
int ccc;
bool viz[100002];
void dfs(int nod)
{
    cc[ccc].push_back(nod);
    viz[nod] = 1;
    for(int i = 0; i < v[nod].size(); ++i)
    {
        int vecin = v[nod][i].first;
        int cl = v[nod][i].second;
        if(cl == 0 && !viz[vecin])
            dfs(vecin);
    }
}
long long tsum[100002];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;
    for(int i = 1; i < n; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({b, c});;
        v[b].push_back({a, c});
    }
    for(int i = 1; i <= n; ++i)
        nr[1][i] = 1;
    for(int i = 1; i <= n; ++i)
    {
        if(!viz[i])
        {
            ++ccc;
            dfs(i);
        }
    }
    for(int i = 1; i < k; ++i)
    {
        long long totsum = 0;
        long long tt = 0;
        for(int j = 1; j <= ccc; ++j)
        {
            long long sum = 0;
            for(int p = 0; p < cc[j].size(); ++p)
                sum = (sum + nr[i][cc[j][p]]) % mod, tt = (tt + gg[i][cc[j][p]]) % mod;
            for(int p = 0; p < cc[j].size(); ++p)
                nr[i+1][cc[j][p]] = sum;
            totsum = (totsum + sum) % mod;
            tsum[j] = sum;
        }
        for(int j = 1; j <= ccc; ++j)
        {
            long long sum = totsum + mod - tsum[j];
            sum %= mod;
            for(int p = 0; p < cc[j].size(); ++p)
                gg[i+1][cc[j][p]] = (sum + tt) % mod;
        }
    }
    long long ans = 0;
    for(int j = 1; j <= n; ++j)
        ans = (ans + gg[k][j]) % mod;
    cout << ans;
    return 0;
}

