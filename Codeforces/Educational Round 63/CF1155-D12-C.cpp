#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
long long rand_seed()
{
	long long a = rng();
    return a;
}
int n, m;
long long v[300002];
long long dt[300002];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i = 1; i <= n; ++i)
        cin >> v[i];
    for(int i = 1; i <= m; ++i)
        cin >> dt[i];
    long long cc = v[2] - v[1];
    for(int i = 3; i <= n; ++i)
        cc = __gcd(cc, v[i] - v[i-1]);
    for(int i = 1; i <= m; ++i)
        if(cc % dt[i] == 0)
        {
            cout << "YES\n";
            cout << v[1] << " " << i << '\n';
            return 0;
        }
    cout << "NO";
    return 0;
}

