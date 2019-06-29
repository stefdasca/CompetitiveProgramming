#include<bits/stdc++.h>
#define mod 1000000007
#pragma GCC optimize("O3")
using namespace std;
long long ans[2002], n, k, combi[4002][4002];
void pascal()
{
    combi[0][0] = combi[1][0] = combi[1][1] = 1;
    for(int i = 2; i <= 4000; ++i)
    {
        combi[i][0] = 1;
        for(int j = 1; j <= i; ++j)
        {
            combi[i][j] = combi[i-1][j] + combi[i-1][j-1];
            if(combi[i][j] >= mod)
                combi[i][j] -= mod;
        }
    }
}
long long pw(long long a, long long b)
{
    long long ans = 1;
    while(b)
    {
        if(b&1)
            ans = (ans * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;
    pascal();
    ans[1] = n - k + 1;
    for(long long j = 2; j <= k; ++j)
    {
        int lft = n - k - (j - 1);
        long long nr = (combi[k-1][j-1] * combi[j+lft][lft]) % mod;
        ans[j] = nr;
    }
    for(int i = 1; i <= k; ++i)
        cout << ans[i] << '\n';
    return 0;
}
