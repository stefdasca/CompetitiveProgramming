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

ll sum, n, we[100002], subtreesum[100002], rad;
vector<int> v[100002];

int anc[18][100002];

int rmq[20][200002], lg[200002];
int lvl[100002];
int m;
int euler[200002];
int nivel[200002];
int lst[100002];

void dfs(int dad, int nod)
{
    ++m;
    euler[m] = nod;
    nivel[m] = lvl[nod];
    subtreesum[nod] = we[nod];
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
        subtreesum[nod] += subtreesum[vecin];
    }
    lst[nod] = m;
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

int kth(int nod, int dist)
{
    for(int i = 17; i >= 0; --i)
        if(dist >= (1<<i))
            nod = anc[i][nod], dist -= (1<<i);
    return nod;
}
ll s(int rad, int nod)
{
    if(rad == nod)
        return sum;
    if(LCA(rad, nod) == nod)
    {
        ll dist = lvl[rad] - lvl[nod];
        return sum - subtreesum[kth(rad, dist - 1)];
    }
    else
        return subtreesum[nod];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> we[i], sum += we[i];
    for(int i = 2; i <= n; ++i)
    {
        int ve;
        cin >> ve;
        v[ve].pb(i);
        v[i].pb(ve);
    }

    dfs(0, 1);
    build();
    rad = 1;
    int q;
    cin >> q;
    for(int i = 1; i <= q; ++i)
    {
        char c;
        int nn;
        cin >> c >> nn;
        if(c == 'S')
            cout << s(rad, nn) << '\n';
        else
            rad = nn;
    }
    return 0;
}

