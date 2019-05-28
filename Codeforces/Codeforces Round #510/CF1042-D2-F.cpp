#include<bits/stdc++.h>
using namespace std;
int n, k;
vector<int>v[1000002];
int ans;
int dfs(int nod, int dad)
{
    if(v[nod].size() == 1)
        return 0;
    vector<int>sz;
    for(int i = 0; i < v[nod].size(); ++i)
    {
        int vecin = v[nod][i];
        if(vecin == dad)
            continue;
        sz.push_back(dfs(vecin, nod) + 1);
    }
    sort(sz.begin(), sz.end());
    while(sz.size() >= 2)
    {
		if (sz.back() + sz[sz.size() - 2] <= k)
			break;
		++ans;
		sz.pop_back();
	}
    return sz.back();
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;
    for(int i = 1; i < n; ++i)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(int i = 1; i <= n; ++i)
        if(v[i].size() > 1)
        {
            dfs(i, 0);
            break;
        }
    cout << ans + 1;
    return 0;
}