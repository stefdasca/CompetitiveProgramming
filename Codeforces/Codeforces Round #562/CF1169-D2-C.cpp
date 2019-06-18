#include<bits/stdc++.h>
#pragma gcc optimize("O3")
#define mati ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define fi first
#define se second
using namespace std;
typedef pair<int, int> pi;
typedef long long ll;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
int n, m;
int v[300002], unu[300002];
bool chk(int nr)
{
    for(int i = 1; i <= n; ++i)
        unu[i] = v[i];
    bool ok = 1;
    if(unu[1] + nr >= m)
        unu[1] = 0;
    for(int i = 2; i <= n; ++i)
    {
        if(unu[i] < unu[i-1])
        {
            if(unu[i] + nr >= unu[i-1])
                unu[i] = unu[i-1];
            else
                return 0;
        }
        if(unu[i] + nr >= m)
            if((unu[i] + nr) % m >= unu[i-1])
                unu[i] = unu[i-1];
    }
    return 1;
}
int main()
{
    mati
    cin >> n >> m;
    for(int i = 1; i <= n; ++i)
        cin >> v[i];
    int st = 0;
    int dr = m-1;
    int ans = m;
    while(st <= dr)
    {
        int mid = (st + dr) / 2;
        if(chk(mid))
            ans = mid, dr = mid - 1;
        else
            st = mid + 1;
    }
    cout << ans;
    return 0;
}
