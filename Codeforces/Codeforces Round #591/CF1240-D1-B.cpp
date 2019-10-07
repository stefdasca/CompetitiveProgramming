#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#define fi first
#define se second
#define pb push_back
#define pf push_front
#define mod 1000000007

using namespace std;

typedef long long ll;

int n, ds;

struct el
{
    int x, y;
};
el v[300002];
int dp[300002];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    for(; t; --t)
    {
        cin >> n;
        for(int i = 1; i <= n; ++i)
            v[i].x = v[i].y = dp[i] = 0;
        ds = 0;
        for(int i = 1; i <= n; ++i)
        {
            int nr;
            cin >> nr;
            if(!v[nr].x)
                v[nr].x = i, ++ds;
            v[nr].y = i;
        }
        int mx = 0;
        int prv = 0;
        for(int i = 1; i <= n; ++i)
        {
            if(!v[i].x)
                continue;
            if(v[i].x > v[prv].y)
                dp[i] = dp[prv] + 1;
            else
                dp[i] = 1;
            mx = max(mx, dp[i]);
            prv = i;
        }
        cout << ds - mx << '\n';
    }
    return 0;
}
