/*
        POI 16-Messenger

    Since the number of queries can be way bigger than n * (n-1), we can precompute all the possible answers and print the answer for each query in O(1).

    In order to do this, we are going to precompute the answer in O(n*m) for each pair. Since this is not enough, I also had to use two optimizations:

    1) don't iterate from nodes such that distance from node to destination is bigger than the number of steps we're left with(distances can be computed
with BFS).
    2) keeping the list of neighbors in classical format rather than in std::vector style(faster runtime, also the difference is quite significant when
we're talking about big time limits, like we have here).

    Implementing this properly will ensure 100 points and also the running time is quite good(further optimizations
can also be found).

*/
#include<bits/stdc++.h>
#define god dimasi5eks
#pragma GCC optimize("Ofast")
#define fi first
#define se second
#define pb push_back
#define pf push_front
#define dancila 3.14159265359
#define eps 1e-9

using namespace std;

typedef long long ll;

int mod;

int add(int a, int b)
{
    int x = a+b;
    if(x >= mod)
        x -= mod;
    return x;
}
int n, m, z;
bool iz[102][102];
int ans[102][102][52], mx[102][102];
struct qu
{
    int a, b, d;
};
qu v[500002];
int dp[2][102];
int li[102][102], sz[102];
int dist[102][102];
void solve(int a, int b, int d)
{
    memset(dp, 0, sizeof(dp));
    dp[0][a] = 1;
    for(int i = 1; i <= d; ++i)
    {
        int mx = (i-1) & 1;
        int rev = 1 - mx;
        for(int j = 1; j <= n; ++j)
            if(dp[mx][j])
            {
                if(dist[j][b] <= d - i + 1)
                    for(int p = 1; p <= sz[j]; ++p)
                        dp[rev][li[j][p]] = add(dp[rev][li[j][p]], dp[mx][j]);
                dp[mx][j] = 0;
            }
        ans[a][b][i] = dp[rev][b];
        dp[rev][b] = 0;
    }
}
void bfs(int nod)
{
    deque<int> d;
    d.pb(nod);
    while(!d.empty())
    {
        int x = d[0];
        d.pop_front();
        for(int p = 1; p <= sz[x]; ++p)
            if(li[x][p] != nod && dist[nod][li[x][p]] == 0)
            {
                d.pb(li[x][p]);
                dist[nod][li[x][p]] = dist[nod][x] + 1;
            }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> mod;
    for(int i = 1; i <= m; ++i)
    {
        int a, b;
        cin >> a >> b;
        iz[a][b] = 1;
    }
    int q;
    cin >> q;
    for(int i = 1; i <= q; ++i)
    {
        cin >> v[i].a >> v[i].b >> v[i].d;
        mx[v[i].a][v[i].b] = max(mx[v[i].a][v[i].b], v[i].d);
    }
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= n; ++j)
            sz[j] = 0;
        for(int j = 1; j <= n; ++j)
            for(int k = 1; k <= n; ++k)
                if(k != i && iz[j][k])
                    li[j][++sz[j]] = k;
        memset(dist, 0, sizeof(dist));
        for(int j = 1; j <= n; ++j)
            bfs(j);
        for(int j = 1; j <= n; ++j)
            if(mx[i][j])
                solve(i, j, mx[i][j]);
    }
    for(int i = 1; i <= q; ++i)
        cout << ans[v[i].a][v[i].b][v[i].d] << '\n';
    return 0;
}
