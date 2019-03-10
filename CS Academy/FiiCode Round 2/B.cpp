#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
long long rand_seed()
{
	long long a = rng();
    return a;
}
long long n, m, v[3002];
long long dist(long long a, long long b)
{
    long long mn = abs(a - b);
    mn = min(mn, m - a + b);
    mn = min(mn, a + m - b);
    return mn;
}
int ds[3002][6002];
int ss[3002][6002];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(long long i = 1; i <= n; ++i)
       cin >> v[i];
    sort(v+1, v+n+1);
    for(long long i = 1; i <= n; ++i)
        for(long long j = 1; j <= 2 * m; ++j)
            if(j <= m)
                ds[i][j] = dist(v[i], j);
            else
                ds[i][j] = dist(v[i], j - m);
    for(long long i = 1; i <= n; ++i)
        for(long long j = 1; j <= 2 * m; ++j)
            ss[i][j] = ss[i-1][j-1] + ds[i][j];
    deque<long long>d;
    for(long long i = 1; i <= n; ++i)
        d.push_back(v[i]);
    int mmn = (1<<30);
    for(long long aa = 1; aa <= n; ++aa)
    {
        for(long long i = 1; i <= m; ++i)
        {
            int z = ss[n][i + (n - aa)] - ss[aa - 1][i - 1];
            z += ss[aa - 1][i + n - 1];
            mmn = min(mmn, z);
        }
        long long x = d[0];
        d.pop_front();
        d.push_back(x);
    }
    cout << mmn;
    return 0;
}

