/*
                Infoarena tricolor(https://www.infoarena.ro/problema/tricolor)
    "Given a tree with n nodes, color the tree nodes in black or white so that the number of (unordered) pairs of twin nodes is maximum.
Two nodes are twinned if and only if both are white and either are bound directly by an edge, or the single elemental chain of them contains
only black nodes."


    We will use dynamic programming approach. Let's define dpb[i][j] = maximum number of pairs of twinned pairs in subtree of i if i is colored
in black and one can get to j white vertexes by visiting only black vertexes in between. We will also define dpw[i] = maximum number of pairs of
twinned pairs in subtree of i if i is colored in white. For each node, we will update those values using values from its sons solving some cases
(color of ith son is black or white). One has also to be careful at overcounting stuff. Official solution is O(n^2) but it seems like an amortized
O(n^3) will also work thanks to the fact that most of the states are not visited at all and I also found the official explanation of O(n^2) solution
hard to understand because they skip some details I consider important for their proof.

*/

#include<bits/stdc++.h>
using namespace std;
ifstream f("tricolor.in");
ofstream g("tricolor.out");
int t;
int n;
vector<int>v[5002];
int dpb[5002][5002], dpw[5002];
bool vizb[5002][5002], vizw[5002];
int sz[5002];
void subtreesize(int dad, int nod)
{
    sz[nod] = 1;
    for(int i = 0; i < v[nod].size(); ++i)
    {
        int vecin = v[nod][i];
        if(vecin == dad)
            continue;
        subtreesize(nod, vecin);
        sz[nod] += sz[vecin];
    }
}
void dfs(int dad, int nod)
{
    if(v[nod].size() == 1 && nod != 1)
        return;
    int arrb[sz[nod] + 2];
    bool vz[sz[nod] + 2];
    memset(arrb, 0, sizeof(arrb));
    memset(vz, 0, sizeof(vz));
    vz[0] = 1;
    int mx = 0;
    int cw = 0;
    for(int i = 0; i < v[nod].size(); ++i)
    {
        int vecin = v[nod][i];
        if(vecin == dad)
            continue;
        dfs(nod, vecin);
        int zz = 0;
        for(int j = 0; j <= sz[nod]; ++j)
            if(vizb[vecin][j])
                zz = max(zz, dpb[vecin][j] + j * (j+1) / 2);
        vector<int>gg;
        vector<int>org;
        for(int j = 0; j <= sz[nod]; ++j)
            if(vz[j])
                gg.push_back(j), org.push_back(arrb[j]);
        for(int j = sz[vecin]; j >= 0; --j)
            if(vizb[vecin][j])
            {
                for(int p = gg.size() - 1; p >= 0; --p)
                {
                    int k = gg[p];
                    if(vz[k])
                    {
                        vz[j + k] = 1;
                        arrb[j + k] = max(arrb[j + k], org[p] + dpb[vecin][j]);
                    }
                }
            }
        for(int p = gg.size() - 1; p >= 0; --p)
        {
            int k = gg[p];
            vz[k + 1] = 1;
            arrb[k + 1] = max(arrb[k + 1], org[p] + dpw[vecin]);
        }
        zz = max(zz, dpw[vecin] + 1);
        mx += zz;
    }
    for(int j = 0; j <= sz[nod]; ++j)
        if(vz[j])
            dpb[nod][j] = arrb[j], vizb[nod][j] = 1;
    dpw[nod] = mx;
}
int main()
{
    f >> t;
    for(; t; --t)
    {
        for(int i = 1; i <= n; ++i)
        {
            v[i].clear();
            for(int k = 0; k <= n; ++k)
                dpb[i][k] = 0, vizb[i][k] = 0;
            dpw[i] = 0;
            vizw[i] = 0;
        }
        f >> n;
        for(int i = 1; i < n; ++i)
        {
            int a, b;
            f >> a >> b;
            v[a].push_back(b);
            v[b].push_back(a);
        }
        subtreesize(0, 1);
        dfs(0, 1);
        int ans = dpw[1];
        for(int j = 0; j <= n; ++j)
            if(vizb[1][j])
                ans = max(ans, dpb[1][j] + j * (j-1) / 2);
        g << ans << '\n';
    }
    return 0;
}
