/*

                        POI 16-Nim

    Given the fact that the sum is at most 10000000, the number of distinct elements of the array will be at most sqrt(10000000).

    It is obvious that we need to count the number of subsets which can be removed such that we get to xorsum 0(which is a losing state for Alice,
therefore a winning state for Byteasar).

    The first observation is that we can use dp, dp[0/1][reminder by d of number of removed elements][xorsum] = number of subsets which
can be removed such that we get to such a state.

    In order to compute the subsequent values of the dp matrix, we are going to count how many subsets we can create
from the elements equal to some value x, with xorsum equal to a value x or to 0 and also with a given reminder by d. This can be done using combinatorics.

    When we will run through the elements(in descending order), we are going to update only states for which we're sure that we can get down to 0.
Namely, if we have a value x, we can bring xorsum to 0 only if the initial xorsum has at most the same amount of bits as x.

    For example, if we have x = 5, we will only run through xorsums between 0 and 7(5 is 101 and 7 is 111).

    Running this DP algorithm in O(sqrt(sum) * d^2 * max_value) (it has a very small constant) will bring you only 50 points, because of both TLE and MLE.

    One can further observe that if we have many distinct elements, and d is big, we won't have subsets with reminder by d equal to the bigger values, so we
can skip those iterations.

    Last but not least, in order to get full score, you need to run a bitmask DP for the biggest 20 numbers, such that you get rid of extra memory(you won't
run through big numbers which require lots of memory).

    Therefore, we are going to get a solution which runs fast enough to get 100.

    Tags: math, dp, combinatorics, bitmasks, games, implementation.

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
ll fact[500002], inv[500002];

int n, k, frq[1000002], dp[2][11][600002];

int C(int n, int k)
{
    return mul(fact[n], mul(inv[k], inv[n-k]));
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;
    int xorr = 0;
    fact[0] = inv[0] = 1;
    for(int i = 1; i <= n; ++i)
    {
        fact[i] = mul(fact[i-1], i);
        inv[i] = pw(fact[i], mod - 2);
    }
    for(int i = 1; i <= n; ++i)
    {
        int x;
        cin >> x;
        xorr ^= x;
        frq[x]++;
    }
    vector<int> vals;
    for(int i = 1000000; i >= 1; --i)
        while(frq[i] && vals.size() < 20)
            vals.pb(i), --frq[i];
    for(int i = 0; i < (1<<(vals.size())); ++i)
    {
        int xr = xorr;
        int rem = 0;
        for(int x = 0; x < vals.size(); ++x)
            if(i & (1<<x))
                xr ^= vals[x], ++rem;
        if(xr <= 600000)
            dp[0][rem%k][xr]++;
    }
    for(int i = 1000000; i >= 1; --i)
    {
        if(frq[i])
        {
            int maxp2 = 1;
            int ct[12][3];
            memset(ct, 0, sizeof(ct));
            for(int j = 0; j <= frq[i]; ++j)
            {
                int val = C(frq[i], j);
                if(j%2 == 0)
                    ct[j%k][0] = add(ct[j%k][0], val);
                else
                    ct[j%k][1] = add(ct[j%k][1], val);
            }
            while(maxp2 < i)
                maxp2 = maxp2 * 2 + 1;
            for(int nd = 0; nd < k; ++nd)
            {
                if(!ct[nd][0] && !ct[nd][1])
                    continue;
                for(int j = 0; j < k; ++j)
                    for(int x = maxp2; x >= 0; --x)
                    {
                        if(!dp[0][j][x])
                            continue;
                        if(j + nd < k)
                        {
                            dp[1][j + nd][(x ^ i)] = add(dp[1][j + nd][(x ^ i)], mul(dp[0][j][x], ct[nd][1]));
                            dp[1][j + nd][x] = add(dp[1][j + nd][x], mul(dp[0][j][x], ct[nd][0]));
                        }
                        else
                        {
                            dp[1][j + nd - k][(x ^ i)] = add(dp[1][j + nd - k][(x ^ i)], mul(dp[0][j][x], ct[nd][1]));
                            dp[1][j + nd - k][x] = add(dp[1][j + nd - k][x], mul(dp[0][j][x], ct[nd][0]));
                        }
                    }
            }
            for(int j = 0; j < k; ++j)
                for(int x = maxp2; x >= 0; --x)
                    dp[0][j][x] = dp[1][j][x], dp[1][j][x] = 0;
        }
    }
    cout << (dp[0][0][0] - (n%k == 0) + mod) % mod << '\n';
    return 0;
}
