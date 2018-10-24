#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#define mod 1000000007
using namespace std;
int n, m, q;
char a[50][50];
int sp[50][50];
int gr[50][50][50][50];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    // shuffle(permutation.begin(), permutation.end(), rng);
    cin >> n >> m >> q;
    for(int i = 1; i <= n; ++i)
        cin >> (a[i] + 1);
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            sp[i][j] = sp[i-1][j] + sp[i][j-1] - sp[i-1][j-1] + (a[i][j] - '0');
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            for(int k = i; k <= n; ++k)
                for(int p = j; p <= m; ++p)
                {
                    gr[i][j][k][p] = gr[i][j][k-1][p] + gr[i][j][k][p-1] - gr[i][j][k-1][p-1];
                    if(sp[k][p] - sp[k][j-1] - sp[i-1][p] + sp[i-1][j-1] == 0)
                        ++gr[i][j][k][p];
                }
    for(int i = 1; i <= q; ++i)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        long long sol = 0;
        for(int r = a; r <= c; ++r)
            for(int o = b; o <= d; ++o)
                sol = sol + (gr[r][o][c][d]);
        cout << sol << '\n';
    }
    return 0;
}
