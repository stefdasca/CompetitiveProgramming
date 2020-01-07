/*
        USACO 18jan-sprinklers-plat

    Let's create a prefix minimum array for the water part of the sprinkler, and a suffix maximum array for the
fertilizer part of the sprinkler.

    It can be observed that we can keep the fertilizer part of the sprinkler constant while iterating through the water part.
In order to do this in an efficient way, we need a two pointer approach.

    If we know the min value of the water range and max value of the fertilizer range, and we fix the ends of the rectangle, we can form
(max fertilizer - min water + 1) * (max fertilizer - min water) / 2 rectangles. Let's look a little bit at this formula. We can get rid of the /2
by multiplying at the end with modular inverse of 2(which is 500000004). Then, by dropping the brackets and doing the computing we will get
a^2 + a - 2ab + b^2 - b, where a is max fertilizer and b is min water.

    We can sum up the values of b which represent the eligible amounts of water using the same two pointer approach and then use the formulas above to find
the answer.


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

#define fisier 1

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

int p[100002];
int n, wat[100002], fer[100002];
int main()
{

    #ifdef fisier
        ifstream f("sprinklers.in");
        ofstream g("sprinklers.out");
    #endif
   // ios_base::sync_with_stdio(false);
   // cin.tie(NULL);
    f >> n;
    for(int i = 1; i <= n; ++i)
    {
        int a, b;
        f >> a >> b;
        p[a] = b;
    }
    for(int i = 0; i < n; ++i)
    {
        if(i == 0)
            wat[i] = p[i];
        else
            wat[i] = min(wat[i-1], p[i]);
    }
    for(int i = n-1; i >= 0; --i)
    {
        if(i == n-1)
            fer[i] = p[i];
        else
            fer[i] = max(fer[i+1], p[i]);
    }
    ll ans = 0;
    ll spp = 0;
    ll snr = 0;
    int pmx = 0;
    for(int i = 0; i < n; ++i)
    {
        if(i >= 1)
        {
            spp = add(spp, mul(wat[i-1], wat[i-1]));
            snr = add(snr, wat[i-1]);
            while(pmx < i && wat[pmx] >= fer[i])
            {
                spp = add(spp, -mul(wat[pmx], wat[pmx]));
                snr = add(snr, -wat[pmx]);
                ++pmx;
            }
        }
        ans = add(ans, mul(i - pmx, mul(fer[i], fer[i])));
        ans = add(ans, mul(i - pmx, fer[i]));
        ans = add(ans, spp);
        ans = add(ans, -snr);
        ans = add(ans, -mul(2 * fer[i], snr));
    }
    g << mul(ans, 500000004);
    return 0;
}
