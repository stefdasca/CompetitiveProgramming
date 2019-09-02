/*
        COI 07-Umnozak

    * It's easier to compute ans(1, b) - ans(1, a-1) than ans(a, b).
    * It can be observed that the number of pairs 2^a1 * 3^a2 * ... * 9^a8 isn't very big, and we can use bruteforce and some math to find the answer.

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
    if(x >= mod)
        x -= mod;
    if(x < 0)
        x += mod;
    return x;
}

ll a[12], fact[50], ans, p10[20];

void bkt(int dg, ll pr, ll mx, int lst)
{

    ll max_number = mx / pr;
    int dgg = 0;
    while(max_number)
        ++dgg, max_number /= 10;
    if(dg > dgg)
        return;
    max_number = mx / pr;
    int cf = dg;
    for(int i = dg; i <= dgg; ++i)
    {
        if(dg < i)
            ++cf, ++a[1];
        if(i && i < dgg)
        {
            ll frml = fact[cf];
            for(int j = 1; j <= 9; ++j)
                frml /= fact[a[j]];
            ans += frml;
        }
    }
    int a2[12];
    for(int i = 0; i <= 9; ++i)
        a2[i] = a[i];
    for(int i = 1; i <= dgg; ++i)
    {
        for(int j = 1; j < max_number / p10[dgg-i] + (i == dgg); ++j)
        {
            if(!a2[j])
                continue;
            --a2[j];
            ll frml = fact[dgg-i];
            for(int q = 1; q <= 9; ++q)
                frml /= fact[a2[q]];
            ans += frml;
            ++a2[j];
        }
        if(!a2[max_number / p10[dgg-i]])
            break;
        --a2[max_number / p10[dgg-i]];
        max_number %= p10[dgg-i];
    }
    // next
    a[1] = 0;
    for(int i = lst; i <= 9; ++i)
        if(pr * i <= mx)
        {
            a[i]++;
            bkt(dg+1, pr*i, mx, i);
            a[i]--;
        }
}


ll dp(ll nr)
{
    memset(a, 0, sizeof(a));
    ans = 0;
    bkt(0, 1, nr, 2);
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll a, b;
    cin >> a >> b;
    fact[0] = 1;
    for(int i = 1; i <= 20; ++i)
        fact[i] = (fact[i-1] * i);
    p10[0] = 1;
    for(int i = 1; i <= 18; ++i)
        p10[i] = p10[i-1] * 10;
    cout << dp(b) - dp(a-1) << '\n';
    return 0;
}
