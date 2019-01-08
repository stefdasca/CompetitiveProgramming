/*
            Baltic 17-railway

    * At first, we will find dfs order of tree(rooted at node 1) and the ancestors for each node with binary lifting.
    * For each query, we will sort the nodes using dfs order position as the criteria and using the binary lifting, we will
"cancel" some of the additions by finding LCA of the 2 adjacent nodes
    * In the end, just divide each sum by 2 and see whether edge formed by node i and his father is visited for at least k times

*/

#include<bits/stdc++.h>
using namespace std;
int n, m, k;
vector<pair<int, int> >v[100002];
int lvl[100002], dfsorder[100002], p, st[100002];
int anc[100002][18];
int sum[100002];
void dfs(int dad, int nod)
{
    int pz = dad;
    anc[nod][0] = dad;
    int pp = 1;
    while(pz)
    {
        anc[nod][pp] = anc[pz][pp - 1];
        pz = anc[nod][pp];
        ++pp;
    }
    for(int i = 0; i < v[nod].size(); ++i)
    {
        int vecin = v[nod][i].first;
        if(vecin == dad)
            continue;
        lvl[vecin] = lvl[nod] + 1;
        dfs(nod, vecin);
    }
    dfsorder[++p] = nod;
    st[nod] = p;
}
int ancc(int nod, int cat)
{
    cat = lvl[nod] - cat;
    for(int i = 17; i >= 0; --i)
    {
        if((1<<i) > cat)
            continue;
        nod = anc[nod][i];
        cat -= (1<<i);
        if(cat == 0)
            return nod;
    }
    return nod;
}
int FindLCA(int a, int b)
{
    int st = 0;
    int dr = min(lvl[a], lvl[b]);
    int ans = 0;
    while(st <= dr)
    {
        int mid = (st + dr) / 2;
        if(ancc(a, mid) == ancc(b, mid))
            ans = ancc(a, mid), st = mid + 1;
        else
            dr = mid - 1;
    }
    return ans;
}
bool cmp(int a, int b)
{
    return st[a] < st[b];
}
void dfs2(int dad, int nod)
{
    for(int i = 0; i < v[nod].size(); ++i)
    {
        if(v[nod][i].first == dad)
            continue;
        dfs2(nod, v[nod][i].first);
        sum[nod] += sum[v[nod][i].first];
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m >> k;
    for(int i = 1; i < n; ++i)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back({b, i});
        v[b].push_back({a, i});
    }
    dfs(0, 1);
    for(int i = 1; i <= m; ++i)
    {
        int ct;
        cin >> ct;
        vector<int>v2;
        for(int j = 1; j <= ct; ++j)
        {
            int nr;
            cin >> nr;
            v2.push_back(nr);
        }
        sort(v2.begin(), v2.end(), cmp);
        for(int j = 0; j < v2.size(); ++j)
        {
            int x = j;
            int y = (j + 1) % v2.size();
            sum[v2[x]]++;
            sum[v2[y]]++;
            sum[FindLCA(v2[x], v2[y])] -= 2;
        }
    }
    dfs2(0, 1);
    vector<int>ans;
    for(int i = 1; i <= n; ++i)
    {
        sum[i] /= 2;
        if(sum[i] >= k)
        {
            for(int j = 0; j < v[i].size(); ++j)
                if(v[i][j].first == anc[i][0])
                    ans.push_back(v[i][j].second);
        }
    }
    cout << ans.size() << '\n';
    sort(ans.begin(), ans.end());
    for(int j = 0; j < ans.size(); ++j)
        cout << ans[j] << " ";
    return 0;
}
