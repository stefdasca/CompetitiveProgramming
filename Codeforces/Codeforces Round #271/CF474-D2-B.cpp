#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
long long rand_seed()
{
	long long a = rng();
    return a;
}
int n;
int wh[2000002];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    int prv = 0;
    for(int i = 1; i <= n; ++i)
    {
        int x;
        cin >> x;
        for(int j = prv + 1; j <= prv + x; ++j)
            wh[j] = i;
        prv += x;
    }
    int m;
    cin >> m;
    for(int i = 1; i <= m; ++i)
    {
        int q;
        cin >> q;
        cout << wh[q] << '\n';
    }
    return 0;
}

