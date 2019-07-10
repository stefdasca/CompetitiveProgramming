#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

typedef long long ll;

int n, q, m, euler[200002], niv[200002], rmq[19][200002], lst[100002], lg[200002], dfsorder[100002], x, level[100002];
int aint[4][400002];
vector<int>v[100002];
void dfs(int nod, int L)
{
    dfsorder[nod] = ++x;
    level[nod] = L;
    ++m;
    euler[m] = nod, niv[m] = L;
    for(int i = 0; i < v[nod].size(); ++i)
    {
        int vecin = v[nod][i];
        dfs(vecin, L+1);
        ++m;
        euler[m] = nod, niv[m] = L;
    }
    lst[nod] = m;
}
void buildrmq()
{
    for(int i = 2; i <= 200000; ++i)
        lg[i] = lg[i/2] + 1;
    for(int i = 1; i <= m; ++i)
        rmq[0][i] = i;
    for(int i = 1; (1<<i) <= m; ++i)
        for(int j = 1; j + (1<<i) - 1 <= m; ++j)
        {
            rmq[i][j] = rmq[i-1][j];
            if(niv[rmq[i-1][j + (1<<(i-1))]] < niv[rmq[i-1][j]])
                rmq[i][j] = rmq[i-1][j + (1<<(i-1))];
        }
}
int findLCA(int x, int y)
{
    int a = min(lst[x], lst[y]);
    int b = max(lst[x], lst[y]);
    int ln = lg[b - a + 1];
    int ans = rmq[ln][a];
    if(niv[rmq[ln][b - (1<<ln) + 1]] < niv[ans])
        ans = rmq[ln][b - (1<<ln) + 1];
    return euler[ans];
}
void build(int nod, int st, int dr)
{
    if(st == dr)
    {
        aint[1][nod] = st;
        aint[2][nod] = st;
        aint[3][nod] = st;
        return;
    }
    int mid = (st + dr) / 2;
    build(nod << 1, st, mid);
    build(nod << 1|1, mid+1, dr);
    aint[1][nod] = findLCA(aint[1][nod << 1], aint[1][nod << 1|1]);
    if(dfsorder[aint[2][nod << 1]] < dfsorder[aint[2][nod << 1|1]])
        aint[2][nod] = aint[2][nod << 1];
    else
        aint[2][nod] = aint[2][nod << 1|1];
    if(dfsorder[aint[3][nod << 1]] > dfsorder[aint[3][nod << 1|1]])
        aint[3][nod] = aint[3][nod << 1];
    else
        aint[3][nod] = aint[3][nod << 1|1];
}
int LCA, mini, mxi;
void query(int nod, int st, int dr, int L, int R)
{
    if(dr < L || st > R)
        return;
    if(L <= st && dr <= R)
    {
        if(LCA == 0)
            LCA = aint[1][nod];
        else
            LCA = findLCA(LCA, aint[1][nod]);
        if(mini == 0 || dfsorder[aint[2][nod]] < dfsorder[mini])
            mini = aint[2][nod];
        if(mxi == 0 || dfsorder[aint[3][nod]] > dfsorder[mxi])
            mxi = aint[3][nod];
        return;
    }
    int mid = (st + dr) / 2;
    query(nod << 1, st, mid, L, R);
    query(nod << 1|1, mid+1, dr, L, R);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> q;
    for(int i = 2; i <= n; ++i)
    {
        int x;
        cin >> x;
        v[x].push_back(i);
    }
    dfs(1, 0);
    buildrmq();
    build(1, 1, n);
    for(int i = 1; i <= q; ++i)
    {
        int x, y;
        cin >> x >> y;
        LCA = 0, mini = 0, mxi = 0;
        query(1, 1, n, x, y);
        int xx = 0, yy = 0, a = min(mini, mxi), b = max(mini, mxi);
        if(a == x)
        {
           LCA = 0, mini = 0, mxi = 0;
           query(1, 1, n, x+1, y);
           xx = LCA;
        }
        else
            if(a == y)
            {
                LCA = 0, mini = 0, mxi = 0;
                query(1, 1, n, x, y-1);
                xx = LCA;
            }
            else
            {
                LCA = 0, mini = 0, mxi = 0;
                query(1, 1, n, x, a-1);
                xx = LCA;
                LCA = 0, mini = 0, mxi = 0;
                query(1, 1, n, a+1, y);
                xx = findLCA(xx, LCA);
            }
        if(b == x)
        {
           LCA = 0, mini = 0, mxi = 0;
           query(1, 1, n, x+1, y);
           yy = LCA;
        }
        else
            if(b == y)
            {
                LCA = 0, mini = 0, mxi = 0;
                query(1, 1, n, x, y-1);
                yy = LCA;
            }
            else
            {
                LCA = 0, mini = 0, mxi = 0;
                query(1, 1, n, x, b-1);
                yy = LCA;
                LCA = 0, mini = 0, mxi = 0;
                query(1, 1, n, b+1, y);
                yy = findLCA(yy, LCA);
            }
        if(level[xx] >= level[yy])
            cout << a << " " << level[xx] << '\n';
        else
            cout << b << " " << level[yy] << '\n';
    }
    return 0;
}

