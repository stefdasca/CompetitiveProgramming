#include<bits/stdc++.h>
using namespace std;
ifstream f("2sah.in");
ofstream g("2sah.out");
int t;
int n, k;
const int mod = 100003;
long long modpow(long long b, long long e)
{
    long long s = 1;
    while(e)
    {
        if(e & 1)
            s = (s * b) % mod;
        b = (b * b) % mod;
        e >>= 1;
    }
    return s;
}
long long mat[5][5], a[5];
void mult(long long a[5][5], long long b[5][5])
{
    long long ans[5][5];
    for(long long i = 1; i <= 3; ++i)
        for(long long j = 1; j <= 3; ++j)
            ans[i][j] = 0;
    for(long long i = 1; i <= 3; ++i)
        for(long long j = 1; j <= 3; ++j)
            for(long long k = 1; k <= 3; ++k)
                ans[i][j] = (ans[i][j] + a[i][k] * b[k][j]) % mod;
    for(long long i = 1; i <= 3; ++i)
        for(long long j = 1; j <= 3; ++j)
            a[i][j] = ans[i][j];
}
void lgput(long long a[5][5], long long p)
{
    long long copie[5][5];
    for(long long i = 1; i <= 3; ++i)
        for(long long j = 1; j <= 3; ++j)
        {
            copie[i][j] = a[i][j];
            if(i == j)
                a[i][j] = 1;
            else
                a[i][j] = 0;
        }
    while(p)
    {
        if(p & 1)
            mult(a, copie);
        mult(copie, copie);
        p >>= 1;
    }
}
int main()
{
    f >> t;
    f >> n >> k;
    if(t == 1)
    {
        g << modpow(3, k - 1);
        return 0;
    }
    a[1] = 2, a[2] = 1, a[3] = 1;
    mat[1][1] = 1, mat[1][2] = 1, mat[1][3] = 1;
    mat[2][1] = mat[3][2] = 1;
    lgput(mat, (n - k + 1) - 2);
    long long ans[4];
    for(int j = 1; j <= 3; ++j)
        ans[j] = 0;
    for(int i = 1; i <= 3; ++i)
        for(int k = 1; k <= 3; ++k)
            ans[i] = (ans[i] + mat[i][k] * a[k]) % mod;
    g << ans[1];
    return 0;
}
