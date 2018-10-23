#include<bits/stdc++.h>
using namespace std;
ifstream f("cuiburi.in");
ofstream g("cuiburi.out");
int n, sol;
struct geo
{
    int tip, xa, ya, xb, yb;
    int r;
};
geo v[2002];
int viz[2002];
vector<int>gr[2002];
int dp[2002];
bool fitrect(int i, int j)
{
    if((v[j].xa >= v[i].xa && v[j].xb <= v[i].xb) && (v[j].ya >= v[i].ya && v[j].yb <= v[i].yb))
        return 1;
    return 0;
}
bool fitcirc(int i, int j)
{
    long long aa = sqrt((v[j].xa - v[i].xa) * (v[j].xa - v[i].xa) + (v[j].ya - v[i].ya) * (v[j].ya - v[i].ya)) + v[j].r;
    if(v[i].r >= aa)
        return 1;
    return 0;
}
bool fitrectcirc(geo a, geo b)
{
    if(b.xa-a.xa < b.r)
        return 0;
    if(a.xb-b.xa < b.r)
        return 0;
    if(b.ya-a.ya < b.r)
        return 0;
    if(a.yb-b.ya < b.r)
        return 0;
    return 1;
}
bool fitcircrect(geo a, geo b)
{
    if((a.xa-b.xa)*(a.xa-b.xa)+(a.ya-b.ya)*(a.ya-b.ya) > a.r*a.r)
        return false;
    if((a.xa-b.xa)*(a.xa-b.xa)+(a.ya-b.yb)*(a.ya-b.yb) > a.r*a.r)
        return false;
    if((a.xa-b.xb)*(a.xa-b.xb)+(a.ya-b.ya)*(a.ya-b.ya) > a.r*a.r)
        return false;
    if((a.xa-b.xb)*(a.xa-b.xb)+(a.ya-b.yb)*(a.ya-b.yb) > a.r*a.r)
        return false;
    return true;
}
bool fit(int i, int j)
{
    if(v[i].tip == 1 && v[j].tip == 1)
        return fitcirc(i, j);
    if(v[i].tip == 0 && v[j].tip == 0)
        return fitrect(i, j);
    if(v[i].tip == 0 && v[j].tip == 1)
        return fitrectcirc(v[i], v[j]);
    if(v[i].tip == 1 && v[j].tip == 0)
        return fitcircrect(v[i], v[j]);
}
void dfs(int nod)
{
    viz[nod] = 1;
    for(int i = 0; i < gr[nod].size(); ++i)
    {
        int nn = gr[nod][i];
        if(!viz[nn])
            dfs(nn);
        dp[nod] = max(dp[nod], dp[nn]);
    }
    dp[nod]++;
    sol = max(sol, dp[nod]);
}
int main()
{
    f >> n;
    for(int i = 1; i <= n; ++i)
    {
        f >> v[i].tip;
        if(v[i].tip == 1)
            f >> v[i].xa >> v[i].ya >> v[i].r;
        else
            f >> v[i].xa >> v[i].ya >> v[i].xb >> v[i].yb;
    }
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j)
            if(i != j && fit(i, j))
                gr[i].push_back(j);
    for(int i = 1; i <= n; ++i)
        if(!viz[i])
            dfs(i);
    g << sol;
    return 0;
}
