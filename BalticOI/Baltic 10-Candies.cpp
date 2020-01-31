/*
        Baltic 10-Candies

    We can run knapsack in order to find whether we can achieve a certain sum. One can do this easily by finding the answer mod some big prime.

    In order to see what happens when we remove some element, we are going to drop the solution counts from knapsack from bottom to top, in
a similar approach to how we built it. The best answer is given by the number which lets as many sums available as possible, because we can
always double the number by adding(sum of all other elements + 1).

    In order to find the smallest number to add, we are going to run again knapsack, but this time with all the numbers, except for the one
we found out to be the best one(we will use their opposites too), because if we have two possible sums after dropping equal to x and y, our answer
can't be equal to abs(x - y) for all possible x and y.

    The second knapsack will contain the number of ways to achieve some sum using
        v[1], -v[1], v[2], -v[2], ...., v[n-1], -v[n-1]
    (we replace the position where we found the best number with the last one)

    The second answer will therefore be the smallest positive number not present in knapsack.

*/
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

// #define fisier 1

using namespace std;

typedef long long ll;

int n, v[102];

int dp[700002], dp2[700002];

int frq[700002];

int ruk[1400002];
int main()
{

    #ifdef fisier
        ifstream f("input.in");
        ofstream g("output.out");
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    int cmmdc = 0;
    for(int i = 1; i <= n; ++i)
    {
        cin >> v[i];
        if(i == 1)
            cmmdc = v[i];
        else
            cmmdc = __gcd(cmmdc, v[i]);
    }
    sort(v+1, v+n+1);
    if(cmmdc != 1)
    {
        cout << v[1] << " " << 1 << '\n';
        return 0;
    }
    dp[0] = 1;
    int sum = 0;
    for(int i = 1; i <= n; ++i)
    {
        for(int j = sum; j >= 0; --j)
        {
            dp[j + v[i]] += dp[j];
            if(dp[j + v[i]] >= mod)
                dp[j + v[i]] -= mod;
        }
        sum += v[i];
    }
    int tb = 0;
    for(int i = 0; i <= sum; ++i)
        tb += (dp[i] > 0);
    int mx = 0, wh = 0, wh2 = 0;
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 0; j <= sum; ++j)
            dp2[j] = dp[j];
        for(int j = v[i]; j <= sum; ++j)
        {
            dp2[j] -= dp2[j - v[i]];
            if(dp2[j] < 0)
                dp2[j] += mod;
        }
        int tb2 = 0;
        for(int j = 0; j <= sum; ++j)
            tb2 += (dp2[j] > 0);
        int prd = sum - v[i] + 1;
        if(tb2 + tb2 - tb > mx)
            mx = tb2 + tb2 - tb, wh = v[i], wh2 = prd;
    }
    ruk[700000] = 1;
    int mxx = 700000;
    int mnn = 700000;
    for(int i = 1; i <= n; ++i)
        if(v[i] == wh)
        {
            v[i] = v[n];
            --n;
            break;
        }
    for(int i = 1; i <= n; ++i)
    {
        for(int j = mxx; j >= mnn; --j)
        {
            ruk[j + v[i]] += ruk[j];
            if(ruk[j + v[i]] > mod)
                ruk[j + v[i]] -= mod;
        }
        mxx += v[i];
        for(int j = mnn; j <= mxx; ++j)
        {
            ruk[j - v[i]] += ruk[j];
            if(ruk[j - v[i]] > mod)
                ruk[j - v[i]] -= mod;
        }
        mnn -= v[i];
    }
    int ans = 0;
    while(ruk[ans + 700000])
        ++ans;
    cout << wh << " " << ans << '\n';
    return 0;
}
