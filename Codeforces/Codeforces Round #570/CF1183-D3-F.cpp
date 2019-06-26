#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int q;
int n, v[200002], v2[200002];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> q;
    for(; q; --q)
    {
        cin >> n;
        for(int i = 1; i <= n; ++i)
            cin >> v[i];
        if(n == 1)
        {
            cout << v[1] << '\n';
            continue;
        }
        sort(v+1, v+n+1);
        int ans1 = 0, ans2 = 0;
        for(int i = n-1; i >= 1; --i)
            if(ans1 == 0 && v[n] % v[i])
                ans1 += v[i];
            else
                if(ans1 % v[i] && v[n] % v[i])
                {
                    ans1 += v[i];
                    break;
                }
        for(int i = n-2; i >= 1; --i)
            if(ans2 == 0 && v[n-1] % v[i])
                ans2 += v[i];
            else
                if(ans2 % v[i] && v[n-1] % v[i])
                {
                    ans2 += v[i];
                    break;
                }
        cout << max(ans1 + v[n], ans2 + v[n-1]) << '\n';
    }
    return 0;
}

