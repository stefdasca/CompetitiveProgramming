/*
        infoarena tritzi(https://www.infoarena.ro/problema/tritzi)
      
    "Find number of ternary numbers of length n such that there aren't any 0 and 1 which are adjacent"
    
    After running a naive dp approach, one can observe that we can reduce the problem to a straightforward matrix exponentiation, because
dp[i] = 2 * dp[i-1] + dp[i-2], where dp[1] = 3 and dp[2] = 7

*/
#include<bits/stdc++.h>
using namespace std;
ifstream f("tritzi.in");
ofstream g("tritzi.out");
long long t, n, mod, mt[3][3], vv[3], cp[3][3], tt[3][3], rc[3];
void mult(long long a[3][3], long long b[3][3])
{
    long long ans[3][3] = {0};
    for(int i = 1; i <= 2; ++i)
        for(int j = 1; j <= 2; ++j)
            for(int k = 1; k <= 2; ++k)
                ans[i][j] = (ans[i][j] + 1LL * a[i][k] * b[k][j]) % mod;
    for(int i = 1; i <= 2; ++i)
        for(int j = 1; j <= 2; ++j)
            a[i][j] = ans[i][j];
}
void lgput(long long a[3][3], long long ex)
{
    cp[1][1] = cp[2][2] = 1;
    for(int i = 1; i <= 2; ++i)
        for(int j = 1; j <= 2; ++j)
            tt[i][j] = a[i][j];
    while(ex)
    {
        if(ex & 1)
            mult(cp, tt);
        mult(tt, tt);
        ex >>= 1;
    }
    for(int i = 1; i <= 2; ++i)
        for(int j = 1; j <= 2; ++j)
            a[i][j] = cp[i][j];
}
int main()
{
    f >> t;
    for(; t; --t)
    {
        f >> n >> mod;
        memset(mt, 0, sizeof(mt));
        memset(vv, 0, sizeof(vv));
        memset(cp, 0, sizeof(cp));
        memset(rc, 0, sizeof(rc));
        mt[1][1] = 2, mt[1][2] = 1;
        mt[2][1] = 1;
        vv[1] = 7, vv[2] = 3;
        if(n == 1)
            g << 3 % mod << '\n';
        else
        {
            lgput(mt, n - 2);
            for(int j = 1; j <= 2; ++j)
                for(int k = 1; k <= 2; ++k)
                    rc[k] = (rc[k] + vv[j] * mt[k][j]) % mod;
            g << rc[1] << '\n';
        }
    }
    return 0;
}
