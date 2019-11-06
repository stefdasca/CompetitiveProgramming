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

int n;
string s, t;
int ordup[1000002], orddwn[1000002], nrdwn, nrupp, pzup[1000002], pzdwn[1000002];
ll sumup[1000002], sumdwn[1000002];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    cin >> s;
    s = ' ' + s;
    for(int i = 1; i <= n; ++i)
    {
        if(s[i] == 'U')
            ordup[++nrupp] = i;
        else
            orddwn[++nrdwn] = i;
        pzup[i] = nrupp;
        pzdwn[i] = nrdwn;
    }
    for(int i = 1; i <= nrupp; ++i)
        sumup[i] = sumup[i-1] + 2 * ordup[i];
    for(int i = 1; i <= nrdwn; ++i)
        sumdwn[i] = sumdwn[i-1] + 2 * orddwn[i];
    for(int i = 1; i <= n; ++i)
    {
        ll ans = 0;
        ll mindif = 0;
        if(s[i] == 'U')
        {
            if(pzup[i-1] >= nrdwn - pzdwn[i])
            {
                ans = n - i + 1;
                mindif = nrdwn - pzdwn[i];
                ans += sumdwn[pzdwn[i] + mindif] - sumdwn[pzdwn[i]];
                ans -= sumup[pzup[i-1]] - sumup[pzup[i-1] - mindif];
            }
            else
            {
                ans = -i;
                mindif = pzup[i-1];
                ans += sumdwn[pzdwn[i] + mindif + 1] - sumdwn[pzdwn[i]];
                ans -= sumup[pzup[i-1]] - sumup[pzup[i-1] - mindif];
            }
        }
        else
        {
            if(pzup[i-1] > nrdwn - pzdwn[i])
            {
                ans = n + 1 + i;
                mindif = nrdwn - pzdwn[i];
                ans += sumdwn[pzdwn[i] + mindif] - sumdwn[pzdwn[i]];
                ans -= sumup[pzup[i-1]] - sumup[pzup[i-1] - mindif - 1];
            }
            else
            {
                ans = i;
                mindif = pzup[i-1];
                ans += sumdwn[pzdwn[i] + mindif] - sumdwn[pzdwn[i]];
                ans -= sumup[pzup[i-1]] - sumup[pzup[i-1] - mindif];
            }
        }
        cout << ans << " ";
    }
    return 0;
}
