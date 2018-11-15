#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int t;
int n;
int v1[1002];
int v2[1002];
vector<int>v[1002];
int viz[1002];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    for(int i = 1; i <= t; ++i)
    {
        cin >> n;
        for(int j = 1; j <= n; ++j)
            v[j].clear();
        for(int j = 1; j < n; ++j)
        {
            int a, b;
            cin >> a >> b;
            v[a].push_back(b);
            v[b].push_back(a);
        }
        int k1, k2;
        map<int, int>mp;
        map<int, int>mp2;
        memset(viz, 0, sizeof(viz));
        cin >> k1;
        for(int j = 1; j <= k1; ++j)
            cin >> v1[j], mp[v1[j]] = 1;
        cin >> k2;
        for(int j = 1; j <= k2; ++j)
            cin >> v2[j], mp2[v2[j]] = 1;
        int ans;
        cout << "B " << v2[1] << endl;
        cin >> ans;
        deque<int>d;
        viz[ans] = 1;
        d.push_back(ans);
        int rau = 0;
        while(!d.empty())
        {
            int nod = d[0];
            if(mp[nod])
            {
                rau = nod;
                break;
            }
            d.pop_front();
            for(int j = 0; j < v[nod].size(); ++j)
            {
                int x = v[nod][j];
                if(viz[x])
                    continue;
                d.push_back(x), viz[x] = 1;
            }
        }
        cout << "A " << rau << endl;
        cin >> ans;
        if (mp2[ans])
            cout << "C " << rau << endl;
        else
            cout << "C " << -1 << endl;
    }
    return 0;
}
