
#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
ifstream f("arbore7.in");
ofstream g("arbore7.out");
int n;
vector<int>v[100002];
int dp[3][100002];
long long ways[3][100002];
long long sol, moduri;
void dfs(int dad, int nod)
{
    if(v[nod].size() == 1 && v[nod][0] == dad)
    {
        dp[1][nod] = 1;
        ways[1][nod] = 1;
        ways[2][nod] = 1;
        return;
    }
    int max3 = 0;
    long long ways1 = 0;
    int max1 = 1;
    long long ways2 = 1;
    int max2 = 0;
    long long ways3 = 1;
    for(int i = 0; i < v[nod].size(); ++i)
    {
        int vecin = v[nod][i];
        if(vecin == dad)
            continue;
        dfs(nod, vecin);
        max3 = max3;
        if(dp[1][vecin] - 1 == dp[2][vecin])
            max3 += dp[1][vecin] - 1, ways3 = (ways3 * (ways[1][vecin] + ways[2][vecin])) % mod;
        else
            if(dp[1][vecin] - 1 > dp[2][vecin])
                max3 += dp[1][vecin] - 1, ways3 = (ways3 * (ways[1][vecin])) % mod;
            else
                max3 += dp[2][vecin], ways3 = (ways3 * ways[2][vecin]) % mod;
        max1 = max1 + dp[2][vecin];
        ways1 = (ways1 * ways[2][vecin]) % mod;
        if(dp[1][vecin]  == dp[2][vecin])
            max2 += dp[1][vecin] , ways2 = (ways2 * (ways[1][vecin] + ways[2][vecin])) % mod;
        else
            if(dp[1][vecin] > dp[2][vecin])
                max2 += dp[1][vecin], ways2 = (ways2 * (ways[1][vecin])) % mod;
            else
                max2 += dp[2][vecin], ways2 = (ways2 * ways[2][vecin]) % mod;
    }
    max3++;
    dp[1][nod] = max(max3, max1);
    dp[2][nod] = max2;
    ways[2][nod] = ways2;
    if(max3 == max1)
        ways[1][nod] = (ways1 + ways3) % mod;
    if(max3 > max1)
        ways[1][nod] = ways3;
    if(max1 > max3)
        ways[1][nod] = ways1;
    if(nod == 1)
    {
        if(dp[1][nod] == dp[2][nod])
            moduri = (ways[1][nod] + ways[2][nod]) % mod;
        if(dp[1][nod] > dp[2][nod])
            moduri = ways[1][nod];
        if(dp[2][nod] > dp[1][nod])
            moduri = ways[2][nod];
    }
}
int main()
{
    f >> n;
    for(int i = 1; i < n; ++i)
    {
        int a, b;
        f >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(0, 1);
    g << max(dp[1][1], dp[2][1]) << " " << moduri << '\n';
    return 0;
}
