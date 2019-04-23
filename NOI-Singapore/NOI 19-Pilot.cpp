/*
        Singapore NOI 19-Pilot

    We can solve the queries in the increasing order of Qi, using dsu and some math to find the answers for each Qi

*/

#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
long long rand_seed()
{
	long long a = rng();
    return a;
}
vector<int>poz[1000002];
int v[1000002], rg[1000002], tt[1000002], qu[1000002];
long long a[1000002];
int n, q;
long long ans;
int Find(int nod)
{
    if(tt[nod] == nod)
        return nod;
    return tt[nod] = Find(tt[nod]);
}
void Union(int a, int b)
{
    ans = ans - 1LL * rg[a] * (rg[a] + 1) / 2;
    ans = ans - 1LL * rg[b] * (rg[b] + 1) / 2;
    ans = ans + 1LL * (rg[a] + rg[b]) * (rg[a] + rg[b] + 1) / 2;
    if(rg[a] >= rg[b])
        tt[b] = a, rg[a] += rg[b];
    else
        tt[a] = b, rg[b] += rg[a];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> q;
    for(int i = 1; i <= n; ++i)
    {
        cin >> v[i];
        poz[v[i]].push_back(i);
    }
    for(int i = 1; i <= q; ++i)
        cin >> qu[i];
    for(int i = 1; i <= n; ++i)
        rg[i] = 1, tt[i] = i;
    for(int i = 1; i <= 1000000; ++i)
    {
        for(int j = 0; j < poz[i].size(); ++j)
        {
            int z = poz[i][j];
            ans++;
            if(z > 1 && v[z-1] <= v[z])
                Union(Find(z-1), Find(z));
            if(z + 1 <= n && v[z+1] < v[z])
                Union(Find(z), Find(z+1));
        }
        a[i] = ans;
    }
    for(int i = 1; i <= q; ++i)
        cout << a[qu[i]] << '\n';
    return 0;
}

