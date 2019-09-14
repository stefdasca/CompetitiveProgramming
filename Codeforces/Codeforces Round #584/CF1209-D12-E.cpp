#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#define fi first
#define se second
#define pb push_back
#define pf push_front
#define mod 1000000007

using namespace std;

typedef long long ll;


int t, n, m;
int mat[13][2002];
bool tk[2002];
struct BFR
{
    int val, L, C;
};
BFR v[13 * 2002];
bool cmp(BFR a, BFR b)
{
    return a.val < b.val;
}
vector<int>tt;

int dp[15][(1<<12)], val[2005][(1<<12)];
int get(int col, int msk)
{
    if(val[col][msk] != -1)
        return val[col][msk];
    val[col][msk] = 0;
    for(int rot = 0; rot < n; ++rot)
    {
        int op = 0;
        for(int j = 0; j < n; ++j)
        {
            int poz = j + rot + 1;
            if(poz > n)
                poz -= n;
            if(msk & (1<<j))
                op += mat[poz][col];
        }
        val[col][msk] = max(val[col][msk], op);
    }
    return val[col][msk];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    for(; t; --t)
    {
        cin >> n >> m;
        int pp = 0;
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= m; ++j)
            {
                cin >> mat[i][j];
                v[++pp] = {mat[i][j], i, j};
            }
        sort(v+1, v+pp+1, cmp);
        memset(tk, 0, sizeof(tk));
        tt.clear();
        for(int i = pp; i >= 1; --i)
        {
            if(!tk[v[i].C])
            {
                tt.pb(v[i].C);
                tk[v[i].C] = 1;
                if(tt.size() >= n)
                    break;
            }
        }
        for(int i = 0; i <= n; ++i)
            for(int j = 0; j < (1<<12); ++j)
                dp[i][j] = -(1<<30);
        dp[0][(1<<n) - 1] = 0;
        memset(val, -1, sizeof(val));
        for(int i = 0; i < tt.size(); ++i)
        {
            for(int msk = 0; msk < (1<<n); ++msk)
            {
                dp[i+1][msk] = dp[i][msk];
                for(int k = msk; k; k = ((k - 1) & msk))
                    dp[i+1][(msk^k)] = max(dp[i + 1][(msk ^ k)], dp[i][msk] + get(tt[i], k));
            }
        }
        cout << dp[tt.size()][0] << '\n';
    }
    return 0;
}

