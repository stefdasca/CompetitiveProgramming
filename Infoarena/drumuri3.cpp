/*
        Infoarena drumuri3


    "Given a connected graph with n nodes and m edges, as well as q queries and a length k,
find for each query the number of paths from ai to bi of length at most k(length is given in nodes)"


    This problem can be solved using divide and conquer technique, based on matrix exponentiation.
At each step, we're going to raise the adjacency matrix to the square, and if necessary, to
multiply it by adjacency matrix.

*/
#include<bits/stdc++.h>
#define mod 10007
using namespace std;
ifstream f("drumuri3.in");
ofstream g("drumuri3.out");
int n, m, k, q, adj[105][105];
int a[105][105], sol[105][105], aux[105][105], r[105][105];
void mult(int a[105][105], int b[105][105], int c[105][105])
{
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
        {
            c[i][j] = 0;
            for(int k = 1; k <= n; k++)
                c[i][j] = (c[i][j] + a[i][k] * b[k][j]) % mod;
        }
}
void solve(int k, int a[105][105], int b[105][105])
{
    if(k == 1)
    {
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                b[i][j] = a[i][j] = adj[i][j];
        return;
    }
    int a2[105][105], b2[105][105];
    solve(k / 2, a2, b2);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
        {
            r[i][j] = a2[i][j];
            if(i == j)
                r[i][j]++;
        }
    mult(b2, r, b);
    mult(a2, a2, a);
    if(k % 2 == 0)
        return;
    mult(adj, a, aux);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            a[i][j] = aux[i][j];
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            b[i][j] = (b[i][j] + a[i][j]) % mod;
}
int main()
{
    f >> n >> m >> k >> q;
    --k;
    for(int i = 1; i <= m; ++i)
    {
        int a, b;
        f >> a >> b;
        adj[a][b] = adj[b][a] = 1;
    }
    solve(k, a, sol);
    for(int i = 1; i <= q; ++i)
    {
        int a, b;
        f >> a >> b;
        g << sol[a][b] << '\n';
    }
    return 0;
}
