#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
long long n, v[100002];
vector<int>divizori[1000002];
long long sum[100002];
long long ans;
long long mod = 1000000007;
void ciur()
{
    for(int i = 1; i <= n; ++i)
        for(int j = i; j <= 1000000; j += i)
            divizori[j].push_back(i);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> v[i];
    ciur();
    sum[0] = 1;
    for(int i = 1; i <= n; ++i)
    {
        for(int j = divizori[v[i]].size() - 1; j >= 0; --j)
        {
            int jj = divizori[v[i]][j];
            sum[jj] = (sum[jj] + sum[jj-1]) % mod;
            ans = (ans + sum[jj-1]) % mod;
        }
    }
    cout << ans;
    return 0;
}
