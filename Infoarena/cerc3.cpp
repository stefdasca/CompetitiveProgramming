/*
        infoarena cerc3(https://www.infoarena.ro/problema/cerc3)
        
   "Given n circles in the cartesian plane, find the minimum number of segments which have to be drawn from (0, 0) such that all the centers
of the circles are on at least one segment, and for each segment, find the biggest number of non-overlapping circles."

    This problem can be easily solved with sorting the circles by fraction x/y and use dp for each range of circles with identical ratio x/y
*/
#include<bits/stdc++.h>
using namespace std;
ifstream f("cerc3.in");
ofstream g("cerc3.out");
int n;
struct cerc
{
    int x, y, r;
    double rap;
};
cerc v[2002];
bool cmp(cerc a, cerc b)
{
    if(a.rap == b.rap)
        return a.x < b.x;
    return a.rap < b.rap;
}
int dp[2002];
int dist(int a, int b)
{
    return (v[a].x - v[b].x) * (v[a].x - v[b].x) + (v[a].y - v[b].y) * (v[a].y - v[b].y);
}
int dp2(int a, int b)
{
    int mx = 0;
    for(int i = a; i <= b; ++i)
    {
        for(int j = a; j < i; ++j)
            if(dist(i, j) > (v[i].r + v[j].r) * (v[i].r + v[j].r))
                dp[i] = max(dp[i], dp[j]);
        ++dp[i];
        if(dp[i] > mx)
            mx = dp[i];
    }
    return mx;
}
int main()
{
    f >> n;
    for(int i = 1; i <= n; ++i)
    {
        f >> v[i].x >> v[i].y >> v[i].r;
        v[i].rap = (0.00000 + v[i].x) / (0.00000 + v[i].y);
    }
    sort(v+1, v+n+1, cmp);
    int ans = 1;
    for(int i = 2; i <= n; ++i)
        if(v[i].rap != v[i-1].rap)
            ++ans;
    g << ans << " ";
    int st = 1;
    ans = 0;
    int c = 0;
    for(int i = 2; i <= n; ++i)
        if(v[i].rap != v[i-1].rap)
        {
            int mx = dp2(st, i - 1);
            st = i;
            if(mx > ans)
                ans = mx, c = 1;
            else
                if(mx == ans)
                    ++c;
        }
    int mx = dp2(st, n);
    if(mx > ans)
        ans = mx, c = 1;
    else
        if(mx == ans)
            ++c;
    g << ans << " " << c << '\n';
    return 0;
}
