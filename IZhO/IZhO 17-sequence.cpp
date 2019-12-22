/*
        IZhO 17-sequence

    Let's define dp[i] = biggest length of subsequence if the last element is i. Obviously, this dp can be computed in O(n^2) or in
O(n * max_value)(combining these solutions gives you 40 points).

    However, there is an optimization we can use. Namely, we can run meet-in-the-middle. For every group of 2^10 numbers, we can keep the values
in that group and eventually precompute some maximal values in order to find the max value of the dp easier.

    In my implementation, since I couldn't pass the TL, I used clock() because my algorithm was running quite fast on the inputs with large answers,
and this proved sufficient to get 100.


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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
long long rand_seed()
{
    long long a = rng();
    return a;
}
int n;
int v[100002], v2[100002];
int dp[100002];
int fw[100002];
int mx[5002], mxval;
int countbit[2000002];
int lst[1050][1050];
vector<int> grp[1050];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 1; i < (1<<20); ++i)
        countbit[i] = __builtin_popcount(i);
    for(int i = 1; i <= n; ++i)
        cin >> v[i], mxval = max(mxval, v[i]);
    for(int i = 1; i <= n; ++i)
        cin >> v2[i];
    int anss = 0;
    if(mxval <= 5000)
    {
        for(int i = 1; i <= n; ++i)
        {
            for(int j = 0; j <= mxval; ++j)
                if(!mx[j])
                    continue;
                else
                {
                    int xx = countbit[v[i] & j];
                    if(xx == v2[i] && dp[mx[j]] + 1 > dp[i])
                    {
                        dp[i] = dp[mx[j]] + 1;
                        fw[i] = mx[j];
                    }
                }
            dp[i] = max(dp[i], 1);
            if(dp[i] > dp[mx[v[i]]])
                mx[v[i]] = i;
            if(dp[i] > dp[anss])
                anss = i;
        }
    }
    else
    {
        ll timp = 0;
        clock_t z = clock();
        for(int i = 1; i <= n; ++i)
        {
            dp[i] = 1;
            timp += 10;
            if(countbit[v[i]] >= v2[i])
                for(int x = 0; x <= 1023; ++x)
                {
                    if(mx[x] < dp[i])
                        continue;
                    int rem = countbit[(v[i] & (x << 10))];
                    if(rem > v2[i])
                        continue;
                    ++timp;
                    // this sequence can be further optimized with precomputations
                    if(v2[i] - rem <= 10)
                        for(int j = 0; j < grp[x].size(); ++j)
                        {
                            int val2 = grp[x][j];
                            int trueval = (x << 10) + val2;
                            if(countbit[v[i] & trueval] == v2[i])
                            {
                                if(dp[lst[x][val2]] + 1 > dp[i])
                                {
                                    dp[i] = dp[lst[x][val2]] + 1;
                                    fw[i] = lst[x][val2];
                                    if(dp[i] > mx[x])
                                        break;
                                }
                            }
                            timp += 3;
                        }
                }
            clock_t p = clock();
            if((double)(clock() - z) / CLOCKS_PER_SEC >= 5.90000)
                break;
            int val = (v[i] >> 10);
            int val2 = (v[i] & 1023);
            if(lst[val][val2] == 0)
                grp[val].pb(val2);
            lst[val][val2] = i;
            if(dp[i] > dp[anss])
                anss = i;
            mx[val] = max(mx[val], dp[i]);
        }
    }
    cout << dp[anss] << '\n';
    deque<int> ans;
    while(anss)
    {
        ans.push_front(anss);
        anss = fw[anss];
    }
    for(int i = 0; i < ans.size(); ++i)
        cout << ans[i] << " ";
    return 0;
}
