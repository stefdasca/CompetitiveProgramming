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

int n;
pair<int, int> op[100002];

set<int> s;
map<int, int> mp;

int m, x, v[200002], v2[200002], aib[200002];

void add(int nod)
{
    for(; nod <= x; nod += (nod & (-nod)))
        aib[nod]++;
}
int compute(int nod)
{
    int ans = 0;
    for(; nod; nod -= (nod & (-nod)))
        ans += aib[nod];
    return ans;
}

int cb(int poz)
{
    int st = 1;
    int dr = x;
    int ans = 0;
    while(st <= dr)
    {
        int mid = (st + dr) / 2;
        if(v[mid] <= poz)
            ans = mid, st = mid + 1;
        else
            dr = mid - 1;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> m;
    for(int i = 1; i <= m; ++i)
    {
        cin >> op[i].fi >> op[i].se;
        s.insert(op[i].fi);
        s.insert(op[i].se);
        n = max(n, op[i].fi);
        n = max(n, op[i].se);
    }
    while(!s.empty())
    {
        ++x;
        v[x] = *s.begin();
        mp[v[x]] = x;
        s.erase(v[x]);
    }
    for(int i = 1; i <= x; ++i)
        v2[i] = v[i];
    ll ans = 0;
    for(int i = 1; i <= m; ++i)
    {
        int aa = mp[op[i].fi];
        int bb = mp[op[i].se];
        swap(v2[aa], v2[bb]);
    }
    for(int i = 1; i <= x; ++i)
    {
        int aa = mp[v2[i]];
        ans += (i - 1) - compute(aa);
        add(aa);
    }
    for(int i = 1; i <= x; ++i)
    {
        if(v2[i] < v[i])
        {
            ans += v[i] - v2[i];
            ans -= cb(v[i]) - cb(v2[i]);
        }
        else
            if(v2[i] > v[i])
            {
                ans += v2[i] - v[i];
                ans -= cb(v2[i]) - cb(v[i]);
            }
       // cout << ans << '\n';
    }
    cout << ans;
    return 0;
}
