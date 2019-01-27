#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int n, x0, y0;
struct str
{
    int x, y;
};
str v[1002];
bool viz[1002];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> x0 >> y0;
    for(int i = 1; i <= n; ++i)
        cin >> v[i].x >> v[i].y;
    int ans = 0;
    for(int i = 1; i <= n; ++i)
    {
        if(viz[i])
            continue;
        viz[i] = 1;
        int sp = i;
        for(int j = 1; j <= n; ++j)
        {
            if(viz[j])
                continue;
            long long a = (v[i].x - x0) * (v[j].y - y0);
            long long b = (v[j].x - x0) * (v[i].y - y0);
            if(a == b)
                viz[j] = 1;
        }
        ++ans;
    }
    cout << ans;
    return 0;
}
