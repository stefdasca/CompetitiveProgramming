/*
                 https://www.infoarena.ro/problema/matrice2
    
    "Given a n*n matrix, find for q pairs of points the max cost of a road between the points in pair"
    
    We can sort the values from matrix and use dsu to find the max cost for each of the such q roads, with respect to implementation details
       
*/
#include<bits/stdc++.h>
using namespace std;
ifstream f("matrice2.in");
ofstream g("matrice2.out");
int n, q;
vector<int>v[90002];
int a[302][302], nr[302][302], cod;
int ans[50002];
int p1[20002], p2[20002];
bool pus[302][302];
int tt[100002], rg[100002], pozmrg[100002];
int val; // current value
int Find(int a)
{
    if(tt[a] == a)
        return a;
    return tt[a] = Find(tt[a]);
}
void Union(int a, int b)
{
    int nw;
    if(v[pozmrg[a]].size() > v[pozmrg[b]].size())
    {
        nw = pozmrg[a];
        for(int j = 0; j < v[pozmrg[b]].size(); ++j)
        {
            v[pozmrg[a]].push_back(v[pozmrg[b]][j]);
            int Val = v[pozmrg[b]][j];
            if(pozmrg[b] == p1[Val])
                p1[Val] = pozmrg[a];
            else
                p2[Val] = pozmrg[a];
            if(p1[Val] == p2[Val] && !ans[Val])
                ans[Val] = val;
        }
    }
    else
    {
        nw = pozmrg[b];
        for(int j = 0; j < v[pozmrg[a]].size(); ++j)
        {
            v[pozmrg[b]].push_back(v[pozmrg[a]][j]);
            int Val = v[pozmrg[a]][j];
            if(pozmrg[a] == p1[Val])
                p1[Val] = pozmrg[b];
            else
                p2[Val] = pozmrg[b];
            if(p1[Val] == p2[Val] && !ans[Val])
                ans[Val] = val;
        }
    }
    if(rg[a] > rg[b])
    {
        tt[b] = a, rg[a] += rg[b];
        pozmrg[a] = nw;
    }
    else
    {
        pozmrg[b] = nw;
        tt[a] = b, rg[b] += rg[a];
    }
}
struct no
{
    int L, C, val;
};
no zz[100002];
bool cmp(no a, no b)
{
    return a.val < b.val;
}
int ox[] = {-1, 0, 1, 0};
int oy[] = {0, 1, 0, -1};
int main()
{
    f >> n >> q;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j)
        {
            f >> a[i][j];
            ++cod;
            nr[i][j] = cod;
            zz[cod] = {i, j, a[i][j]};
        }
    sort(zz + 1, zz + cod + 1, cmp);
    for(int i = 1; i <= cod; ++i)
        tt[i] = i, rg[i] = 1, pozmrg[i] = i;
    for(int i = 1; i <= q; ++i)
    {
        int a, b, c, d;
        f >> a >> b >> c >> d;
        p1[i] = nr[a][b];
        p2[i] = nr[c][d];
        v[nr[a][b]].push_back(i);
        v[nr[c][d]].push_back(i);
    }
    for(int i = cod; i >= 1; --i)
    {
        val = zz[i].val;
        pus[zz[i].L][zz[i].C] = 1;
        for(int j = 0; j <= 3; ++j)
        {
            int Lvecin = zz[i].L + ox[j];
            int Cvecin = zz[i].C + oy[j];
            if(pus[Lvecin][Cvecin] && Find(nr[zz[i].L][zz[i].C]) != Find(nr[Lvecin][Cvecin]))
                Union(Find(nr[zz[i].L][zz[i].C]), Find(nr[Lvecin][Cvecin]));
        }
    }
    for(int i = 1; i <= q; ++i)
        g << ans[i] << '\n';
    return 0;
}
