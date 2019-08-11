/*
        * Let's define dp[i][j][0/1] = minimal amount of flips which are necessary to get the dish to be for j seconds on side 1, if we 
last used the ith segment, and we are on side 0/1.

        * In order to compute this value, we will be using the values for the previous segment, therefore needing only the last two lines 
of the recurrence. In order to make the computing of transitions more efficient, we are going to use a deque which will always keep 
the min value in a segment of range [l[i], r[i]].
    
        * Therefore, we are using an optimization of the naive solution, which basically reduces a factor of n from its complexity.
*/
#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#define fi first
#define se second
#define pb push_back
#define pf push_front
#define mod 1000000007

using namespace std;

typedef long long ll;


int add(int a, int b)
{
    ll x = a+b;
    if(x >= mod)
        x -= mod;
    if(x < 0)
        x += mod;
    return x;
}
ll mul(ll a, ll b)
{
    return (a*b) % mod;
}

ll pw(ll a, ll b)
{
    ll ans = 1;
    while(b)
    {
        if(b & 1)
            ans = (ans * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return ans;
}
int n, k, dp[2][100005][2], l[105], r[105];
int dq[100005],stq,drq;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;
    for(int i = 1; i <= k; ++i)
        cin >> l[i] >> r[i];
    for(int i = 0; i <= n; i++)
    {
        dp[0][i][0] = 1 << 28;
        dp[0][i][1] = 1 << 28;
    }
    dp[0][0][0] = 0;
    for(int i = 1, la = 1 ;i <= k; i++, la ^= 1)
    {
        stq = 1;drq = 0;
        for(int j = 0; j <= n; j++)
        {
            dp[la][j][0] = dp[la ^ 1][j][0];
            dp[la][j][1] = (r[i] - r[i - 1] <= j ? dp[la ^ 1][j - r[i] + r[i - 1]][1] : 1 << 28);
            while(stq <= drq && j - dq[stq] > r[i] - l[i])
                stq++;
            while(stq <= drq && dp[!la][dq[drq]][0] > dp[!la][j][0])
                drq--;
            dq[++drq] = j;
            dp[la][j][0] = min(dp[la][j][0],dp[!la][dq[stq]][0] + 2);
            dp[la][j][1] = min(dp[la][j][1],dp[!la][dq[stq]][0] + 1);
        }
        stq = 1;drq = 0;
        for(int j = 0;j <= n;j++)
        {
            while(stq <= drq && j - dq[stq] > r[i] - r[i - 1])
                stq++;
            if(j + r[i - 1] >= l[i])
            {
                while(stq <= drq && dp[!la][dq[drq]][1] > dp[!la][j + r[i - 1] - l[i]][1])
                    drq--;
                dq[++drq] = j + r[i - 1] - l[i];
            }
            if(stq <= drq)
            {
                dp[la][j][0] = min(dp[la][j][0],dp[la ^ 1][dq[stq]][1] + 1);
                dp[la][j][1] = min(dp[la][j][1],dp[la ^ 1][dq[stq]][1] + 2);
            }
        }
    }
    int tmp = min(dp[k & 1][n][0],(n - (2 * n - r[k]) >= 0 ? dp[k & 1][n - (2 * n - r[k])][1]:1 << 28));
    if(tmp == 1 << 28)
    {
        cout << "Hungry\n";
        return 0;
    }
    cout << "Full\n" << tmp << '\n';
    return 0;
}
