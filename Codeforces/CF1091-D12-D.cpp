/// Never do the same mistake twice

#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#define mod 998244353
using namespace std;
long long n;
int v[12];
int frq[12];
long long fact[1000002];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 1; i <= n; ++i)
        v[i] = i;
    fact[0] = 1;
    for(int i = 1; i <= n; ++i)
        fact[i] = (fact[i-1] * i) % mod;
    if(n == 1)
    {
        cout << 1;
        return 0;
    }
    long long ans = 0;
    long long sum = 1;
    for(int i = 2; i < n; ++i)
    {
        sum += fact[i-1];
        sum = sum * i - 1;
        sum %= mod;
    }
    sum = sum * n;
    sum %= mod;
    cout << sum;
    return 0;
}
