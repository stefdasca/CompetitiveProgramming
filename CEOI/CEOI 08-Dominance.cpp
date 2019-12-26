/*
                CEOI 08-Dominance

    Modify the query from (x, y, r) to (x+y-r, x-y-r, 2*r) and now we turned the problem
into adding 1 or -1 to a square of size 2*r, which can be solved using normalization.

    Counting the number of squares with positive or negative sum is easy using some math,
now that we computed the sums.

    Also, because memory limit is tight, I kept only the last 2 lines of the prefix sums.

*/
#include<bits/stdc++.h>
#define god dimasi5eks
#pragma GCC optimize("O3")
#define fi first
#define se second
#define pb push_back
#define pf push_front
#define mod 1000000007
#define dancila 3.14159265359
#define eps 1e-9

using namespace std;

typedef long long ll;


int add(int a, int b)
{
    ll x = a+b;
    if(x >= mod)
        x -= mod;
    if(x < 0)
        x += mod;
    return x;
}
ll mul(ll a, ll b)
{
    return (a*b) % mod;
}

ll pw(ll a, ll b)
{
    ll ans = 1;
    while(b)
    {
        if(b & 1)
            ans = (ans * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return ans;
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
long long rand_seed()
{
    long long a = rng();
    return a;
}
int n, m, q, q2;
struct dt
{
    char tip;
    int ls, cs, rg;
};
dt v[3002], v2[12002];
int vc[6202];
int mat[3][6202];
int xx[6202], yy[6202], nx, ny;
int px[6002], py[6002], rx, ry;
bool cmp(dt a, dt b)
{
    if(a.ls == b.ls)
        return a.cs < b.cs;
    return a.ls < b.ls;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    cin >> q;
    nx = ny = 1;
    for(int i = 1; i <= q; ++i)
    {
        cin >> v[i].tip;
        cin >> v[i].ls >> v[i].cs >> v[i].rg;
        int nnx = v[i].ls + v[i].cs - v[i].rg;
        int nny = v[i].ls - v[i].cs - v[i].rg;
        v[i].rg *= 2;
        v[i].ls = nnx;
        v[i].cs = nny;
        xx[++nx] = v[i].ls;
        yy[++ny] = v[i].cs;
        xx[++nx] = v[i].ls + v[i].rg + 1;
        yy[++ny] = v[i].cs + v[i].rg + 1;
        v2[++q2] = {v[i].tip, v[i].ls, v[i].cs, 1};
        v2[++q2] = {v[i].tip, v[i].ls + v[i].rg + 1, v[i].cs, -1};
        v2[++q2] = {v[i].tip, v[i].ls, v[i].cs + v[i].rg + 1, -1};
        v2[++q2] = {v[i].tip, v[i].ls + v[i].rg + 1, v[i].cs + v[i].rg + 1, 1};
    }
    sort(xx + 1, xx + nx + 1);
    sort(yy + 1, yy + ny + 1);
    xx[nx + 1] = xx[nx] + 1;
    yy[ny + 1] = yy[ny] + 1;
    ++nx;
    ++ny;
    sort(v2 + 1, v2 + q2 + 1, cmp);
    for(int i = 1; i <= nx; ++i)
        if(i == 1 || xx[i] > xx[i-1])
            px[++rx] = xx[i];
    for(int i = 1; i <= ny; ++i)
        if(i == 1 || yy[i] > yy[i-1])
            py[++ry] = yy[i];
    int ppz = 1;
    ll nW = 0, nB = 0;
    for(int i = 1; i < rx; ++i)
    {
        for(int j = 1; j < ry; ++j)
        {
            mat[2][j] = mat[2][j-1] + mat[1][j] - mat[1][j-1];
            while(ppz <= q2 && v2[ppz].ls == px[i] && v2[ppz].cs == py[j])
            {
                if(v2[ppz].tip == 'W')
                {
                    if(v2[ppz].rg == 1)
                        ++mat[2][j];
                    else
                        --mat[2][j];
                }
                else
                {
                    if(v2[ppz].rg == 1)
                        --mat[2][j];
                    else
                        ++mat[2][j];
                }
                ++ppz;
            }
            ll area = 1LL * (px[i+1] - px[i]) * (py[j+1] - py[j]);
            ll total = area / 2;
            if(area % 2)
                total += ((px[i] + py[j]) % 2 == 0);
            if(mat[2][j] > 0)
                nW += total;
            else
                if(mat[2][j] < 0)
                    nB += total;
        }
        for(int j = 1; j <= ry; ++j)
            mat[1][j] = mat[2][j], mat[2][j] = 0;
    }
    cout << nW << " " << nB << '\n';
    return 0;
}
