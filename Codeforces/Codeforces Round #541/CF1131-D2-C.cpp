#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
long long rand_seed()
{
	long long a = rng();
    return a;
}
int n, v[102], ans[102];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> v[i];
    sort(v+1, v+n+1);
    if(n % 2 == 1)
        ans[n/2 + n%2] = v[n];
    int s = n/2;
    int d = n/2 + 1 + n % 2;
    for(int i = n - (n % 2); i >= 1; i -= 2)
    {
        ans[s] = v[i];
        ans[d] = v[i-1];
        --s;
        ++d;
    }
    for(int i = 1; i <= n; ++i)
        cout << ans[i] << " ";
    return 0;
}

