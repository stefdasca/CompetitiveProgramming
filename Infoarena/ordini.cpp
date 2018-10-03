#include <bits/stdc++.h>
using namespace std;
ifstream f("ordini.in");
ofstream g("ordini.out");
int mod;
const int maxn = 1002;
int n;
long long C[maxn][maxn], has[11], po10[maxn];
long long cal()
{
    long long res = 1;
    int tot = 0;
    for (int i = 0; i < 10; i++)
        tot += has[i];
    for (int i = 0; i < 10; i++)
    {
        if (has[i] == 0)
            continue;
        res = (res * C[tot][has[i]]) % mod;
        tot -= has[i];
    }
    return res;
}
int main()
{
    for(int i=0; i<=9; ++i)
        f>>has[i],n+=has[i];
    f>>mod;
    po10[0] = 1;
    for (int i = 1; i < maxn; i++)
        po10[i] = po10[i - 1] * 10ll % mod;
    for (int i = 0; i < maxn; i++)
    {
        C[i][0] = 1;
        for (int j = 1; j <= i; j++)
            C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
    }
    long long ans = 0;
    for (int i = 1; i < 10; i++)
    {
        if (has[i] == 0)
            continue;
        has[i]--;
        ans = (ans + po10[n - 1] * cal() % mod * i % mod) % mod;
        for (int j = 1; j < 10; j++)
        {
            if (has[j] == 0)
                continue;
            has[j]--;
            for (int k = 0; k < n - 1; k++)
                ans = (ans + po10[k] * cal() % mod * j % mod) % mod;
            has[j]++;
        }
        has[i]++;
    }
    g<<ans;
    return 0;
}
