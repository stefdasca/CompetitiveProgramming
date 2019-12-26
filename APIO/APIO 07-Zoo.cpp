/*
                    APIO 07-Zoo

    We are going to fix whether we took the first 5 animals or not using a bitmask, and run a bitmask dp algorithm:

    dp[i][j] = max number of kids which can be made happy if we checked the kids which can see the first i animals and the last 5 animals have mask j.

    In order to deal with kids which can see animals in range [x, y], with x > y (for example, L-2, L-1, L, 1, 2), we have to check them manually using
the fixed bitmask.

    One also has to precompute bun[i][j] = max number of kids which can be made happy if we checked only the kids which can see the animals in range [i-4, i]
and those 5 animals have mask j.


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

using namespace std;

typedef long long ll;


int add(int a, int b)
{
    ll x = a+b;
    if(x >= mod)
        x -= mod;
    if(x < 0)
        x += mod;
    return x;
}
ll mul(ll a, ll b)
{
    return (a*b) % mod;
}

ll pw(ll a, ll b)
{
    ll ans = 1;
    while(b)
    {
        if(b & 1)
            ans = (ans * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return ans;
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
long long rand_seed()
{
    long long a = rng();
    return a;
}
int l, n;
struct kid
{
    int st;
    vector<int> gg;
    vector<int> ngg;
};
kid v[50002];
vector<int> st[10002];
int dp[10002][35];
bool viz[10002][35];
int bun[10002][35];
int solve(int msk)
{
    viz[5][msk] = 1;
    int ans = 0;
    for(int i = 5; i <= l; ++i)
    {
        for(int lst = 0; lst <= 31; ++lst)
        {
            if(!viz[i][lst])
                continue;
            dp[i][lst] += bun[i][lst];
            if(i < l)
            {
                int zz = (lst & 15);
                viz[i+1][zz * 2] = 1;
                dp[i+1][zz * 2] = max(dp[i+1][zz * 2], dp[i][lst]);
                viz[i+1][zz * 2 + 1] = 1;
                dp[i+1][zz * 2 + 1] = max(dp[i+1][zz * 2 + 1], dp[i][lst]);
            }
            ans = max(ans, dp[i][lst]);
        }
    }
    for(int lst = 0; lst <= 31; ++lst)
    {
        int stt = l - 3;
        int rl = lst;
        int pz = 4;
        int vall = dp[l][lst];
        while(stt <= l)
        {
            rl = (rl & 15);
            rl <<= 1;
            if(msk & (1<<pz))
                rl++;
            for(int x = 0; x < st[stt].size(); ++x)
            {
                int pz = st[stt][x];
                bool bun = 0;
                for(int j = 0; j < v[pz].ngg.size(); ++j)
                {
                    int qq = v[pz].ngg[j];
                    if(qq < stt)
                        qq += l;
                    if(rl & (1<<(4 - (qq - stt))))
                        bun = 1;
                }
                for(int j = 0; j < v[pz].gg.size(); ++j)
                {
                    int qq = v[pz].gg[j];
                    if(qq < stt)
                        qq += l;
                    if(!(rl & (1<<(4 - (qq - stt)))))
                        bun = 1;
                }
                if(bun)
                    vall++;
            }
            ++stt;
            --pz;
        }
        ans = max(ans, vall);
    }
    for(int i = 1; i <= l; ++i)
        for(int j = 0; j <= 31; ++j)
            dp[i][j] = 0, viz[i][j] = 0;
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    for(; t; --t)
    {
        cin >> l >> n;
        for(int i = 1; i <= n; ++i)
        {
            cin >> v[i].st;
            st[v[i].st].pb(i);
            int a, b;
            cin >> a >> b;
            for(int j = 1; j <= a; ++j)
            {
                int x;
                cin >> x;
                v[i].ngg.pb(x);
            }
            for(int j = 1; j <= b; ++j)
            {
                int x;
                cin >> x;
                v[i].gg.pb(x);
            }
        }
        for(int i = 5; i <= l; ++i)
        {
            for(int lst = 0; lst <= 31; ++lst)
            {
                for(int x = 0; x < st[i - 4].size(); ++x)
                {
                    int pz = st[i - 4][x];
                    bool bbun = 0;
                    for(int j = 0; j < v[pz].ngg.size(); ++j)
                    {
                        int qq = v[pz].ngg[j];
                        if(lst & (1<<(i - qq)))
                            bbun = 1;
                    }
                    for(int j = 0; j < v[pz].gg.size(); ++j)
                    {
                        int qq = v[pz].gg[j];
                        if(!(lst & (1<<(i - qq))))
                            bbun = 1;
                    }
                    if(bbun)
                        bun[i][lst]++;
                }
            }
        }
        int ans = 0;
        for(int i = 0; i <= 31; ++i)
            ans = max(ans, solve(i));
        for(int i = 1; i <= n; ++i)
        {
            v[i].st = 0;
            v[i].gg.clear();
            v[i].ngg.clear();
        }
        for(int i = 1; i <= l; ++i)
            st[i].clear();
        for(int i = 0; i <= l; ++i)
            for(int j = 0; j <= 31; ++j)
                bun[i][j] = 0;
        cout << ans << '\n';
    }
    return 0;
}
