#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
long long rand_seed()
{
	long long a = rng();
    return a;
}
int n, m, q;
int a[1002][1002], v[1000002];
int nr[1002][1002], nr2[1002][1002], mx1[1002], mx2[1002];
map<int, int>mp;
int frq[1000002], v2[1002];
int aib[1000002];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            cin >> a[i][j];
    for(int i = 1; i <= n; ++i)
    {
        mp.clear();
        for(int j = 1; j <= m; ++j)
            v2[j] = a[i][j];
        sort(v2 + 1, v2 + m + 1);
        int p = 0;
        for(int j = 1; j <= m; ++j)
            if(v2[j] != v2[j-1])
                mp[v2[j]] = ++p;
        for(int j = 1; j <= m; ++j)
            nr[i][j] = mp[a[i][j]];
        mx1[i] = p;
    }
    for(int j = 1; j <= m; ++j)
    {
        mp.clear();
        for(int i = 1; i <= n; ++i)
            v2[i] = a[i][j];
        sort(v2+1, v2+n+1);
        int p = 0;
        for(int i = 1; i <= n; ++i)
            if(v2[i] != v2[i-1])
                mp[v2[i]] = ++p;
        for(int i = 1; i <= n; ++i)
            nr2[i][j] = mp[a[i][j]];
        mx2[j] = p;
    }
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= m; ++j)
        {
            int nrr = max(nr[i][j], nr2[i][j]);
            cout << max(nrr + mx1[i] - nr[i][j], nrr + mx2[j] - nr2[i][j]) << " ";
        }
        cout << '\n';
    }
    return 0;
}

