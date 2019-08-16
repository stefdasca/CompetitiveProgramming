#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second

using namespace std;
int n, m, k, v[200002];
struct ve
{
    int y, x;
};
ve pp[200002];
int dp[2002];
int sp[2002];
bool viz[2002];
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m >> k;
    for(int i = 1; i <= n; ++i)
        cin >> v[i];
    sort(v+1, v+n+1);
    n = min(n, k);
    for(int i = 1; i <= n; ++i)
        sp[i] = v[i] + sp[i-1];
    for(int i = 1; i <= m; ++i)
        cin >> pp[i].x >> pp[i].y;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
        {
            if(pp[j].x > i)
                continue;
            dp[i] = max(dp[i], dp[i - pp[j].x] + sp[i - pp[j].x + pp[j].y] - sp[i - pp[j].x]);
        }
    cout << sp[n] - dp[n];
    return 0;
}
