#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
long long rand_seed()
{
	long long a = rng();
    return a;
}
long long l, r, mod = 1000000007;
long long sum(long long x)
{
    if(x == 0)
        return 0;
    long long st = 0;
    long long st2 = 0;
    long long stp = 0;
    long long ct = 1;
    while(x)
    {
        if(stp == 0)
        {
            if(x >= ct)
                st += ct, x -= ct;
            else
                st += x, x = 0;
        }
        else
        {
            if(x >= ct)
                st2 += ct, x -= ct;
            else
                st2 += x, x = 0;
        }
        ct = ct * 2;
        stp ^= 1;
    }
    long long aaa = st % mod;
    aaa = (aaa * aaa) % mod;
    long long ans = (ans + aaa) % mod;
    long long bbb = st2 % mod;
    long long ccc = (bbb + 1) % mod;
    bbb = (bbb * ccc) % mod;
    ans = (ans + bbb) % mod;
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> l >> r;
    cout << (sum(r) - sum(l-1) + mod) % mod;
    return 0;
}
