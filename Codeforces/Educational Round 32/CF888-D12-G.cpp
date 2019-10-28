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

ll ans;
int val[200002];
int solve(int pw, int sta, int dra, int stb, int drb)
{
    if(dra < sta || drb < stb)
        return (1<<30);
    if(pw == -1)
        return 0;
    int mm = sta;
    while(mm <= dra && !(val[mm] & (1<<pw)))
        ++mm;
    int mm2 = stb;
    while(mm2 <= drb && !(val[mm2] & (1<<pw)))
        ++mm2;
    int ans = (1<<30);
    ans = min(ans, solve(pw - 1, sta, mm - 1, stb, mm2 - 1));
    ans = min(ans, solve(pw - 1, mm, dra, mm2, drb));
    if(ans == (1<<30))
    {
        ans = min(ans, (1<<pw) + solve(pw - 1, sta, mm - 1, mm2, drb));
        ans = min(ans, (1<<pw) + solve(pw - 1, mm, dra, stb, mm2 - 1));
    }
    return ans;
}
void di(int pw, int st, int dr)
{
    if(pw == -1)
        return;
    int mid = st;
    while(mid <= dr && !(val[mid] & (1<<pw)))
        ++mid;
    if(mid > dr || mid == st)
        di(pw - 1, st, dr);
    else
    {
        int sol = solve(pw, st, mid - 1, mid, dr);
        ans += sol;
        di(pw - 1, st, mid - 1);
        di(pw - 1, mid, dr);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> val[i];
    sort(val + 1, val + n + 1);
    di(29, 1, n);
    cout << ans << '\n';
    return 0;
}
