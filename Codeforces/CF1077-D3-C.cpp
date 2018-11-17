/// Never do the same mistake twice

#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int n;
map<long long, int>mp;
long long sum;
int v[200005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> v[i], mp[v[i]]++, sum += v[i];
    vector<int>ans;
    for(int i = 1; i <= n; ++i)
    {
        sum -= v[i];
        mp[v[i]] --;
        if(sum % 2 == 0 && mp[sum/2] > 0)
            ans.push_back(i);
        sum += v[i];
        mp[v[i]] ++;
    }
    cout << ans.size() << '\n';
    for(int i = 0; i < ans.size(); ++i)
        cout << ans[i] << " ";
    return 0;
}
