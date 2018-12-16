/// be happy!

#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int dp[110];
bool viz[110];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    viz[0] = 1;
    for(int i = 0; i <= 100; ++i)
    {
        if(viz[i])
        {
            for(int j = i + 2; j <= i + 7; ++j)
            {
                if(!viz[j])
                    viz[j] = 1, dp[j] = dp[i] + 1;
            }
        }
    }
    int t;
    cin >> t;
    for(int i = 1; i <= t; ++i)
    {
        int nr;
        cin >> nr;
        cout << dp[nr] << '\n';
    }
    return 0;
}
