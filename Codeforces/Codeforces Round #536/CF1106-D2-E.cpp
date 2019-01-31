#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int n, m, k;
struct arr
{
    int st, dr, stop, val;
};
arr v[100002];
bool cmp(arr a, arr b)
{
    if(a.st == b.st && a.val == b.val)
        return a.stop > b.stop;
    if(a.st == b.st)
        return a.val < b.val;
    return a.st < b.st;
}
long long dp[100002][202];
int stp[100002], sfp[100002];
int wh[100002];
long long mn[202];
struct cmp2
{
    bool operator()(int a, int b)
    {
        if(v[a].val == v[b].val)
            return (v[a].stop < v[b].stop);
        return (v[a].val < v[b].val);
    }
};
priority_queue<int, vector<int>, cmp2>q;
bool viz[100005][202];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> k;
    for(int i = 1; i <= k; ++i)
        cin >> v[i].st >> v[i].dr >> v[i].stop >> v[i].val;
    sort(v+1, v+k+1, cmp);
    int poz = 1;
    for(int i = 1; i <= n; ++i)
    {
        while(poz <= k && v[poz].st == i)
            q.push(poz), ++poz;
        while(!q.empty() && v[q.top()].dr < i)
            q.pop();
        if(q.empty())
            continue;
        if(!stp[q.top()])
            stp[q.top()] = i;
        sfp[q.top()] = i;
        wh[i] = q.top();
    }
    long long ans = (1LL<<60);
    viz[1][0] = 1;
    for(int i = 1; i <= n; ++i)
    {
        if(wh[i])
            for(int j = 0; j <= m; ++j)
            {
                if(!viz[i][j])
                    continue;
                if(!viz[i+1][j+1] || dp[i][j] < dp[i+1][j+1])
                    viz[i+1][j+1] = 1, dp[i+1][j+1] = dp[i][j];
                if(!viz[v[wh[i]].stop + 1][j] || dp[i][j] + v[wh[i]].val < dp[v[wh[i]].stop + 1][j])
                    viz[v[wh[i]].stop + 1][j] = 1, dp[v[wh[i]].stop + 1][j] =dp[i][j] + v[wh[i]].val;
            }
        else
            for(int j = 0; j <= m; ++j)
            {
                if(!viz[i][j])
                    continue;
                if(!viz[i+1][j] || dp[i][j] < dp[i+1][j])
                    viz[i+1][j] = 1, dp[i+1][j] = dp[i][j];
            }
    }
    for(int i = 0; i <= m; ++i)
        if(viz[n+1][i])
            ans = min(ans, dp[n+1][i]);
    cout << ans << '\n';
    return 0;
}

