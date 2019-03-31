#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int n, m, q;
int p[200002], v[200002], poz[200002];
int dp[200002], lst[200002];
int aint[800002], mxx;
void build(int nod, int st, int dr)
{
    if(st == dr)
    {
        aint[nod] = lst[st];
        return;
    }
    int mid = (st + dr) / 2;
    build(nod << 1, st, mid);
    build(nod << 1|1, mid + 1, dr);
    aint[nod] = max(aint[nod << 1], aint[nod << 1|1]);
}
void query(int nod, int st, int dr, int L, int R)
{
    if(dr < L || st > R)
        return;
    if(L <= st && dr <= R)
    {
        mxx = max(mxx, aint[nod]);
        return;
    }
    int mid = (st + dr) / 2;
    query(nod << 1, st, mid, L, R);
    query(nod << 1|1, mid + 1, dr, L, R);
}
int uu[200002];
int anc[200002][22];
int prec(int x)
{
    if(x == 1)
        return p[n];
    return p[x-1];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> q;
    for(int i = 1; i <= n; ++i)
        cin >> p[i], poz[p[i]] = i;
    for(int i = 1; i <= m; ++i)
        cin >> v[i];
    if(n == 1)
        for(int i = 1; i <= m; ++i)
            dp[i] = 1, lst[i] = i;
    else
        for(int i = 1; i <= m; ++i)
        {
            anc[i][0] = uu[prec(poz[v[i]])];
            int q = 0;
            while(anc[i][q])
            {
                int tt = anc[i][q];
                anc[i][q + 1] = anc[tt][q];
                ++q;
            }
            int lft = n-1;
            int pc = i;
            for(int j = 19; j >= 0; --j)
            {
                if(lft >= (1<<j) && anc[pc][j] != 0)
                    pc = anc[pc][j], lft -= (1<<j);
            }
            uu[v[i]] = i;
            if(lft == 0)
                lst[i] = pc;
        }
    build(1, 1, m);
    for(int i = 1; i <= q; ++i)
    {
        int st, dr;
        cin >> st >> dr;
        mxx = 0;
        query(1, 1, m, st, dr);
        if(mxx >= st)
            cout << 1;
        else
            cout << 0;
    }
    return 0;
}
