/// Never do the same mistake twice

#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int n, q;
vector<int>v[300002];
struct str
{
    long long lungime, cat;
};
vector<str>queries[300002];
long long val[300002];
long long mars[300002];
void dfs(int dad, int nod, int nivel, long long sum)
{
    for(int i = 0; i < queries[nod].size(); ++i)
    {
        mars[nivel] += queries[nod][i].cat;
        if(nivel + queries[nod][i].lungime + 1 <= 300000)
            mars[nivel + queries[nod][i].lungime + 1] -= queries[nod][i].cat;
    }
    val[nod] = sum + mars[nivel];
    for(int i = 0; i < v[nod].size(); ++i)
    {
        int vecin = v[nod][i];
        if(vecin == dad)
            continue;
        dfs(nod, vecin, nivel + 1, sum + mars[nivel]);
    }
    for(int i = 0; i < queries[nod].size(); ++i)
    {
        mars[nivel] -= queries[nod][i].cat;
        if(nivel + queries[nod][i].lungime + 1 <= 300000)
            mars[nivel + queries[nod][i].lungime + 1] += queries[nod][i].cat;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 1; i < n; ++i)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    cin >> q;
    for(int i = 1; i <= q; ++i)
    {
        long long a, b, c;
        cin >> a >> b >> c;
        queries[a].push_back({b, c});
    }
    dfs(0, 1, 0, 0);
    for(int i = 1; i <= n; ++i)
        cout << val[i] << " ";
    return 0;
}

