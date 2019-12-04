#include<bits/stdc++.h>
#define god dimasi5eks
#pragma GCC optimize("O3")
#define fi first
#define se second
#define pb push_back
#define pf push_front
#define mod 1000000007
#define dancila 3.14159265359
#define eps 1e-9

using namespace std;

typedef long long ll;

int n, q, v[500002], ans[500002];

pair<int, int> qu[500002];

vector<int> vq[500002];

int val[23], poz[23];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> v[i];
    cin >> q;
    for(int i = 1; i <= q; ++i)
    {
        cin >> qu[i].fi >> qu[i].se;
        vq[qu[i].se].pb(i);
    }
    for(int i = 1; i <= n; ++i)
    {
        int vx = v[i];
        int qx = i;
        for(int j = 22; j >= 0; --j)
            if(vx & (1<<j))
            {
                if(!val[j])
                {
                    val[j] = vx;
                    poz[j] = qx;
                    break;
                }
                if(poz[j] < qx)
                {
                    swap(val[j], vx);
                    swap(poz[j], qx);
                }
                vx ^= val[j];
            }
        for(int j = 0; j < vq[i].size(); ++j)
        {
            int nr = vq[i][j];
            for(int xx = 22; xx >= 0; --xx)
                if(poz[xx] >= qu[nr].fi)
                    ans[nr] = max(ans[nr], ans[nr] ^ val[xx]);
        }
    }
    for(int i = 1; i <= q; ++i)
        cout << ans[i] << '\n';
    return 0;
}
