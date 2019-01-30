/*
                                Baltic 08-Gates

    * After analyzing the input format, we can observe that this problem is just 2-SAT
    * Find strongly connected components, then using the property that the components are
always sorted by their topological sort order, we will just check whether a number and its
opposite are on the same component, otherwise we will put 1 only if the normal switch is in
a component which is after the component of the negated switch

*/

#include<bits/stdc++.h>
using namespace std;
int n, m;
bool pus[1000002], viz[1000002];
int comp[1000002];
vector<int>v[1000002], tr[1000002];
vector<int>ordine;
void dfs(int nod)
{
    viz[nod] = 1;
    for(int i = 0; i < v[nod].size(); ++i)
    {
        int vecin = v[nod][i];
        if(viz[vecin])
            continue;
        dfs(vecin);
    }
    ordine.push_back(nod);
}
int nr;
void dfs2(int nod)
{
    comp[nod] = nr;
    for(int i = 0; i < tr[nod].size(); ++i)
    {
        int vecin = tr[nod][i];
        if(comp[vecin])
            continue;
        dfs2(vecin);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    swap(n, m);
    for(int i = 1; i <= m; ++i)
    {
        int a, nega, b, negb;
        cin >> a >> nega >> b >> negb;
        nega ^= 1;
        negb ^= 1;
        v[a * 2 + (!nega)].push_back(b * 2 + negb);
        v[b * 2 + (!negb)].push_back(a * 2 + nega);
        tr[b * 2 + negb].push_back(a * 2 + (!nega));
        tr[a * 2 + nega].push_back(b * 2 + (!negb));
    }
    for(int i = 2; i <= 2 * n + 1; ++i)
        if(!viz[i])
            dfs(i);
    reverse(ordine.begin(), ordine.end());
    for(int i = 0; i < ordine.size(); ++i)
    {
        int nod = ordine[i];
        if(!comp[nod])
            ++nr, dfs2(nod);
    }
    for(int i = 2; i <= 2 * n + 1; ++i)
        if(comp[i] == comp[i ^ 1])
        {
            cout << "IMPOSSIBLE";
            return 0;
        }
    for(int i = 1; i <= n; ++i)
        cout << (comp[i * 2] > comp[i * 2 + 1]) << '\n';
    return 0;
}

