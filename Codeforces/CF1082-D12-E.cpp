#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int n, c;
int v[500002], fr[500002], prefc[500002], suffc[500002];
vector<int>nr[500002];
int mmx[500002], wh[500002], mmxs[500002], whs[500002];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> c;
    int ans = 0;
    for(int i = 1; i <= n; ++i)
        cin >> v[i], fr[v[i]]++, nr[v[i]].push_back(i);
    for(int i = 1; i <= 500000; ++i)
        ans = max(ans, fr[i]);
    for(int i = 1; i <= n; ++i)
        prefc[i] = prefc[i-1] + (v[i] == c);
    for(int i = n; i >= 1; --i)
        suffc[i] = suffc[i+1] + (v[i] == c);
    for(int i = 1; i <= 500000; ++i)
    {
        if(i == c)
            continue;
        if(!nr[i].size())
            continue;
        int mx = -(1<<29);
        for(int j = 0; j < nr[i].size(); ++j)
        {
            mx = max(mx, prefc[nr[i][j]] - j);
            ans = max(ans, suffc[nr[i][j]] + j + mx + 1);
        }
    }
    cout << ans;
    return 0;
}
