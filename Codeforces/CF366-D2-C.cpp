#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#define mod 1000000007
using namespace std;
int n, k, v[102], v2[102];
bool dp[10002][10002];
bool viz[10002];
int mini[10002];
int maxi[10002];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    // shuffle(permutation.begin(), permutation.end(), rng);
    cin>>n>>k;
    int sum = 0;
    for(int i = 1; i <= n; ++i)
        cin >> v[i], sum += v[i];
    for(int i = 1; i <= n; ++i)
        cin >> v2[i];
    int mxx = sum / k;
    dp[0][0] = 1;
    viz[0] = 1;
    int sol = -1;
    for(int i = 1; i <= n; ++i)
    {
        for(int j = sum; j >= 0; --j)
        {
            if(!viz[j])
                continue;
            for(int kk = mini[j]; kk <= maxi[j]; ++kk)
                if(dp[j][kk])
                {
                    dp[j + v[i]][kk + v2[i]] = 1;
                    if((kk + v2[i]) <= mxx)
                    {
                        if(!viz[j + v[i]])
                            mini[j+v[i]] = maxi[j+v[i]] = kk + v2[i];
                        viz[j + v[i]] = 1;
                        mini[j+v[i]] = min(mini[j+v[i]], kk + v2[i]);
                        maxi[j+v[i]] = max(maxi[j+v[i]], kk + v2[i]);
                        if((kk + v2[i]) * k == (j + v[i]))
                            sol = max(sol, j + v[i]);
                    }
                }
        }
    }
    cout << sol;
    return 0;
}
