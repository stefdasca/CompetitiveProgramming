/*
        SRM416-D1-500

    Let's run any brute force algorithm for the first few possible sums. One can observe either by hand or
by using OEIS(https://oeis.org/A001402) that the sequence has a recurrence relation, which we are going to implement it.

*/
#include<bits/stdc++.h>
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
    while(x >= mod)
        x -= mod;
    while(x < 0)
        x += mod;
    return x;
}
ll mul(ll a, ll b)
{
    return (a*b) % mod;
}

int n;
int ans;
int ct[6000002];


class CustomDice
{
     public:
        int countDice(int M)
        {
            ct[21] = 1;
            for(int pz = 22; pz <= 6000000; ++pz)
            {
                int ans = add(ct[pz-1], ct[pz-2]);
                ans = add(ans, add(-ct[pz-5], -ct[pz-7]));
                ans = add(ans, add(ct[pz-9], ct[pz-10]));
                ans = add(ans, add(ct[pz-11], ct[pz-12]));
                ans = add(ans, add(-ct[pz-14], -ct[pz-16]));
                ans = add(ans, add(ct[pz-19], add(ct[pz-20], -ct[pz-21])));
                ans = add(ans, add(-ct[pz-7], -ct[pz-14]));
                ct[pz] = ans;
            }
            int n = M;
            n *= 6;
            int sol = 0;
            for(int i = 1; i <= n; ++i)
                sol = add(sol, ct[i]);
            ll ta = 30LL * sol;
            ta %= mod;
            return ta;
        }
};


