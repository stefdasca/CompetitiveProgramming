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

int n, L, R, k;
int v[100002], mn[100002], mx[100002], ans[100002];

int intinv(int a, int b, int c, int d)
{
    a = max(a, c);
    b = min(b, d);
    return a;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> L >> R >> k;
    for(int i = 1; i <= n; ++i)
        cin >> v[i];
    mn[n] = L;
    mx[n] = R;
    for(int i = n-1; i >= 1; --i)
    {
        if(v[i] == v[i+1])
        {
            mx[i] = mx[i+1];
            mn[i] = mn[i+1];
        }
        else
        {
            if(v[i] > v[i+1])
            {
                mn[i] = mn[i+1] + 1;
                mx[i] = min(mx[i+1] + k, R);
            }
            else
            {
                mn[i] = max(mn[i+1] - k, L);
                mx[i] = mx[i+1] - 1;
            }
        }
        if(mn[i] > R || mx[i] < L)
        {
            cout << -1;
            return 0;
        }
    }
    ans[1] = mn[1];
    cout << mn[1] << " ";
    for(int i = 2; i <= n; ++i)
    {
        if(v[i] == v[i-1])
            ans[i] = ans[i-1];
        else
        {
            if(v[i] > v[i-1])
                ans[i] = intinv(ans[i-1] + 1, ans[i-1] + k, mn[i], mx[i]);
            else
                ans[i] = intinv(ans[i-1] - k, ans[i-1] - 1, mn[i], mx[i]);
        }
        cout << ans[i] << " ";
    }
    return 0;
}
