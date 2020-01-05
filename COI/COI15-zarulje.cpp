/*

            COI 15-zarulje

    Let's keep the important light bulbs from right to left using stack. At each step, we will remove from the stack the elements bigger than
the current element and add those updates in an update list.

    Then, let's do the same from left to right, but unlike for the previous traversal, we are going to update the answer for each i from 1 to n.
When we are at a position i, we are going to reverse the "previous states" marked by the items in the update list at position i, initialize the answer
for the start position = i, and then drop the bigger elements from the stack, like we did at the previous traversal, while keeping track of the value of the
answer in a similar fashion.

    How do we update the answer?

    Let's say we know the count of elements equal to x at right and left(frq[i], respectively frq2[i]). If we have such a group, the answer is going to be
multiplied by (frq[i] + frq2[i] choose frq[i]), and when we modify the answer, we need to divide by (frq[i] + frq2[i] choose frq[i]). This can be dealt with
by precomputing the factorials and the modular inverses.

    Therefore, we get an algorithm which runs in amortized O(n), because of precomputing the modular inverses in O(n) instead of usual O(n log n) approach.

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

// #define fisier

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
int n, k, val, v[200002];
ll fact[200002], inv[200002];
ll C(int n, int k)
{
    return mul(fact[n], mul(inv[k], inv[n-k]));
}

ll ans[200002], ways, frq[200002], frq2[200002];
vector<pair<int, int> >upds[200002];
int main()
{

    #ifdef fisier
        ifstream f("input.in");
        ofstream g("output.out");
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;
    for(int i = 1; i <= n; ++i)
        cin >> v[i];
    fact[0] = inv[0] = 1;
    for(int i = 1; i <= n; ++i)
        fact[i] = mul(fact[i-1], i);

    // amortized O(n) modular inverse for all of i! from 1 to n
    inv[n] = pw(fact[n], mod - 2);
    for(int i = n-1; i >= 1; --i)
        inv[i] = mul(inv[i+1], i+1);
    deque<int> d;
    for(int i = n; i >= 1; --i)
    {
        while(!d.empty() && v[d.back()] > v[i])
        {
            --frq[v[d.back()]];
            upds[i].pb({v[d.back()], 1});
            d.pop_back();
        }
        upds[i].pb({v[i], -1});
        frq[v[i]]++;
        d.pb(i);
    }
    d.clear();
    ways = 1;
    for(int i = 1; i <= n; ++i)
    {
        for(int x = 0; x < upds[i].size(); ++x)
        {
            int va = upds[i][x].fi;
            int ct = upds[i][x].se;
            ways = mul(ways, mul(inv[frq[va] + frq2[va]], mul(fact[frq[va]], fact[frq2[va]])));
            frq[va] += ct;
            ways = mul(ways, mul(fact[frq[va] + frq2[va]], mul(inv[frq[va]], inv[frq2[va]])));
        }
        ans[i] = ways;
        while(!d.empty() && v[i] < v[d.back()])
        {
            int va = v[d.back()];
            ways = mul(ways, mul(inv[frq[va] + frq2[va]], mul(fact[frq[va]], fact[frq2[va]])));
            --frq2[va];
            ways = mul(ways, mul(fact[frq[va] + frq2[va]], mul(inv[frq[va]], inv[frq2[va]])));
            d.pop_back();
        }
        int va = v[i];
        ways = mul(ways, mul(inv[frq[va] + frq2[va]], mul(fact[frq[va]], fact[frq2[va]])));
        ++frq2[va];
        ways = mul(ways, mul(fact[frq[va] + frq2[va]], mul(inv[frq[va]], inv[frq2[va]])));
        d.pb(i);
    }
    for(; k; --k)
    {
        cin >> val;
        cout << ans[val] << '\n';
    }
    return 0;
}
