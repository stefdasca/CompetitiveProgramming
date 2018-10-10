/// leader of NumaNumaTei

#include<bits/stdc++.h>
#define SD 100002
#define LOG2 19
using namespace std;
ifstream f("aiacupalindroame.in");
ofstream g("aiacupalindroame.out");
int n, q;
int nr;
vector<pair<int, int> >v[SD];
int tata[SD];
string s;
int base = 26, mod = 1000000009;
int hsh[SD], lele[SD];
void dfs(int nod)
{
    for(int i = 0; i < v[nod].size(); ++i)
    {
        int aa = v[nod][i].first;
        hsh[aa] = (1LL * hsh[nod] * base + v[nod][i].second) % mod;
        lele[aa] = lele[nod] + 1;
        dfs(aa);
    }
}
int main()
{
    f >> n >> q;
    for(int i = 2; i <= n; ++i)
        f >> tata[i];
    f >> s;
    for(int i = 0; i < n-1; ++i)
        v[tata[i+2]].push_back({i+2, (s[i]-'a')});
    dfs(1);
    for(int i = 1; i <= q; ++i)
    {
        int a, b;
        f >> a >> b;
        if(lele[a] == lele[b] && hsh[a] == hsh[b])
            g << 1 << '\n';
        else
            g << 0 << '\n';
    }
    return 0;
}
