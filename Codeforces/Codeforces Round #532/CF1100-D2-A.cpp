/// 2222 by 1 february, thx

#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int n, k;
int v[102];
bool closed[102];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;
    for(int i = 1; i <= n; ++i)
        cin >> v[i];
    int mx = -200;
    for(int i = 1; i <= n; ++i)
    {
        memset(closed, 0, sizeof(closed));
        int z = i;
        while(z > 0)
            closed[z] = 1, z -= k;
        z = i;
        while(z <= n)
            closed[z] = 1, z += k;
        int sn = 0, sc = 0;
        for(int j = 1; j <= n; ++j)
            if(!closed[j])
            {
                if(v[j] == -1)
                    ++sn;
                else
                    ++sc;
            }
        mx = max(mx, abs(sn - sc));
    }
    cout << mx;
    return 0;
}


