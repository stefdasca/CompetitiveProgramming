/*
        CEOI 04-Sweets

    Let's use inclusion-exclusion. For every possible subset, we will find using stars-and-bars method the number of ways to
choose candies such that we get to mxsum - sum, where mxsum is the maximum allowed sum and sum is the sum of elements in the chosen set.

    That number of ways is mxsum - sum choose n, which can be computed "by hand" using fraction reduction.

    As it is usual for problems which require count of ways to do something, in some range, we will rewrite the range [a, b]
in [0, b] and [0, a-1], which are way easier to compute.

*/

#include<bits/stdc++.h>
#define god dimasi5eks
#pragma GCC optimize("O3")
#define fi first
#define se second
#define pb push_back
#define pf push_front
#define mod 2004
#define dancila 3.14159265359
#define eps 1e-9

// #define fisier

using namespace std;

typedef long long ll;


int add(int a, int b)
{
    int x = a+b;
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
int n, a, b, v[12], sp[12];

int cmmdc(int a, int b)
{
    while(b)
    {
        int c = a%b;
        a = b;
        b = c;
    }
    return a;
}

int C(int n, int k)
{
    if(n < k)
        return 0;
    vector<int> mare, mic;
    for(int i = n - k + 1; i <= n; ++i)
        mare.pb(i);
    for(int i = 1; i <= k; ++i)
        mic.pb(i);
    for(int i = 0; i < mare.size(); ++i)
        for(int j = 0; j < mic.size(); ++j)
        {
            int gc = cmmdc(mare[i], mic[j]);
            mare[i] /= gc;
            mic[j] /= gc;
        }
    int ans = 1;
    for(int i = 0; i < mare.size(); ++i)
        ans = mul(ans, mare[i]);
    return ans;
}

int solve(int mxsum)
{
    int ans = 0;
    for(int i = 0; i < (1<<n); ++i)
    {
        int sum = mxsum;
        int ct = 0;
        for(int j = 0; j < n; ++j)
            if(i & (1<<j))
                sum -= (v[j] + 1), ++ct;
        if(ct & 1)
            ans = add(ans, -C(sum + n, n));
        else
            ans = add(ans, C(sum + n, n));
    }
    return ans;
}
int main()
{

    #ifdef fisier
        ifstream f("input.in");
        ofstream g("output.out");
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> a >> b;
    for(int i = 0; i < n; ++i)
        cin >> v[i];
    cout << add(solve(b), -solve(a-1));
    return 0;
}
