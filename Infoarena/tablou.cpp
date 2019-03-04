/*
        infoarena tablou(https://www.infoarena.ro/problema/tablou)
        
   "Given a n*m matrix and k queries, where at some query one modifies the values from the first matrix in a submatrix(xa, ya) to (xb, yb)
to a certain digit, and we have to compute the sum of the differences between matrix from query i and all the other matrixes from the other
queries. difference between 2 matrixes is sum of (i <= n and j <= n and p <= n and q <= n) of a[i][j] - b[p][q]"

    We can use some prefix sums to solve this problem in O(n * m + q), using the observation that we can compute in O(1) the amount of 
modifications one can obtain.

*/
#include<bits/stdc++.h>
using namespace std;
ifstream f("tablou.in");
ofstream g("tablou.out");
int n, m, a[3002][3002], q, sp[3002][3002];
char c[3002][3002];
long long sum[100002];
int main()
{
    f >> n >> m;
    for(int i = 1; i <= n; ++i)
        f >> (c[i] + 1);
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
        {
            sp[i][j] = (c[i][j] - '0');
            sp[i][j] = sp[i][j] + sp[i-1][j] + sp[i][j-1] - sp[i-1][j-1];
        }
    f >> q;
    long long total = 0;
    for(int i = 1; i <= q; ++i)
    {
        int La, Ca, Lb, Cb, cul;
        f >> La >> Ca >> Lb >> Cb >> cul;
        long long org = sp[n][m] - (sp[Lb][Cb] - sp[La - 1][Cb] - sp[Lb][Ca - 1] + sp[La - 1][Ca - 1]);
        org = org + 1LL * (Cb - Ca + 1) * (Lb - La + 1) * cul;
        sum[i] = org;
        total += org;
    }
    for(int i = 1; i <= q; ++i)
    {
        total -= sum[i];
        long long ans = 1LL * n * m * ((q - 1) * sum[i] - total);
        g << ans << '\n';
        total += sum[i];
    }
    return 0;
}
