/*
            POI 04-Maximal

    We can reduce the problem to finding the maximum value of lcm(x1, x2, ..., xn)
such that x1 + x2 + ... + xn = n.

    It's easy to observe that those values have to be prime, so we're going to do DP
on max product. One can either use big integers or "logarithmate" the product.

    "Logarithmation" of product(I don't know the english term for this) is basically transforming
a product into a sum of logarithms, since the logarithm of the product is the sum of logarithms in
the parts of the product.

*/

#include<bits/stdc++.h>
using namespace std;
int n, pr, zz;
float dp[10002][402], lg[10002];
int lst[10002][402];
int rad[1002];
void tri(int nr)
{
    ++zz;
    for(int i = nr; i <= n; i *= nr)
        rad[i] = zz;
    for(int i = n; i >= 1; --i)
    {
        dp[i][zz] = dp[i][zz-1];
        lst[i][zz] = lst[i][zz-1];
        for(int j = nr; j <= i; j *= nr)
        {
            if(dp[i - j][zz-1] + lg[j] > dp[i][zz])
            {
                dp[i][zz] = dp[i - j][zz-1] + lg[j];
                lst[i][zz] = j;
            }
        }
    }
}
int trs[10002], len;
bool pus[10002];
void fnd(int a, int b)
{
    if(dp[a][b] == 0)
    {
        for(int i = 1; i <= a; ++i)
            trs[++len] = 1;
        return;
    }
    int nr = lst[a][b];
    fnd(a - nr, rad[nr] - 1);
    trs[++len] = nr;
}
int main()
{
    int t;
    cin >> t;
    for(int i = 2; i <= 10000; ++i)
        lg[i] = log(i);
    for(; t; --t)
    {
        cin >> n;
        zz = 0;
        len = 0;
        memset(pus, 0, sizeof(pus));
        memset(trs, 0, sizeof(trs));
        for(int i = 2; i <= n; ++i)
            if(!pus[i])
            {
                for(int j = i; j <= n; j += i)
                    pus[j] = 1;
                int z = i;
                tri(i);
                if(zz >= 400)
                    break;
            }
        fnd(n, zz);
        zz = 1;
        sort(trs + 1, trs + len + 1);
        for(int i = 1; i <= len; ++i)
        {
            for(int j = 1; j < trs[i]; ++j)
                cout << zz + j << " ";
            cout << zz << " ";
            zz += trs[i];
        }
        cout << '\n';
    }
    return 0;
}
