/*
        COCI 2009-10, contest 6 - Gremlini

    It is obvious that we will use dp to solve this problem. Since t is big, we are going to use matrix
exponentiation to solve this problem. Let's note mt[i][j][k] = the minimal amount of time to get 2^i ancestors,
if we get a gremlin of type j, hatched by k.

    After we do the matrix exponentiation, we will binary search on the answer and use the previously calculated matrixes to see whether
we can get additional 2^j gremlins on an ancestral line.

*/

#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
long long n, t;
long long countt[102], timp[102], nxt[1002], curr[1002];
struct fii
{
    int a, b;
};
fii v[102][1002];
long long mt[52][102][102];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> t;
    for(int i = 1; i <= n; ++i)
    {
        cin >> countt[i] >> timp[i];
        for(int j = 1; j <= countt[i]; ++j)
            cin >> v[i][j].a;
        for(int j = 1; j <= countt[i]; ++j)
            cin >> v[i][j].b;
    }
    for(int i = 0; (1LL<<i) <= t; ++i)
        for(int j = 0; j <= 100; ++j)
            for(int k = 0; k <= 100; ++k)
                mt[i][j][k] = (1LL<<60);
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= countt[i]; ++j)
            mt[0][v[i][j].a][i] = min(mt[0][v[i][j].a][i], timp[i] + v[i][j].b);
    int p = 1;
    for(; (1LL << p) <= t; ++p)
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= n; ++j)
                for(int k = 1; k <= n; ++k)
                    mt[p][i][j] = min(mt[p][i][j], mt[p-1][i][k] + mt[p-1][k][j]);
    long long rez = 0;
    for(--p; p >= 0; --p)
    {
        long long mn = (1LL<<60);
        for(int i = 1; i <= n; ++i)
            nxt[i] = (1LL<<60);
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= n; ++j)
            {
                nxt[i] = min(nxt[i], curr[j] + mt[p][i][j]);
                mn = min(mn, nxt[i]);
            }
        if(mn <= t)
        {
            rez += (1LL << p);
            for(int i = 0; i <= n; ++i)
                curr[i] = nxt[i];
        }
    }
    cout << rez;
    return 0;
}

