#include<bits/stdc++.h>
using namespace std;
ifstream f("mostenire3.in");
ofstream g("mostenire3.out");
int n, k, v[100002];
bool check(int vl)
{
    int qq = 0;
    int um = 0;
    for(int i = 1; i <= n; ++i)
    {
        qq += v[i];
        if(qq >= vl)
        {
            qq = 0;
            um++;
        }
    }
    if(um < k)
        return 0;
    return 1;
}
struct sp
{
    int st, dr;
    int vl;
};
sp v0[102];
bool used[102];
int vvv[102];
bool cmp(int a, int b)
{
    if(v0[a].vl == v0[b].vl)
        return v0[a].st < v0[b].st;
    return v0[a].vl < v0[b].vl;
}
int main()
{
    f >> n >> k;
    for(int i = 1; i <= n; ++i)
        f >> v[i];
    int st = 1;
    int dr = 1000000000;
    int ans = 0;
    while(st <= dr)
    {
        int mid = (st + dr) / 2;
        if(check(mid))
            ans = mid, st = mid + 1;
        else
            dr = mid - 1;
    }
    g << ans << '\n';
    int qq = 0;
    int ff = 0;
    int L = 1;
    for(int i = 1; i <= n; ++i)
    {
        qq += v[i];
        if(qq >= ans)
        {
            ++ff;
            v0[ff] = {L, i, qq};
            vvv[ff] = ff;
            L = i + 1;
            qq = 0;
        }
    }
    if(qq != 0)
        v0[ff] = {v0[ff].st, n, qq + v0[ff].vl};
    sort(vvv + 1, vvv + ff + 1, cmp);
    for(int i = 1; i <= k; ++i)
    {
        for(int j = 1; j <= k; ++j)
            if(!used[j] && v0[vvv[j]].vl == v0[i].vl)
            {
                g << k - j + 1 << " " << v0[vvv[j]].dr - v0[vvv[j]].st + 1 << '\n';
                used[j] = 1;
                break;
            }
    }
    return 0;
}
