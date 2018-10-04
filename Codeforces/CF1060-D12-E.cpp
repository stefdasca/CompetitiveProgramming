#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#define mod 1000000007
#define fi first
#define se second
using namespace std;
long long n, ans, o, e;
vector<int>v[200002];
long long sum[200002];
void dfs(int now, int prev, int pa)
{
    if(pa == 1)
        o++;
    else
        e++;
    for(int i = 0; i < v[now].size(); ++i)
    {
        int u = v[now][i];
        if(u == prev)
            continue;
        dfs(u, now, 1-pa);
        sum[now] += sum[u];
    }
    ans += sum[now] * (n - sum[now]);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for(int i = 1; i <= n; ++i)
        sum[i] = 1;
    dfs(1, 0, 0);
    cout << (ans + o*e)/2;
    return 0;
}
