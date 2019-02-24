/*
            Infoarena troll(https://www.infoarena.ro/problema/troll)
            
     "given n ranges of type (a, b, C), where range i has the ends [ai, bi] and value Ci, find the maximum number of ranges which are not 
 overlapping, such that at least one of them contains a range with Ci such that Ci is maximal among Ci from the array"
 
    At first, we can sort the intervals with increasing a, then we can use dp to solve this problem. dp[i][j] = the max number of intervals, 
such that the last range used is the jth, and i = 1 if we already got a range with maximal value, and 0 otherwise. I implemented the dp using
fenwick tree, for fast transition between states. 
       
*/
#include<bits/stdc++.h>
using namespace std;
ifstream f("troll.in");
ofstream g("troll.out");
int n;
struct st
{
    int a, b, c;
};
st v[100002];
bool cmp(st a, st b)
{
    return a.a < b.a;
}
int aib[2][200002], vs[200002];
int cb(int poz)
{
    int s = 1;
    int d = 2 * n;
    int ans = 0;
    while(s <= d)
    {
        int mid = (s + d) / 2;
        if(vs[mid] <= poz)
            ans = mid, s = mid + 1;
        else
            d = mid - 1;
    }
    return ans;
}
void update(int un, int st, int vv)
{
    for(; st <= 2 * n; st += (st & (-st)))
        aib[un][st] = max(aib[un][st], vv);
}
int compute(int un, int st)
{
    int ans = 0;
    for(; st; st -= (st & (-st)))
        ans = max(ans, aib[un][st]);
    return ans;
}
int main()
{
    f >> n;
    int mx = -1338;
    for(int i = 1; i <= n; ++i)
        f >> v[i].a >> v[i].b >> v[i].c, mx = max(mx, v[i].c);
    sort(v+1, v+n+1, cmp);
    for(int i = 1; i <= n; ++i)
    {
        vs[2 * i - 1] = v[i].a;
        vs[2 * i] = v[i].b;
    }
    sort(vs + 1, vs + 2 * n + 1);
    int maxx = 0;
    int ss = 0;
    for(int i = 1; i <= n; ++i)
    {
        int pz = cb(v[i].a);
        int aa = compute(1, pz - 1);
        int pz2 = cb(v[i].b);
        if(aa)
        {
            update(1, pz2, aa + 1);
            maxx = max(maxx, aa + 1);
        }
        aa = compute(0, pz - 1);
        update((v[i].c == mx), pz2, aa + 1);
        if(v[i].c == mx)
            maxx = max(maxx, aa + 1);
    }
    g << mx << " " << maxx << '\n';
    return 0;
}
