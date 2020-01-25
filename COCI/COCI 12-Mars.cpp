/*
        COCI 12-Mars

    We can use dp to find the answer. One can observe that based on the position we are going to fill at the current step,
our set of states is restricted(the criteria is the lowest bit of the current position).

    Even though it may look like we're going to add some numbers more than once, actually it's not the case(it can be proved by induction).

    Therefore, the solution will run in O(k^2 log k), where we will consider k to be equal to the size of the matrix(2^(original value of k)).

    detailed editorial + alternative O(k^3) approach - https://github.com/mostafa-saad/MyCompetitiveProgramming/blob/master/Olympiad/COCI/official/2013/contest1_solutions/solutions.pdf

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
int k;
int mat[520][520], dp[520][520];

int main()
{

    #ifdef fisier
        ifstream f("input.in");
        ofstream g("output.out");
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> k;
    k = (1<<k);
    for(int i = 0; i < k; ++i)
        for(int j = 0; j < k; ++j)
            cin >> mat[i][j];

    for(int i = 0; i < k; ++i)
        for(int j = 0; j < k; ++j)
            dp[i][j] = 1000000000;

    for(int i = 0; i < k; ++i)
        dp[0][i] = 0;
    for(int i = 1; i < k; ++i)
    {
        int lobit = (i & -i);
        for(int prev = 0; prev < k; ++prev)
        {
            int st = (prev ^ lobit) & ~(lobit - 1);
            int dr = st + lobit - 1;
            for(int curr = st; curr <= dr; ++curr)
                dp[i][curr] = min(dp[i][curr], dp[i - 1][prev] + mat[prev][curr]);
        }
    }

    int ans = 1000000000;
    for(int i = 0; i < k; ++i)
        ans = min(ans, dp[k - 1][i]);
    cout << ans;
    return 0;
}
