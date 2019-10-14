/*
        COCI 09-Palacinke

    * Given that T is huge, we can't use straightforward DP to compute the answer, so we will have to use
matrix exponentiation

    * We are going to find the number of paths ending at node 1 which respect the required conditions.
By marking the edges of the graph with 1 in the 2*n+1 sized matrix we can then raise the matrix at the Tth
power to find the answer.

    * Since we will get invalid paths in the answer, we need to use inclusion-exclusion to compute the exact answer.

*/
#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#define fi first
#define se second
#define pb push_back
#define pf push_front
#define mod 5557

using namespace std;

typedef long long ll;

int n;
void mult(int a[2 * 25 + 1][2 * 25 + 1], int b[2 * 25 + 1][2 * 25 + 1], int c[2 * 25 + 1][2 * 25 + 1])
{
    int tmp[2 * 25 + 1][2 * 25 + 1];
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
        {
            tmp[i][j] = 0;
            for(int k = 0; k < n; ++k)
                tmp[i][j] += a[i][k] * b[k][j];
        }
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
            c[i][j] = tmp[i][j] % mod;
}

int id(int u, int t)
{
    return 1 + u*2 + t;
}

int N, M, T;
struct edge
{
    int u, v, mask;
};
edge E[502];
int solve(int mask)
{
    int A[2 * 25 + 1][2 * 25 + 1];
    int B[2 * 25 + 1][2 * 25 + 1];
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
        {
            A[i][j] = 0;
            B[i][j] = (i == j);
        }
    A[0][0] = 1;
    for(int u = 0; u < N; ++u)
        A[id(u, 1)][id(u, 0)] = 1;

    for(int i = 0; i < M; ++i)
    {
        ++A[id(E[i].v, 0)][id(E[i].u, 0)];
        if(!(E[i].mask & mask))
            ++A[id(E[i].v, 0)][id(E[i].u, 1)];
        if(E[i].v == 0)
        {
            ++A[0][id(E[i].u, 0)];
            if(!(E[i].mask & mask))
                ++A[0][id(E[i].u, 1)];
        }
    }

    int k = T;
    while(k)
    {
        if(k & 1)
            mult(B, A, B);
        mult(A, A, A);
        k /= 2;
    }
    return B[0][id(0, 0)];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    n = 1 + 2*N;
    for(int i = 0; i < M; ++i)
    {
        string s;
        cin >> E[i].u >> E[i].v >> s;
        --E[i].u;
        --E[i].v;
        for(int j = 0; j < s.size(); ++j)
        {
            if(s[j] == 'B')
                E[i].mask |= 1;
            if(s[j] == 'J')
                E[i].mask |= 2;
            if(s[j] == 'M')
                E[i].mask |= 4;
            if(s[j] == 'P')
                E[i].mask |= 8;
        }
    }
    cin >> T;
    int ans = 0;
    for(int mask = 0; mask < 16; ++mask)
    {
        int sgn = 1;
        for(int i = 0; i < 4; ++i)
            if(mask & (1<<i))
                sgn = -sgn;
        ans += sgn * solve(mask);
    }
    cout << (ans % mod + mod) % mod;
    return 0;
}
