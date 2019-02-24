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
int ans[150002];
vector<int>v[150002];
int bl[150002];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    ans[1] = 1;
    for(int i = 1; i <= n; ++i)
        v[i].push_back(i), bl[i] = i;
    int pz = 2;
    for(int z = 1; z < n; ++z)
    {
        int a, b;
        cin >> a >> b;
        if(v[bl[a]].size() > v[bl[b]].size())
        {
            int q = bl[b];
            for(int i = 0; i < v[q].size(); ++i)
            {
                v[bl[a]].push_back(v[q][i]);
                bl[v[q][i]] = bl[a];
            }
            v[q].clear();
        }
        else
        {
            int q = bl[a];
            for(int i = 0; i < v[q].size(); ++i)
            {
                v[bl[b]].push_back(v[q][i]);
                bl[v[q][i]] = bl[b];
            }
            v[q].clear();
        }
    }
    for(int i = 0; i < v[bl[1]].size(); ++i)
        cout << v[bl[1]][i] << " ";
    return 0;
}

