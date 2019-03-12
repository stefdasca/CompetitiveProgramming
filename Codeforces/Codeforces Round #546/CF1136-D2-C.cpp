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
int a[502][502], b[502][502];
vector<int>v[1002], v2[1002];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    int aa = 0, bb = 0;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            cin >> a[i][j], v[i+j].push_back(a[i][j]);
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            cin >> b[i][j], v2[i+j].push_back(b[i][j]);
    for(int i = 1; i <= n + m; ++i)
    {
        sort(v2[i].begin(), v2[i].end());
        sort(v[i].begin(), v[i].end());
        for(int j = 0; j < v[i].size(); ++j)
            if(v[i][j] != v2[i][j])
            {
                cout << "NO";
                return 0;
            }
    }
    cout << "YES";
    return 0;
}
