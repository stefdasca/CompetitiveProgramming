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

// #define fisier

using namespace std;

typedef long long ll;

int t;
int n;
pair<int, int> data[72];

map<pair<int, int>, int> dp[2];

void baga(int poz, int aa, int bb, int val)
{
    if(dp[poz].find({aa, bb}) == dp[poz].end())
        dp[poz][{aa, bb}] = (1<<30);
    dp[poz][{aa, bb}] = min(dp[poz][{aa, bb}], val);
}
int main()
{

    #ifdef fisier
        ifstream f("input.in");
        ofstream g("output.out");
    #endif
    cin >> t;
    for(; t; --t)
    {
        cin >> n;
        int sum = 0;
        for(int i = 1; i <= n; ++i)
            cin >> data[i].fi >> data[i].se, sum += data[i].se;
        sort(data + 1, data + n + 1);
        reverse(data + 1, data + n + 1);
        dp[0].clear();
        dp[1].clear();
        dp[1][{0, 0}] = data[1].fi;
        for(int i = 2; i <= n; ++i)
        {
            dp[(i & 1)].clear();
            for(auto it : dp[((i - 1) & 1)])
            {
                pair<int, int> pi = it.fi;
                int val = dp[((i - 1) & 1)][pi];
                baga((i & 1), pi.fi, pi.se, val);
                int val2 = val + data[i].fi * (pi.fi == 0);
                baga((i & 1), pi.fi + data[i].se, pi.se, val2);
                val2 = val + data[i].fi * (pi.se == 0);
                baga((i & 1), pi.fi, pi.se + data[i].se, val2);
            }
        }
        int ans = (1<<30);
        for(auto it : dp[(n & 1)])
        {
            pair<int, int> pi = it.fi;
            if(pi.fi == 0 || pi.se == 0)
                continue;
            ans = min(ans, it.se * max(pi.fi, max(pi.se, sum - pi.fi - pi.se)));
        }
        cout << ans << '\n';
    }
    return 0;
}
