/*
        infoarena minuni(https://www.infoarena.ro/problema/minuni)
        
    "Given n towns placed in a line, where the ith town is at distance i from origin, and m queries of type a b(a road is added from a to b)
find how many pairs of cities are getting closer after each query"
    
    From the restrictions of the problem we know that the roads are either one included in another, or not intersecting at all. 
    We will use segment tree to find for a road whether it's included in another road added before or not, and from that point it becomes
a simple casework problem.
*/
#include<bits/stdc++.h>
using namespace std;
ifstream f("minuni.in");
ofstream g("minuni.out");
int n, m;
int sortt[100002];
int aint[400002];
struct query
{
    int x, y;
};
query v[100002];
void upd(int nod, int st, int dr, int poz, int val)
{
    if(st == dr)
    {
        aint[nod] = val;
        return;
    }
    int mid = (st + dr) / 2;
    if(poz <= mid)
        upd(nod << 1, st, mid, poz, val);
    else
        upd(nod << 1|1, mid+1, dr, poz, val);
    aint[nod] = max(aint[nod << 1], aint[nod << 1|1]);
}
int nn = 0;
int que(int nod, int st, int dr, int L, int R)
{
    int mid = (st + dr) / 2;
    if(L <= st && dr <= R)
    {
        if(st == dr)
            return aint[nod];
        if(aint[nod << 1|1] > nn)
            return que(nod << 1|1, mid+1, dr, L, R);
        if(aint[nod << 1] > nn)
            return que(nod << 1, st, mid, L, R);
        return 0;
    }
    if(dr < L || st > R)
        return -(1<<30);
    int aa = que(nod << 1|1, mid+1, dr, L, R);
    if(aa > nn)
        return aa;
    int bb = que(nod << 1, st, mid, L, R);
    if(bb > nn)
        return bb;
    return 0;
}
int cb(int x)
{
    int st = 1;
    int dr = m;
    int ans;
    while(st <= dr)
    {
        int mid = (st + dr) / 2;
        if(sortt[mid] <= x)
            ans = mid, st = mid + 1;
        else
            dr = mid - 1;
    }
    return ans;
}
map<int, int> mp;
int main()
{
    f >> n >> m;
    for(int i = 1; i <= m; ++i)
        f >> v[i].x >> v[i].y, sortt[i] = v[i].x, mp[v[i].y] = v[i].x;
    sort(sortt + 1, sortt + m + 1);
    for(int i = 1; i <= m; ++i)
    {
        int poz = cb(v[i].x);
        nn = v[i].x;
        int mx = que(1, 1, m, 1, poz-1);
        long long ans = (n - v[i].y + 1);
        if(mx < v[i].x)
            g << ans * v[i].x << '\n';
        else
        {
            int ox = mp[mx];
            long long sol = 1LL * ox * (mx - v[i].y) + ans * (v[i].x - ox);
            g << sol << '\n';
        }
        upd(1, 1, m, poz, v[i].y);
    }
    return 0;
}
