/*
            COCI 06-Debug

    We can use hashing in order to find the answer. In order to speed up the algorithm, we are going to iterate in reverse order of
the answers and we are going to break every time we can/can't find an answer.

    This can be done faster if we compute some more hashes along the way, but this is not necessary.


*/
#include<bits/stdc++.h>
#define god dimasi5eks
#pragma GCC optimize("O3")
#define fi first
#define se second
#define pb push_back
#define pf push_front
#define mod 1000000007
#define dancila 3.14159265359
#define eps 1e-9

// #define fisier 1

using namespace std;

typedef long long ll;

const int base = 257;

int n, m;
char mat[302][302];
ll hsh[302][302], hsh2[302][302], pw[302];

ll compute(int L, int Ca, int Cb)
{
    ll ans = hsh[L][Cb] - ((hsh[L][Ca - 1] * pw[Cb - Ca + 1]) % mod) + mod;
    if(ans >= mod)
        ans -= mod;
    return ans;
}
ll compute2(int L, int Ca, int Cb)
{
    ll ans = hsh2[L][Cb] - ((hsh2[L][Ca + 1] * pw[Ca - Cb + 1]) % mod) + mod;
    if(ans >= mod)
        ans -= mod;
    return ans;
}
bool tri(int le)
{
    for(int i = 1; i + le - 1 <= n; ++i)
        for(int j = 1; j + le - 1 <= m; ++j)
        {
            bool ok = 1;
            for(int a = i, b = i + le - 1; a <= b; ++a, --b)
            {
                if(compute(a, j, j + le - 1) != compute2(b, j + le - 1, j))
                {
                    ok = 0;
                    break;
                }
            }
            if(ok)
                return 1;
        }
    return 0;
}
int main()
{

    #ifdef fisier
        ifstream f("input.in");
        ofstream g("output.out");
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i = 1; i <= n; ++i)
        cin >> (mat[i] + 1);
    pw[0] = 1;
    for(int i = 1; i <= 300; ++i)
        pw[i] = (pw[i-1] * base) % mod;
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= m; ++j)
            hsh[i][j] = (hsh[i][j-1] * base + (mat[i][j] - '0' + 1)) % mod;
        for(int j = m; j >= 1; --j)
            hsh2[i][j] = (hsh2[i][j+1] * base + (mat[i][j] - '0' + 1)) % mod;
    }
    for(int i = min(n, m); i >= 2; --i)
        if(tri(i))
        {
            cout << i;
            return 0;
        }
    cout << -1;
    return 0;
}
