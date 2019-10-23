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

bool is[1002];

int n, k, dp[1002], minii, maxii;
int viz[1000002];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;
    int dist = 0;
    vector<int>di;
    for(int i = 1; i <= k; ++i)
    {
        int nr;
        cin >> nr;
        if(i == 1)
            minii = maxii = nr;
        else
        {
            minii = min(minii, nr);
            maxii = max(maxii, nr);
        }
        if(!is[nr])
            ++dist, di.pb(nr);
        is[nr] = 1;
        dp[nr] = 1;
    }
    if(n > maxii || n < minii)
    {
        cout << -1;
        return 0;
    }
    deque<pair<int, int> >d;
    d.pb({0, 0});
    int ct = 0;
    while(!d.empty())
    {
        pair<int, int> x = d[0];
        d.pop_front();
        for(int j = 0; j < dist; ++j)
        {
            int ne_pos = x.fi + di[j];
            if(viz[ne_pos] < x.se + 1)
            {
                if(ne_pos + 2000 >= (x.se + 1) * n && ne_pos - 2000 <= (x.se + 1) * n)
                {
                    viz[ne_pos] = x.se + 1;
                    d.pb({ne_pos, x.se + 1});
                    if(ne_pos == n * (x.se + 1))
                    {
                        cout << x.se + 1;
                        return 0;
                    }
                }
            }
        }
    }
    return 0;
}

