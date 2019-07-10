/// Will it all end?

#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int n, q;
string s;
int sum[100002];
long long mod = 1000000007;
long long modpow(long long b, long long ex)
{
    long long sol = 1;
    while(ex)
    {
        if(ex&1)
            sol = (sol * b) % mod;
        b = (b * b) % mod;
        ex >>= 1;
    }
    return sol;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> q;
    cin >> s;
    for(int i = 0; i < n; ++i)
        sum[i+1] = sum[i] + (s[i] == '1');
    for(int i = 1; i <= q; ++i)
    {
        int st, dr;
        cin >> st >> dr;
        int summ = sum[dr] - sum[st-1];
        long long ans = (modpow(2, summ) - 1 + mod) % mod;
        summ = (dr - st + 1) - summ;
        long long ans2 = (ans * (modpow(2, summ) - 1)) % mod;
        cout << (ans + ans2) % mod << '\n';
    }
    return 0;
}
