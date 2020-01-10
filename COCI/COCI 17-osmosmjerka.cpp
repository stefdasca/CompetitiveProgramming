/*
            COCI 17-osmosmjerka

    For n = m, we can find the rolling hashes of size min(k, n) and count with a map or by sorting the number of equal pairs.

    Let's extend this approach for n != m. We can observe that our period will be at most n*m. Since we can't build all the matrix, we will
need to compute the hashes for each string in a binary lifting like approach for all the possible 8 directions.

*/
#include<bits/stdc++.h>
#define god dimasi5eks
#pragma GCC optimize("O3")
#define fi first
#define se second
#define pb push_back
#define pf push_front
#define mod 1000000009
#define mod2 1000000007
#define dancila 3.14159265359
#define eps 1e-9

// #define fisier 1

using namespace std;

typedef long long ll;

ll cmmdc(ll a, ll b)
{
    while(b)
    {
        ll c = a%b;
        a = b;
        b = c;
    }
    return a;
}

int n, m, k;

char mat[502][502];

ll pwmd[502], pwmd2[502];
ll hsh0[502][502], hsh1[502][502];
ll nsh0[502][502], nsh1[502][502];
ll ps[2][502][502], ps2[2][502][502];

vector<ll> hshlist;

void solve(int x, int y)
{
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
        {
            ps[0][i][j] = ps2[0][i][j] = mat[i][j];
            hsh0[i][j] = hsh1[i][j] = 0;
        }

    for(int pw = 1; pw <= 19; ++pw)
    {
        int ac = pw % 2;
        int prv = (ac ^ 1);
        if((k & (1<<(pw-1))))
        {
            for(int i = 0; i < n; ++i)
                for(int j = 0; j < m; ++j)
                {
                    int prvx = i - (1<<(pw-1)) * x;
                    int prvy = j - (1<<(pw-1)) * y;
                    prvx %= n;
                    if(prvx < 0)
                        prvx += n;
                    prvy %= m;
                    if(prvy < 0)
                        prvy += m;
                    nsh0[i][j] = (hsh0[prvx][prvy] * pwmd[pw-1] + ps[prv][i][j]) % mod;
                    nsh1[i][j] = (hsh1[prvx][prvy] * pwmd2[pw-1] + ps2[prv][i][j]) % mod2;
                }
            memcpy(hsh0, nsh0, sizeof(hsh0));
            memcpy(hsh1, nsh1, sizeof(hsh1));
        }
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j)
            {
                int prvx = i - (1<<(pw-1)) * x;
                int prvy = j - (1<<(pw-1)) * y;
                prvx %= n;
                if(prvx < 0)
                    prvx += n;
                prvy %= m;
                if(prvy < 0)
                    prvy += m;
                ps[ac][i][j] = (ps[prv][prvx][prvy] * pwmd[pw-1] + ps[prv][i][j]) % mod;
                ps2[ac][i][j] = (ps2[prv][prvx][prvy] * pwmd2[pw-1] + ps2[prv][i][j]) % mod2;
            }
    }
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j)
            hshlist.pb({1LL * mod2 * hsh0[i][j] + hsh1[i][j]});
}
int main()
{

#ifdef fisier
    ifstream f("input.in");
    ofstream g("output.out");
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> k;
    k = min(k, n * m);
    for(int i = 0; i < n; ++i)
        cin >> mat[i];
    pwmd[0] = 257;
    pwmd2[0] = 257;
    for(int i = 1; i <= 501; ++i)
    {
        pwmd[i] = (pwmd[i-1] * pwmd[i-1]) % mod;
        pwmd2[i] = (pwmd2[i-1] * pwmd2[i-1]) % mod2;
    }

    for(int i = -1; i <= 1; ++i)
        for(int j = -1; j <= 1; ++j)
            if(i != 0 || j != 0)
                solve(i, j);
    ll num = 0;
    ll den = 1LL * n * m * 8;
    den *= den;
    sort(hshlist.begin(), hshlist.end());
    for(int i = 0; i < hshlist.size();)
    {
        int j = i;
        while(j < hshlist.size() && hshlist[j] == hshlist[i])
            ++j;
        num += 1LL * (j - i) * (j - i);
        i = j;
    }
    ll dc = cmmdc(num, den);
    cout << num/dc << "/" << den/dc << '\n';
    return 0;
}
