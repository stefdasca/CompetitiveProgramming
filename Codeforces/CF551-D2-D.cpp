/// Never do the same mistake twireze

#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
unsigned long long n, k, l, m;
long long modpow(long long b, long long ex)
{
    long long ans = 1;
    while(ex)
    {
        if(ex & 1)
            ans = (ans * b) % m;
        b = (b * b) % m;
        ex >>= 1;
    }
    return ans;
}
long long mat[3][3], SOL[3][3];
inline void mult(long long t1[][3], long long t2[][3], long long rez[][3])
{
    long long i, j, k;
    for (i = 0; i < 2; i++)
        for (j = 0; j < 2; j++)
            for (k = 0; k < 2; k++)
                rez[i][j] = (rez[i][j] + 1LL * t1[i][k] * t2[k][j]) % m;

}

inline void lg_power(long long P, long long M[][3])
{
    long long rez[3][3], aux[3][3], i;

    memcpy(rez, mat, sizeof(mat));
    M[0][0] = M[1][1] = 1;
    while(P)
    {
        if (P & 1)
        {
            memset(aux, 0, sizeof(aux));
            mult(M, rez, aux);
            memcpy(M, aux, sizeof(aux));
        }

        memset(aux, 0, sizeof(aux));
        mult(rez, rez, aux);
        memcpy(rez, aux, sizeof(rez));
        P >>= 1;
    }
}
long long fiboo(long long cat)
{
    mat[0][0] = 0;
    mat[0][1] = 1;
    mat[1][0] = 1;
    mat[1][1] = 1;
    lg_power(cat, SOL);
    return SOL[1][1];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k >> l >> m;
    unsigned long long ans = 1;
    long long fb = fiboo(n + 1);
    long long pw = modpow(2, n);
    long long summ = 0;
    for(int i = l-1; i >= 0; --i)
    {
        unsigned long long qq;
        if(i <= 62)
            qq = (1LL<<i);
        else
            qq = (1LL<<62) + (1LL<<62);
        unsigned long long aa = (k & qq);
        if(aa == 0)
            ans = (ans * fb) % m;
        else
            summ += qq, ans = (ans * (pw - fb + m)) % m;
    }
    if(summ != k)
        cout << 0;
    else
        cout << ans%m;
    return 0;
}

