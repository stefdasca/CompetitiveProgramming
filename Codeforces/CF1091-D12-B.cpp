/// Never do the same mistake twice

#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int n;
struct puncte
{
    int x, y;
};
puncte v[1002];
puncte p2[1002];
struct date
{
    int x, y, pz;
};
date vv[1000002];
bool cmp(date a, date b)
{
    if(a.x == b.x)
        return a.y < b.y;
    return a.x < b.x;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> v[i].x >> v[i].y;
    for(int i = 1; i <= n; ++i)
        cin >> p2[i].x >> p2[i].y;
    int zz = 0;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j)
            vv[++zz] = {v[i].x + p2[j].x, v[i].y + p2[j].y, i};
    sort(vv+1, vv + zz + 1, cmp);
    for(int i = n; i <= zz; ++i)
        if(vv[i].x == vv[i - n + 1].x && vv[i].y == vv[i - n + 1].y)
        {
            cout << vv[i].x << " " << vv[i].y << '\n';
            return 0;
        }
    return 0;
}
