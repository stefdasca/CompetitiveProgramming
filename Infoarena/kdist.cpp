#include <bits/stdc++.h>
using namespace std;
ifstream f ("kdist.in");
ofstream g ("kdist.out");
typedef long long ll;
const int nmax = 200005;
struct str
{
    int val, i;
    bool x;
};
int n, T, p, dep[nmax], euler[nmax*2], first[nmax], lg2[nmax*2], col[nmax], last[nmax];
vector<int> v[nmax];
struct pp
{
    int ff, ss;
};
pp pd[19][nmax*2];
vector<str> r[nmax];
str mkt(int val, int i, bool x)
{
    str aux;
    aux.val = val;
    aux.i = i;
    aux.x = x;
    return aux;
}
void dfs(int x, int pred = 0)
{
    dep[x] = dep[pred]+1;
    ++p;
    euler[p] = x;
    first[x] = p;
    for(int i=0; i<v[x].size(); ++i)
    {
        int y=v[x][i];
        if(y != pred)
        {
            dfs(y, x);
            euler[++p] = x;
        }
    }
}
int query(int x, int y)
{
    if (x == y)
        return x;
    if(first[x] > first[y])
        swap(x, y);
    int sz = lg2[first[y]-first[x]];
    return min(pd[sz][first[x]].ss, pd[sz][first[y]-(1<<sz)].ss);
}
void rmq()
{
    for (int i = 2; i < nmax*2; ++i)
        lg2[i] = lg2[i/2]+1;
    for (int i = 1; i < p; ++i)
    {
        pd[0][i] = {euler[i], dep[euler[i]]};
        if(dep[euler[i]] > dep[euler[i+1]])
            pd[0][i] = {euler[i+1], dep[euler[i+1]]};
    }
    for (int t = 1; t <= lg2[p-1]; ++t)
        for (int i = 1; i <= p-(1<<t); ++i)
            if(pd[t-1][i].ss < pd[t-1][i+(1<<(t-1))].ss)
                pd[t][i] = pd[t-1][i];
            else
                pd[t][i] = pd[t-1][i+(1<<(t-1))];
}
ll solve(vector<str> &w)
{
    ll sol = 0;
    if(w.size() <= 1)
        return 0;
    int sz = w.size(), all;
    int pr[sz+2];
    pr[0] = w[0].x;
    for (int i = 1; i < sz; ++i)
        pr[i] = pr[i-1]+w[i].x;
    all = pr[sz-1];
    for (int i=0; i<w.size(); ++i)
    {
        str x=w[i];
        if(x.x)
            sol+=x.val*(all-1);
    }
    int rgt[sz+2], lft[sz+2], st[sz+2], vf = 0;
    rgt[sz-1] = sz;
    st[++vf] = sz-1;
    for (int i = sz-2; i >= 0; --i)
    {
        while(vf > 0 && w[i].val <= w[st[vf]].val)
            --vf;
        if(vf == 0)
            rgt[i] = sz;
        else
            rgt[i] = w[st[vf]].i;
        st[++vf] = i;
    }
    vf = 0;
    lft[0] = -1;
    st[++vf] = 0;
    for (int i = 1; i < sz; ++i)
    {
        while(vf > 0 && w[i].val < w[st[vf]].val)
            --vf;
        if(vf == 0)
            lft[i] = -1;
        else
            lft[i] = w[st[vf]].i;
        st[++vf] = i;
    }
    ll lca = 0;
    for (int i=0; i<w.size(); ++i)
    {
        str x=w[i];
        ll lo = lft[x.i]+1, hi = rgt[x.i]-1;
        lca+=1ll*x.val*(pr[hi]-pr[x.i])*(x.i!=0)*(pr[x.i-1]-(lo!=0)*pr[lo-1]);
        if(x.x)
            lca += 1ll*x.val*(pr[hi]-pr[lo]);
    }
    lca *= 2;
    sol -= lca;
    return sol;
}
int main()
{
    f >> n >> T;
    for (int i = 1; i < n; ++i)
    {
        int x, y;
        f >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    dfs(1);
    lg2[1] = 0;
    rmq();
    for (int i = 1; i <= n; ++i)
        f >> col[i];
    for (int i = 1; i <= p; ++i)
        if(last[col[euler[i]]] == 0)
        {
            r[col[euler[i]]].push_back(mkt(dep[euler[i]], 0, 1));
            last[col[euler[i]]] = i;
        }
        else if(i == first[euler[i]])
        {
            if(i-1 != first[euler[i-1]] || col[euler[i-1]] != col[euler[i]])
            {
                int in = r[col[euler[i]]].size();
                r[col[euler[i]]].push_back(mkt(query(euler[last[col[euler[i]]]], euler[i]), in, false));
            }
            int in = r[col[euler[i]]].size();
            r[col[euler[i]]].push_back(mkt(dep[euler[i]], in, true));
            last[col[euler[i]]] = i;
        }
    for (int i = 1; i <= T; ++i)
        g<<solve(r[i])<<'\n';
    return 0;
}
