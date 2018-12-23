/// Never do the same mistake twice

#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
long long n, s;
vector<int>v[100002];
int ssh, wh, m1, m2;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> s;
    for(int i = 1; i < n; ++i)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int fr = 0;
    for(int i = 1; i <= n; ++i)
        if(v[i].size() == 1)
            ++fr;
    double ans = (0.0000 + s) / (1.0000 + fr);
    ans = ans * 2;
    cout << fixed << setprecision(15) << ans;
    return 0;
}
