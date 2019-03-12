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
int v[102];
int v2[102];
int p;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> v[i] >> v2[i];
    cin >> p;
    int ans = n;
    for(int i = 1; i <= n; ++i)
        if(p > v2[i])
            --ans;
    cout << ans;
    return 0;
}

