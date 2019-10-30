#include<bits/stdc++.h>
#define god dimasi5eks
#pragma GCC optimize("O3")
#define fi first
#define se second
#define pb push_back
#define pf push_front
#define mod 1000000007

using namespace std;

typedef long long ll;

int n, q;

vector<int>v[100002];
ll path_sum[100002], sts[100002];
int rmq[20][200002], lg[200002];
int lvl[100002];
int m;
int euler[200002];
int nivel[200002];
int lst[100002];

int anc[20][100002];
void dfs(int dad, int nod)
{
    sts[nod] = 1;
    ++m;
    euler[m] = nod;
    nivel[m] = lvl[nod];

    int q = 0;
    anc[q][nod] = dad;
    while(anc[q][nod])
    {
        anc[q+1][nod] = anc[q][anc[q][nod]];
        ++q;
    }

    for(int i = 0; i < v[nod].size(); ++i)
    {
        int vecin = v[nod][i];
        if(vecin == dad)
            continue;
        lvl[vecin] = lvl[nod] + 1;
        dfs(nod, vecin);
        ++m;
        euler[m] = nod;
        nivel[m] = lvl[nod];
        sts[nod] += sts[vecin];
        path_sum[nod] += path_sum[vecin] + sts[vecin];
    }
    lst[nod] = m;
}
ll pathsumreverse[100002], ct[100002];
void dfs2(int dad, int nod, ll nodes, ll sum)
{
    ct[nod] = n - sts[nod];
    pathsumreverse[nod] = sum;
    for(int i = 0; i < v[nod].size(); ++i)
    {
        int vecin = v[nod][i];
        if(vecin == dad)
            continue;
        dfs2(nod, vecin, n - sts[vecin], sum + path_sum[nod] - path_sum[vecin] - sts[vecin] + n - sts[vecin]);
    }
}
void build()
{
    for(int i = 2; i <= m; ++i)
        lg[i] = lg[i/2] + 1;
    for(int i = 1; i <= m; ++i)
        rmq[0][i] = i;
    for(int i = 1; i <= lg[m]; ++i)
        for(int j = 1; j + (1<<i) - 1 <= m; ++j)
            if(nivel[rmq[i-1][j]] < nivel[rmq[i-1][j + (1<<(i - 1))]])
                rmq[i][j] = rmq[i-1][j];
            else
                rmq[i][j] = rmq[i-1][j + (1<<(i-1))];
}
int LCA(int x, int y)
{
    int a = min(lst[x], lst[y]);
    int b = max(lst[x], lst[y]);
    int ln = lg[b - a + 1];
    int ans = rmq[ln][a];
    if(nivel[rmq[ln][b - (1<<ln) + 1]] < nivel[ans])
        ans = rmq[ln][b - (1<<ln) + 1];
    return euler[ans];
}
int querybin(int dist, int nod)
{
    for(int i = 19; i >= 0; --i)
        if(dist >= (1<<i))
            nod = anc[i][nod], dist -= (1<<i);
    return nod;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> q;
    for(int i = 1; i < n; ++i)
    {
        int a, b;
        cin >> a >> b;
        v[a].pb(b);
        v[b].pb(a);
    }
    dfs(0, 1);
    dfs2(0, 1, 0, 0);
    build();
    for(int i = 1; i <= q; ++i)
    {
        int a, b;
        cin >> a >> b;
        int x = LCA(a, b);
        if(x == b)
            swap(a, b);
        if(LCA(a, b) == a)
        {
            int nrx = querybin(lvl[b] - lvl[a] - 1, b);
            ll nr = 1LL * sts[b] * (n - sts[nrx]);
            ll len = nr + 1LL * (path_sum[a] - path_sum[nrx] - sts[nrx] + pathsumreverse[a]) * sts[b] + 1LL * path_sum[b] * (n - sts[nrx]) + 1LL * (n - sts[nrx]) * sts[b] * (lvl[b] - lvl[a]);
            double rap = (0.0000 + len) / (0.0000 + nr);
            cout << fixed << setprecision(12) << rap << '\n';
        }
        else
        {
            ll len = 1LL * sts[a] * sts[b] + 1LL * path_sum[a] * sts[b] + 1LL * path_sum[b] * sts[a] + 1LL * sts[a] * sts[b] * (lvl[a] + lvl[b] - 2 * lvl[LCA(a, b)]);
            ll nr = 1LL * sts[a] * sts[b];
            double rap = (0.0000 + len) / (0.0000 + nr);
            cout << fixed << setprecision(12) << rap << '\n';
        }
    }
    return 0;
}
