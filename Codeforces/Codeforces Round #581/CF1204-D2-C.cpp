#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#define fi first
#define se second
#define pb push_back

using namespace std;

typedef long long ll;

int n, m;
char adj[102][102];
int rf[102][102];
int v[1000002];
int dp[1000002];
int lst[102];
int fw[1000002];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> (adj[i] + 1);
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j)
            if(adj[i][j] != '0')
                rf[i][j] = 1;
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (rf[i][k] && rf[k][j] && (rf[i][j] > rf[i][k] + rf[k][j] || !rf[i][j]) && i != j)
                    rf[i][j] = rf[i][k] + rf[k][j];
    cin >> m;
    for(int i = 1; i <= m; ++i)
        cin >> v[i];
    lst[v[1]] = 1;
    dp[1] = 1;
    for(int i = 2; i <= m; ++i)
    {
        dp[i] = (1<<30);
        for(int j = 1; j <= n; ++j)
        {
            if(lst[j] != 0)
            {
                if(rf[j][v[i]] == (i - lst[j]))
                {
                    if(dp[lst[j]] + 1 < dp[i])
                    {
                        dp[i] = dp[lst[j]] + 1;
                        fw[i] = lst[j];
                    }
                }
            }
        }
        lst[v[i]] = i;
    }
    vector<int>vv;
    int pz = m;
    cout << dp[m] << '\n';
    while(pz)
    {
        vv.push_back(v[pz]);
        pz = fw[pz];
    }
    for(int i = vv.size() - 1; i >= 0; --i)
        cout << vv[i] << " ";
    return 0;
}
