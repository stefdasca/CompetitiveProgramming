/// 2222 by 1 february, thx

#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

int n, x, y, v[102];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> x >> y;
    for(int i = 1; i <= n; ++i)
        cin >> v[i];
    sort(v+1, v+n+1);
    if(x > y)
    {
        cout << n;
        return 0;
    }
    if(x <= y)
    {
        int ans = 0;
        for(int i = 1; i <= n; i += 2)
        {
            if(v[i] <= x)
                ans++;
        }
        cout << ans;
        return 0;
    }
}
