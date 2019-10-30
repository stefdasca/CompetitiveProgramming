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

int n, ct1[102], ct2[102];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j)
        {
            char c;
            cin >> c;
            if(c == 'C')
                ++ct1[i], ++ct2[j];
        }
    int ans = 0;
    for(int i = 1; i <= n; ++i)
    {
        ans += 1LL * ct1[i] * (ct1[i] - 1) / 2;
        ans += 1LL * ct2[i] * (ct2[i] - 1) / 2;
    }
    cout << ans;
    return 0;
}
