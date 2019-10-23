/*
        CF789-D2-E

    * My solution combines the editorial's approach(BFS from 0 and find a zero-sum cycle)
with an important observation: If we have many concentrations available, then we can run an
O(n^3) dp which will work very fast if we know many concentrations.

    * Basically, I start with BFS and if I need too many iterations, I switch to the DP solution in
order to avoid TLE.

    * The dp solution is a recursive one, which tries to combine for a concentration i, all the pairs of concentration of type
(a, b), with a < i < b, using some math.

*/
#include<bits/stdc++.h>
#define god dimasi5eks
#pragma GCC optimize("O3")
#define fi first
#define se second
#define pb push_back
#define pf push_front
#define mod 1000000007

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
bool is[1002];

int n, k, dp[1002], minii, maxii;

int calcdp(int nr)
{
    if(is[nr])
        return dp[nr];
    is[nr] = 1;
    dp[nr] = (1<<14);
    if(nr == 0)
        return dp[nr];
    for(int i = minii; i < nr; ++i)
    {
        calcdp(i);
        if(dp[i] <= dp[nr])
            for(int j = nr + 1; j <= maxii; ++j)
            {
                int difa = (nr - i) * dp[i];
                int difb = (j - nr) * calcdp(j);
                int x = cmmdc(difa, difb);
                difa /= x;
                difb /= x;
                dp[nr] = min(dp[nr], difb * dp[i] + difa * dp[j]);
            }
    }
    return dp[nr];
}
int viz[1000002];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;
    int dist = 0;
    vector<int>di;
    for(int i = 1; i <= k; ++i)
    {
        int nr;
        cin >> nr;
        if(i == 1)
            minii = maxii = nr;
        else
        {
            minii = min(minii, nr);
            maxii = max(maxii, nr);
        }
        if(!is[nr])
            ++dist, di.pb(nr);
        is[nr] = 1;
        dp[nr] = 1;
    }
    if(n > maxii || n < minii)
    {
        cout << -1;
        return 0;
    }
    if(n == 0)
    {
        cout << 1;
        return 0;
    }
    deque<pair<int, int> >d;
    d.pb({0, 0});
    int ct = 0;
    while(!d.empty())
    {
        pair<int, int> x = d[0];
        ++ct;
        if(ct >= 2000000)
            break;
        d.pop_front();
        for(int j = 0; j < dist; ++j)
        {
            int ne_pos = x.fi + di[j];
            if(viz[ne_pos] < x.se + 1)
            {
                viz[ne_pos] = x.se + 1;
                d.pb({ne_pos, x.se + 1});
                if(ne_pos == n * (x.se + 1))
                {
                    cout << x.se + 1;
                    return 0;
                }
            }
        }
    }

    calcdp(n);
    if(!is[n] || dp[n] == (1<<14))
        cout << -1;
    else
        cout << dp[n];
    return 0;
}
