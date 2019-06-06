#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int t;
int n, k;
int v[200002];
int check(int dist)
{
    int sec = 1;
    for(int i = 1; i <= n; ++i)
    {
        while(sec + 1 <= n && v[sec + 1] - v[i] <= 2 * dist)
            ++sec;
        int nrp = sec - i + 1;
        if(nrp >= k)
            return v[i] + dist;
    }
    return -1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    for(; t; --t)
    {
        cin >> n >> k;
        ++k;
        for(int i = 1; i <= n; ++i)
            cin >> v[i];
        int st = 0;
        int dr = 1000000001;
        int ans = 0;
        int val = 0;
        while(st <= dr)
        {
            int mid = (st + dr) / 2;
            if(check(mid) != -1)
                ans = mid, val = check(mid), dr = mid - 1;
            else
                st = mid + 1;
        }
        cout << val << '\n';
    }
    return 0;
}

