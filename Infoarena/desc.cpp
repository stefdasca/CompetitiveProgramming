#include<bits/stdc++.h>
using namespace std;
ifstream f("desc.in");
ofstream g("desc.out");
long long n, k;
int dp[4201][4201];
long long divi[7500], nr;
unordered_map<long long, int>d;
int main()
{
    f >> n >> k;
    for(long long i = 1; i * i <= n; ++i)
    {
        if(n % i == 0)
        {
            if(i != 1)
                divi[++nr] = i;
            if(i != n / i)
                divi[++nr] = n/i;
        }
    }
    sort(divi + 1, divi + nr + 1);
    divi[0] = 1;
    for(int i = 1; i <= nr; ++i)
        d[divi[i]] = i;
    dp[0][nr] = 1;
    for(int i = 0; i <= nr; ++i)
    {
        for(int e = nr; e >= 1; --e)
            dp[i][e] += dp[i][e+1];
        for(int j = i+1; j <= nr; ++j)
        {
            if(divi[j] % divi[i] != 0)
                continue;
            long long rap = divi[j]/divi[i];
            if(d.find(rap) == d.end())
                continue;
            int x = d[rap];
            dp[j][x] += dp[i][x];
        }
    }
    int L = nr;
    int C = 1;
    g << dp[nr][1] << '\n';
    while(k)
    {
        if(dp[L][C] - dp[L][C+1] < k)
        {
            k -= (dp[L][C] - dp[L][C+1]);
            ++C;
        }
        else
            if(L == C && k == 1)
            {
                g << divi[C] << " ";
                break;
            }
            else
            {
                g << divi[C] << " ";
                n /= divi[C];
                L = d[n];
            }
    }
    return 0;
}
