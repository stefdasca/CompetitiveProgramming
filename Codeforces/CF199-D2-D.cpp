#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#define mod 1000000007
using namespace std;
int n, k;
char a[3][100002];
bool viz[3][100002];
int dp[3][100002];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    // shuffle(permutation.begin(), permutation.end(), rng);
    cin >> n >> k;
    for(int i = 1; i <= 2; ++i)
        cin >> (a[i] + 1);
    viz[1][1] = 1;
    deque<pair<int, int> >d;
    d.push_back({1, 1});
    while(!d.empty())
    {
        pair<int, int>Rose = d[0];
        d.pop_front();
        if(Rose.second <= dp[Rose.first][Rose.second])
            continue;
        if(Rose.second+1 > n)
        {
            cout << "YES";
            return 0;
        }
        if(a[Rose.first][Rose.second+1] != 'X')
        {
            if(!viz[Rose.first][Rose.second + 1])
            {
                viz[Rose.first][Rose.second + 1] = 1;
                dp[Rose.first][Rose.second + 1] = dp[Rose.first][Rose.second] + 1;
                d.push_back({Rose.first, Rose.second + 1});
            }
        }
        if(a[Rose.first][Rose.second-1] != 'X')
        {
            if(!viz[Rose.first][Rose.second - 1])
            {
                viz[Rose.first][Rose.second - 1] = 1;
                dp[Rose.first][Rose.second - 1] = dp[Rose.first][Rose.second] + 1;
                d.push_back({Rose.first, Rose.second - 1});
            }
        }
        if(Rose.second+k > n)
        {
            cout << "YES";
            return 0;
        }
        if(a[3 - Rose.first][Rose.second+k] != 'X')
        {
            if(!viz[3 - Rose.first][Rose.second + k])
            {
                viz[3 - Rose.first][Rose.second + k] = 1;
                dp[3 - Rose.first][Rose.second + k] = dp[Rose.first][Rose.second] + 1;
                d.push_back({3 - Rose.first, Rose.second + k});
            }
        }
    }
    cout << "NO";
    return 0;
}
