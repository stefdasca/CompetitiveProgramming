#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int n, k;
long long v[52], pr[52], ans;
bool ok[52][52];
bool chk(long long targ, long long mask)
{
    memset(ok, false, sizeof(ok));
    ok[0][0] = 1;
    for (int i = 1; i <= n; ++i)
        for (int j = 0; j < i; ++j)
            if (((pr[i] - pr[j]) & mask & targ) == targ)
                for (int k = 0; k < 51; ++k)
                    if (ok[j][k])
                        ok[i][k + 1] = 1;
    return ok[n][k];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;
    for(int i = 1; i <= n; ++i)
        cin >> v[i], pr[i] = pr[i-1] + v[i];
    for(int i = 56; i >= 0; --i)
        if(chk(ans | (1LL<<i), ~((1LL << i) - 1)))
            ans |= (1LL<<i);
    cout << ans;
    return 0;
}
