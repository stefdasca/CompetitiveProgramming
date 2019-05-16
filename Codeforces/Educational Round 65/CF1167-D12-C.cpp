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
vector<int>v[500002];
int cc[500005], sz[500005], c;
bool viz[500002];
void dfs(int nod)
{
    cc[nod] = c;
    ++sz[c];
    viz[nod] = 1;
    for(int i = 0; i < v[nod].size(); ++i)
    {
        int vec = v[nod][i];
        if(!viz[vec])
            dfs(vec);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i = 1; i <= m; ++i)
    {
        int a;
        cin >> a;
        vector<int>vv;
        for(int j = 1; j <= a; ++j)
        {
            int nr;
            cin >> nr;
            vv.push_back(nr);
        }
        for(int i = 0; i + 1 < vv.size(); ++i)
        {
            v[vv[i]].push_back(vv[i+1]);
            v[vv[i+1]].push_back(vv[i]);
        }
    }
    for(int i = 1; i <= n; ++i)
        if(!viz[i])
            ++c, dfs(i);
    for(int i = 1; i <= n; ++i)
        cout << sz[cc[i]] << " ";
    return 0;
}
