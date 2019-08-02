/*
        Infoarena sir3(google translate does a decent enough job at translating the statement)
    
    Let's keep for every distinct number in array the position of its complement(S - v[i]) and with those positions, we are going to create 
two segment trees, one for max-query and one for min-query. If complement is situated in right of the original element, we are going to ask 
a query to check whether the minimum in range [i, complement[i] is equal to position of original element and 
maximum in range [i, complement[i] is equal to position of the complement. This works because if we have an element which has complement 
in left or in right of the interval, min or max will be outside of the range. 

*/
#include<bits/stdc++.h>
using namespace std;
ifstream f("sir3.in");
ofstream g("sir3.out");
int n, s;
int v[200002];
int ct[200002];
map<int, int> mp;
int mx[800002], mn[800002];
void build(int nod, int st, int dr)
{
    if(st == dr)
    {
        mx[nod] = ct[st];
        mn[nod] = ct[st];
        return;
    }
    int mid = (st + dr) / 2;
    build(nod << 1, st, mid);
    build(nod << 1|1, mid+1, dr);
    mx[nod] = max(mx[nod << 1], mx[nod << 1|1]);
    mn[nod] = min(mn[nod << 1], mn[nod << 1|1]);
}
int mxx, mnn;
void query(int nod, int st, int dr, int L, int R)
{
    if(dr < L || st > R)
        return;
    if(L <= st && dr <= R)
    {
        mxx = max(mxx, mx[nod]);
        mnn = min(mnn, mn[nod]);
        return;
    }
    int mid = (st + dr) / 2;
    query(nod << 1, st, mid, L, R);
    query(nod << 1|1, mid+1, dr, L, R);
}
int main()
{
    f >> n >> s;
    for(int i = 1; i <= n; ++i)
        f >> v[i], mp[v[i]] = i;
    for(int i = 1; i <= n; ++i)
        if(mp.find(s - v[i]) != mp.end())
            ct[i] = mp[s - v[i]];
    build(1, 1, n);
    int ans = 0, Lf = 0, Rg = 0;
    for(int i = 1; i <= n; ++i)
    {
        if(ct[i] > i)
        {
            mxx = 0;
            mnn = n+1;
            query(1, 1, n, i, ct[i]);
            if(mnn == i && mxx == ct[i])
                if(ct[i] - i + 1 > ans)
                    ans = ct[i] - i + 1, Lf = i, Rg = ct[i];
        }
        else
            if(ct[i] == i && ans == 0)
                ans = 1, Lf = Rg = i;
    }
    g << ans << " " << Lf << " " << Rg << '\n';
    return 0;
}
