/*
                COCI 07-Cestarine

    solution: https://github.com/mostafa-saad/MyCompetitiveProgramming/blob/master/Olympiad/COCI/official/2008/contest6_solutions/solutions.pdf

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
deque<int> intr, ies;

ll dp[100002];

ll tri(int a, int b)
{
    vector<int> v;
    vector<int> v2;
    for(int x = a; x <= b; ++x)
        v.pb(ies[x]), v2.pb(intr[x]);
    ll gg = (1LL<<50);
    do{
        ll cost = 0;
        for(int i = 0; i < v.size(); ++i)
        {
            if(v[i] == v2[i])
                cost += (1LL<<50);
            cost += abs(v[i] - v2[i]);
        }
        gg = min(gg, cost);
    }while(next_permutation(v.begin(), v.end()));
    return gg;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i)
    {
        int a, b;
        cin >> a >> b;
        intr.pb(a);
        ies.pb(b);
    }
    intr.push_front(0);
    ies.push_front(0);
    sort(intr.begin(), intr.end());
    sort(ies.begin(), ies.end());
    dp[1] = (1LL<<50);
    for(int i = 2; i <= n; ++i)
    {
        dp[i] = (1LL<<50);
        if(intr[i] != ies[i])
            dp[i] = min(dp[i], abs(intr[i] - ies[i]) + dp[i-1]);
        dp[i] = min(dp[i], tri(i-1, i) + dp[i-2]);
        if(i >= 3)
            dp[i] = min(dp[i], tri(i-2, i) + dp[i-3]);
    }
    cout << dp[n];
    return 0;
}

