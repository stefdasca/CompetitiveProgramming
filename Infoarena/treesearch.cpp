#include<bits/stdc++.h>
using namespace std;
ifstream f("treesearch.in");
ofstream g("treesearch.out");
long long n, m;
long long ans[100002], a[100002], sol[100002];
vector<long long>v[100002];
void dfs(long long dad, long long nod)
{
    ans[nod] = -2000000001;
    for(long long i = 0; i < v[nod].size(); ++i)
    {
        long long vecin = v[nod][i];
        if(vecin == dad)
            continue;
        dfs(nod, vecin);
        ans[nod] = max(ans[nod], ans[vecin]);
    }
    ans[nod] = max(ans[nod] + a[nod], a[nod]);
}
void dfs2(long long dad, long long nod, long long mx)
{
    sol[nod] = ans[nod];
    sol[nod] = max(sol[nod], mx + ans[nod]);
    vector<long long>aa;
    for(long long i = 0; i < v[nod].size(); ++i)
    {
        long long vecin = v[nod][i];
        if(vecin == dad)
            continue;
        aa.push_back(ans[vecin]);
    }
    sort(aa.begin(), aa.end());
    if(aa.size() >= 2)
        sol[nod] = max(sol[nod], aa[aa.size()-1] + aa[aa.size()-2] + a[nod]);
    for(long long i = 0; i < v[nod].size(); ++i)
    {
        long long vecin = v[nod][i];
        if(vecin == dad)
            continue;
        if(nod == 1)
        {
            if(ans[vecin] == aa[aa.size()-1])
            {
                if(aa.size() == 1)
                    dfs2(nod, vecin, a[nod]);
                else
                    dfs2(nod, vecin, max(a[nod], aa[aa.size()-2] + a[nod]));
            }
            else
                dfs2(nod, vecin, max(a[nod], aa[aa.size()-1] + a[nod]));
        }
        else
        {
            if(ans[vecin] == aa[aa.size()-1])
            {
                if(aa.size() == 1)
                    dfs2(nod, vecin, max(a[nod], mx + a[nod]));
                else
                    dfs2(nod, vecin, max(a[nod], max(mx + a[nod], aa[aa.size()-2] + a[nod])));
            }
            else
                dfs2(nod, vecin, max(a[nod], max(mx + a[nod], aa[aa.size()-1] + a[nod])));
        }
    }
}
int main()
{
    f >> n >> m;
    for(long long i = 1; i <= n; ++i)
        f >> a[i];
    for(long long i = 1; i < n; ++i)
    {
        long long a, b;
        f >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(0, 1);
    dfs2(0, 1, 0);
    for(long long i = 1; i <= m; ++i)
    {
        long long nr;
        f >> nr;
        g << sol[nr] << '\n';
    }
    return 0;
}
