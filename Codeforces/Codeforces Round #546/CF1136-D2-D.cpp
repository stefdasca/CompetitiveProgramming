#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int n, m, gi, pe[300005], cnt[300005];
vector<int>tr[300005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i = 1; i <= n; ++i)
        cin >> pe[i];
    gi = pe[n];
    for(int i = 1; i <= m; ++i)
    {
        int a, b;
        cin >> a >> b;
        tr[b].push_back(a);
    }
    int ans = 0;
    int tt = 0;
    for(int i = n; i >= 1; --i)
    {
        if(i != n && cnt[pe[i]] == tt)
        {
            ++ans;
            continue;
        }
        ++tt;
        for(int j = 0; j < tr[pe[i]].size(); ++j)
            ++cnt[tr[pe[i]][j]];
    }
    cout << ans;
    return 0;
}


