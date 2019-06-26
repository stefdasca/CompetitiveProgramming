#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int q, n;
int v[200002];
int frq[200002], frq2[200002];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> q;
    for(; q; --q)
    {
        cin >> n;
        for(int i = 1; i <= n; ++i)
        {
            int nr;
            cin >> nr;
            frq[nr]++;
        }
        for(int i = 1; i <= n; ++i)
            if(frq[i] != 0)
                frq2[frq[i]]++;
        int p2 = n;
        long long ans = 0;
        for(int i = n; i >= 1; --i)
        {
            while(frq2[p2] == 0 && p2 >= i)
                --p2;
            if(p2 >= i)
            {
                ans += i;
                --frq2[p2];
            }
        }
        cout << ans << '\n';
        for(int i = 1; i <= n; ++i)
            frq[i] = 0, frq2[i] = 0;
    }
    return 0;
}

