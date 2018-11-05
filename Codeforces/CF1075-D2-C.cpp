#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int n, m;
int ans = 1202222;
int oy[100002];
struct vert
{
    int x1, x2, y;
};
vert v[100002];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i = 1; i <= n; ++i)
        cin >> oy[i];
    sort(oy + 1, oy + n + 1);
    int cate = 0;
    deque<int>d;
    for(int i = 1; i <= m; ++i)
    {
        cin >> v[i].x1 >> v[i].x2 >> v[i].y;
        if(v[i].x1 == 1)
            d.push_back(v[i].x2);
    }
    sort(d.begin(), d.end(), greater<int>());
    for(int i = 1; i <= n; ++i)
    {
        cate = i-1;
        while(!d.empty() && d.back() < oy[i])
            d.pop_back();
        int nr = d.size();
        ans = min(ans, cate + nr);
    }
    while(!d.empty() && d.back() < 1000000000)
        d.pop_back();
    int nr = d.size();
    ans = min(ans, n + nr);
    cout << ans;
    return 0;
}
