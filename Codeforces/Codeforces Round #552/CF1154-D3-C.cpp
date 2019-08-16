#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;
int v[4], v2[4];
int a2, b2, c2;
int tip[] = {0, 1, 2, 3, 1, 3, 2, 1};
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> v[1] >> v[2] >> v[3];
    int ans = 0;
    for(int st = 1; st <= 7; ++st)
    {
        v2[1] = v[1], v2[2] = v[2], v2[3] = v[3];
        int mx = 0;
        bool rau = 0;
        for(int z = st; z <= 7; ++z)
        {
            if(v2[tip[z]])
                ++mx, v2[tip[z]]--;
            else
            {
                rau = 1;
                break;
            }
        }
        if(!rau)
        {
            int zz = min(v2[1] / 3, min(v2[2] / 2, v2[3] / 2));
            mx += 7 * zz;
            v2[1] -= 3 * zz;
            v2[2] -= 2 * zz;
            v2[3] -= 2 * zz;
            for(int j = 1; j <= 7; ++j)
            {
                if(v2[tip[j]])
                    ++mx, --v2[tip[j]];
                else
                    break;
            }
        }
        ans = max(ans, mx);
    }
    cout << ans;
    return 0;
}
