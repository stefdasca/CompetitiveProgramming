#include<fstream>
#include<algorithm>
using namespace std;
ifstream f("nkbiti.in");
ofstream g("nkbiti.out");
int n, k;
const int mod = 666777;
int a[1002];
long long mat[46][46];
void mult(long long a[46][46], long long b[46][46])
{
    long long ans[k + 2][k + 2];
    for(long long i = 1; i <= k; ++i)
        for(long long j = 1; j <= k; ++j)
            ans[i][j] = 0;
    for(long long i = 1; i <= k; ++i)
        for(long long j = 1; j <= k; ++j)
            for(long long q = 1; q <= k; ++q)
                ans[i][j] = (ans[i][j] + a[i][q] * b[q][j]) % mod;
    for(long long i = 1; i <= k; ++i)
        for(long long j = 1; j <= k; ++j)
            a[i][j] = ans[i][j];
}
void lgput(long long a[46][46], long long p)
{
    long long copie[46][46];
    for(long long i = 1; i <= k; ++i)
        for(long long j = 1; j <= k; ++j)
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
    f >> n >> k;
    a[1] = 1, a[2] = 1;
    for(int i = 3; i <= min(n, k) + 1; ++i)
        for(int j = i - 1; j >= max(0, i - k - 1); --j)
            a[i] = (a[i] + a[j]) % mod;
    if(n <= k)
    {
        long long s = 0;
        for(int j = n; j >= 0; --j)
            s += a[j];
        g << s << '\n';
        return 0;
    }
    ++k;
    for(int i = 1; i <= k; ++i)
        mat[1][i] = 1;
    for(int i = 1; i < k; ++i)
        mat[i + 1][i] = 1;
    lgput(mat, n - k + 1);
    reverse(a + 1, a + k + 1);
    long long ans[k + 2];
    for(int j = 1; j <= k; ++j)
        ans[j] = 0;
    for(int i = 1; i <= k; ++i)
        for(int z = 1; z <= k; ++z)
            ans[i] = (ans[i] + mat[i][z] * a[z]) % mod;
    long long s = 0;
    for(int j = 1; j <= k; ++j)
        s = (s + ans[j]) % mod;
    g << s;
    return 0;
}
