#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#define mod 1000000007
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
long long rand_seed()
{
	long long a = rng();
    return a;
}
int n, dp[78][(1<<20) + 5];
string s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    cin >> s;
    s = ' ' + s;
    dp[0][0] = 1;
    long long aa = 0;
    for(int i = 1; i < s.size(); ++i)
    {
        vector<int>pc;
        int j = i;
        int val = 0;
        while(j >= 1 && val <= 20)
        {
            if(s[j] == '1')
            {
                if(i - j >= 5)
                    break;
                val += (1<<(i - j));
            }
            if(val > 20)
                break;
            if(val)
                for(int fo = 0; fo < (1<<20); ++fo)
                {
                    dp[i][fo | (1<<(val - 1))] = dp[i][fo | (1<<(val - 1))] + dp[j - 1][fo];
                    if(dp[i][fo | (1<<(val - 1))] >= mod)
                        dp[i][fo | (1<<(val - 1))] -= mod;
                }
            --j;
        }
        dp[i][0]++;
        for(int fo = 1; fo < (1<<20); fo = fo * 2 + 1)
            aa = (aa + dp[i][fo]) % mod;
    }
    cout << aa;
    return 0;
}

