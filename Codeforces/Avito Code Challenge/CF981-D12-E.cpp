#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#define mod 1000000007
using namespace std;
int n, q;
struct que
{
    int st, dr, val;
};
que v[10002], v2[10002];
bool cmp(que a, que b)
{
    return a.st < b.st;
}
bool cmp2(que a, que b)
{
    return a.dr < b.dr;
}
bool was[10002];
long long dp[10002], dp2[10002];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> q;
    for(int i = 1; i <= q; ++i)
        cin >> v[i].st >> v[i].dr >> v[i].val, v2[i] = v[i];
    sort(v + 1, v + q + 1, cmp);
    sort(v2 + 1, v2 + q + 1, cmp2);
    dp[0] = 1;
    int a = 1;
    int b = 1;
    v[q + 1].st = n+1;
    v2[q + 1].dr = n+1;
    while(a <= q || b <= q)
    {
        if(v[a].st <= v2[b].dr)
        {
            for(int j = n; j >= v[a].val; --j)
            {
                dp[j] = (dp[j] + dp[j - v[a].val]);
                if(dp[j] >= mod)
                    dp[j] -= mod;
            }
            ++a;
        }
        else
        {
            for(int j = v2[b].val; j <= n; ++j)
            {
                dp[j] = (dp[j] - dp[j - v2[b].val] + mod);
                if(dp[j] >= mod)
                    dp[j] -= mod;
            }
            ++b;
        }
        for(int j = 1; j <= n; ++j)
            if(dp[j])
                was[j] = 1;
    }
    int nr = 0;
    for(int j = 1; j <= n; ++j)
        nr += was[j];
    cout << nr << '\n';
    for(int j = 1; j <= n; ++j)
        if(was[j])
            cout << j << " ";
    return 0;
}

