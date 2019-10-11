// https://www.infoarena.ro/problema/kfib

#include<bits/stdc++.h>
using namespace std;
ifstream f("kfib.in");
ofstream g("kfib.out");
const int mod = 666013;
long long nrd;
long long a[5];
long long mat[5][5];
void mult(long long a[5][5], long long b[5][5])
{
    long long ans[5][5];
    for(long long i = 1; i <= 2; ++i)
        for(long long j = 1; j <= 2; ++j)
            ans[i][j] = 0;
    for(long long i = 1; i <= 2; ++i)
        for(long long j = 1; j <= 2; ++j)
            for(long long k = 1; k <= 2; ++k)
                ans[i][j] = (ans[i][j] + a[i][k] * b[k][j]) % mod;
    for(long long i = 1; i <= 2; ++i)
        for(long long j = 1; j <= 2; ++j)
            a[i][j] = ans[i][j];
}
void lgput(long long a[5][5], long long p)
{
    long long copie[5][5];
    for(long long i = 1; i <= 2; ++i)
        for(long long j = 1; j <= 2; ++j)
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
    f >> nrd;
    a[1] = 1, a[2] = 1;
    mat[1][1] = 1, mat[1][2] = 1;
    mat[2][1] = 1;
    if(nrd <= 2)
        g << a[nrd] << '\n';
    else
    {
        lgput(mat, nrd - 2);
        long long ans[4];
        for(int j = 1; j <= 2; ++j)
            ans[j] = 0;
        for(int i = 1; i <= 2; ++i)
            for(int k = 1; k <= 2; ++k)
                ans[i] = (ans[i] + mat[i][k] * a[k]) % mod;
        g << ans[1] << '\n';
    }
    return 0;
}

