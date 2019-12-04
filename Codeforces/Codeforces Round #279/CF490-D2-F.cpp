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

int n, v[6002], v2[6002];
int ans;
vector<int> vv[6002];
int LIS[6002], sz;
void dfs(int dad, int nod)
{
    bool gr = 0;
    int poz = 0;
    int old = 0;
    if(v[nod] > LIS[sz])
        ++gr, LIS[++sz] = v[nod];
    else
    {
        if(v[nod] <= LIS[1])
            old = LIS[1], poz = 1, LIS[1] = v[nod];
        else
        {
            int st = 1;
            int dr = sz - 1;
            int ans = 0;
            while(st <= dr)
            {
                int mid = (st + dr) / 2;
                if(v[nod] >= LIS[mid] && v[nod] < LIS[mid + 1])
                {
                    ans = mid + 1;
                    break;
                }
                else
                {
                    if(v[nod] >= LIS[mid])
                        st = mid + 1;
                    else
                        dr = mid - 1;
                }
            }
            old = LIS[ans], poz = ans, LIS[ans] = v[nod];
        }
    }
    ans = max(ans, sz);
    for(int i = 0; i < vv[nod].size(); ++i)
    {
        int vecin = vv[nod][i];
        if(vecin == dad)
            continue;
        dfs(nod, vecin);
    }
    if(gr)
        --sz;
    else
        LIS[poz] = old;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> v[i], v2[i] = v[i];
    sort(v2+1, v2+n+1);
    for(int i = 1; i <= n; ++i)
    {
        int st = 1;
        int dr = n;
        int ans = 0;
        while(st <= dr)
        {
            int mid = (st + dr) / 2;
            if(v2[mid] < v[i])
                st = mid + 1;
            else
                ans = mid, dr = mid - 1;
        }
        v[i] = ans;
    }
    for(int i = 1; i < n; ++i)
    {
        int a, b;
        cin >> a >> b;
        vv[a].pb(b);
        vv[b].pb(a);
    }
    for(int i = 1; i <= n; ++i)
        dfs(0, i);
    cout << ans;
    return 0;
}
