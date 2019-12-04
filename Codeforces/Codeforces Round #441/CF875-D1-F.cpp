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

int n, m;

struct roses
{
    int a, b, c;
};
roses v[200002];

bool cmp(roses a, roses b)
{
    return a.c < b.c;
}

int tt[200002], rg[200002], used[200002];

int Find(int nod)
{
    if(tt[nod] == nod)
        return nod;
    return tt[nod] = Find(tt[nod]);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i = 1; i <= n; ++i)
        tt[i] = i, rg[i] = 1;
    for(int i = 1; i <= m; ++i)
        cin >> v[i].a >> v[i].b >> v[i].c;
    sort(v+1, v+m+1, cmp);
    int ans = 0;
    for(int i = m; i >= 1; --i)
    {
        int ta = Find(v[i].a);
        int tb = Find(v[i].b);
        if(ta != tb && (!used[ta] || !used[tb]))
            tt[ta] = tb, used[tb] |= used[ta], ans += v[i].c;
        else
            if(ta == tb && !used[ta])
                used[ta] = 1, ans += v[i].c;
    }
    cout << ans;
    return 0;
}

