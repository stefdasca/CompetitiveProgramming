#include<bits/stdc++.h>
using namespace std;
int n, v[200002], dp[200002][7], where[200007][7];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> v[i];
    for(int i = 1; i <= 5; ++i)
        dp[1][i] = 1;
    for(int i = 1; i < n; ++i)
    {
        for(int j = 1; j <= 5; ++j)
        {
            if(!dp[i][j])
                continue;
            if(v[i] > v[i+1])
                for(int k = 1; k < j; ++k)
                    dp[i+1][k] = 1, where[i+1][k] = j;
            if(v[i] < v[i+1])
                for(int k = j+1; k <= 5; ++k)
                    dp[i+1][k] = 1, where[i+1][k] = j;
            if(v[i] == v[i+1])
                for(int k = 1; k <= 5; ++k)
                    if(j != k)
                        dp[i+1][k] = 1, where[i+1][k] = j;
        }
    }
    for(int i = 1; i <= 5; ++i)
        if(dp[n][i])
        {
            vector<int>v;
            int pa = n;
            int pb = i;
            while(pa)
            {
                v.push_back(pb);
                pb = where[pa][pb];
                --pa;
            }
            reverse(v.begin(), v.end());
            for(int j = 0; j < v.size(); ++j)
                cout << v[j] << " ";
            return 0;
        }

    cout << -1;
    return 0;
}
