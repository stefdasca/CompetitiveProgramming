#include<bits/stdc++.h>
#pragma gcc optimize("O3")
using namespace std;

int n, m, q;
int mat[4002][4002], sp[4002][4002], spinv[4002][4002];
long long query(long long L, long long C)
{
    long long a = L / (2 * n);
    long long b = C / (2 * m);
    int x = __builtin_popcount(a) + __builtin_popcount(b);
    bool inverted = 0;
    if(x % 2 == 1)
        inverted = 1;
    long long p = L - a * (2 * n);
    long long q = C - b * (2 * m);
    long long ans = a * b * n * m * 2;
    ans += a * n * q;
    ans += b * m * p;
    if(inverted)
        ans += spinv[p][q];
    else
        ans += sp[p][q];
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> q;
    for(int i = 0; i < n; ++i)
    {
        string s;
        cin >> s;
        for(int j = 0; j < m; ++j)
            mat[i][j] = (s[j] - '0');
    }
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j)
        {
            mat[i+n][j] = mat[i][j] ^ 1;
            mat[i][j+m] = mat[i][j] ^ 1;
            mat[i+n][j+m] = mat[i][j];
        }
    for(int i = 0; i < 2 * n; ++i)
        for(int j = 0; j < 2 * m; ++j)
        {
            sp[i+1][j+1] = sp[i+1][j] + sp[i][j+1] - sp[i][j] + mat[i][j];
            spinv[i+1][j+1] = (i + 1) * (j + 1) - sp[i+1][j+1];
        }
    for(int i = 1; i <= q; ++i)
    {
        int La, Ca, Lb, Cb;
        cin >> La >> Ca >> Lb >> Cb;
        --La;
        --Ca;
        cout << query(Lb, Cb) - query(La, Cb) - query(Lb, Ca) + query(La, Ca) << '\n';
    }
    return 0;
}
