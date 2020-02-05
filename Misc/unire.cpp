#include<bits/stdc++.h>
using namespace std;

ifstream f("unire.in");
ofstream g("unire.out");

int n, m, mn, c;
long long ans;
vector<int> v[100002];
vector<int> sm;
int viz[100002];

void dfs(int nod)
{
    mn = min(mn, nod);
    viz[nod] = 1;
    for(int i = 0; i < v[nod].size(); ++i)
    {
        int vecin = v[nod][i];
        if(!viz[vecin])
            dfs(vecin);
    }
}
int main()
{
    f >> n >> m;
    f >> c;
    for(int i = 1; i <= m; ++i)
    {
        int a, b;
        f >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    mn = 0;
    for(int i = 1; i <= n; ++i)
        if(!viz[i])
        {
            mn = i;
            dfs(i);
            sm.push_back(i);
        }
    sort(sm.begin(), sm.end());
    for(int i = 1; i < sm.size(); ++i)
    {
        ans += sm[0];
        ans += sm[i];
    }
    if(c == 1)
        g << sm.size() - 1 << '\n';
    else
        g << ans;
    return 0;

}
