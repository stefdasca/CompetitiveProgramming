#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int n;
int v[22];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> v[i];
    int ans = 0;
    for(int i = 2; i < n; ++i)
    {
        vector<int>vv;
        for(int j = i-1; j <= i+1; ++j)
            vv.push_back(v[j]);
        sort(vv.begin(), vv.end());
        if(v[i] == vv[1])
            ++ans;
    }
    cout << ans;
    return 0;
}
