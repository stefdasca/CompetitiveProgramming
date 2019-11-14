#include<bits/stdc++.h>
#define god dimasi5eks
#pragma GCC optimize("O3")
#define fi first
#define se second
#define pb push_back
#define pf push_front
#define mod 1000000007

using namespace std;

typedef long long ll;

string s;

int n, sp[1000002];

int sz[1000002];

pair<int, int> mn[1000002], mn2[1000002];

pair<int, int> stk[1000002];
int solve()
{
    for(int i = 1; i <= n; ++i)
        sp[i] = sp[i-1] + (s[i] == 'R' ? 1 : -1);
    int top = 0;
    for(int i = n; i >= 1; --i)
    {
        pair<int, int> nw = {sp[i], i};
        while(top > 0 && stk[top].fi <= sp[i])
        {
            nw = min(nw, mn2[top]);
            --top;
        }
        sz[i] = top + 1;
        mn[i] = nw;
        if(top > 0)
            mn[i] = min(mn[i], mn[stk[top].se]);
        --mn[i].fi;
        stk[++top] = {sp[i], i};
        mn2[top] = nw;
    }
    int cnt = 0;
    int mx = 0;
    pair<int, int> mni = {0, 0};
    for(int i = 1; i <= n; ++i)
    {
        mni = min(mni, {sp[i], i});
        if(mx >= sp[i])
            continue;
        mx = sp[i];
        pair<int, int> mn_total = min(mni, mn[i]);
        if(mn_total.second == n)
            ++cnt;
    }
    return cnt;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> s;
    s = ' ' + s;
    n = s.size() - 1;
    int mn = 0, mx = 0;
    for(int i = 1; i <= n; ++i)
    {
        sp[i] = sp[i-1] + (s[i] == 'R' ? 1 : -1);
        if(i < n)
        {
            mn = min(mn, sp[i]);
            mx = max(mx, sp[i]);
        }
    }
    if(sp[n] > mx || sp[n] < mn)
    {
        cout << 1;
        return 0;
    }
    int ans = solve();
    for(int i = 1; i <= n; ++i)
        s[i] = (s[i] == 'R' ? 'L' : 'R');
    ans += solve();
    cout << ans;
    return 0;
}

