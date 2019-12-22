/*
        IZhO 17-bootfall

    Do knapsack for the initial n items. We will store count[i] = how many subsets have sum i, mod some big prime.

    When we want to remove 1 item, we have to reverse the knapsack and then revert back to the initial state.

    At the end, we need to check how many differences appear in all of the n removals, and this can be counted with a frequency array.

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
int n;
int v[502];

int frq[1000002];
bool dp[250002];
int ct[250002], ct2[250002];
int fi[250002];
int lst[250002];
bool canruk(int lack)
{
    int sm = 0;
    for(int i = 1; i <= n; ++i)
        if(i != lack)
            sm += v[i];
    if(lack == 0)
    {
        int mxval = 0;
        dp[0] = 1;
        ct[0] = 1;
        for(int i = 1; i <= n; ++i)
        {
            for(int j = mxval; j >= 0; --j)
                if(dp[j])
                {
                    ct[j + v[i]] = add(ct[j + v[i]], ct[j]);
                    if(!fi[j + v[i]])
                        fi[j + v[i]] = i;
                    lst[j + v[i]] = i;
                    dp[j + v[i]] = 1;
                }
            mxval += v[i];
        }
        if(mxval % 2 == 0 && dp[mxval / 2])
            return 1;
        return 0;
    }
    else
    {
        for(int j = 0; j <= sm + v[lack]; ++j)
            ct2[j] = ct[j];
        for(int j = v[lack]; j <= sm + v[lack]; ++j)
            ct[j] = add(ct[j], -ct[j - v[lack]]);
        for(int i = 0; i <= sm/2; ++i)
            if(ct[i])
                frq[sm - 2 * i]++;
        for(int j = 0; j <= sm + v[lack]; ++j)
            ct[j] = ct2[j];
        return 1;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> v[i];
    sort(v+1, v+n+1);
    if(!canruk(0))
    {
        cout << 0;
        return 0;
    }
    for(int i = 1; i <= n; ++i)
        canruk(i);
    int nrok = 0;
    for(int i = 0; i <= 1000000; ++i)
        if(frq[i] == n)
            ++nrok;
    cout << nrok << '\n';
    for(int i = 0; i <= 1000000; ++i)
        if(frq[i] == n)
            cout << i << " ";
    return 0;
}
