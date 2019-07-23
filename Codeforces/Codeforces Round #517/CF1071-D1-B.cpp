/// Rose <3

#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#define mod 1000000007
using namespace std;
int n, k, mxlen;
char a[2002][2002];
int dp[2002][2002];
bool pus[2002][2002];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    // shuffle(permutation.begin(), permutation.end(), rng);
    cin>>n>>k;
    for(int i = 1; i <= n; ++i)
        cin >> (a[i] + 1);
    if(k >= 2*n-1)
    {
        for(int i = 1; i <= 2*n-1; ++i)
            cout << "a";
        return 0;
    }

    if(k == 0)
    {
        deque<pair<int, int> >d;
        d.push_back({1, 1});
        cout << a[1][1];
        while(!d.empty())
        {
            deque<pair<int, int> >d2;
            char mini = 'z' + 1;
            for(int i = 0; i < d.size(); ++i)
            {
                pair<int, int>x;
                x = d[i];
                if(x.first+1 <= n)
                    mini = min(mini, a[x.first+1][x.second]);
                if(x.second+1 <= n)
                    mini = min(mini, a[x.first][x.second + 1]);
            }
            if(mini == 'z' + 1)
                break;
            cout << mini;
            for(int i = 0; i < d.size(); ++i)
            {
                pair<int, int>x;
                x = d[i];
                if(x.first+1 <= n && a[x.first+1][x.second] == mini  && !pus[x.first+1][x.second])
                    d2.push_back({x.first+1, x.second}), pus[x.first+1][x.second] = 1;
                if(x.second+1 <= n && a[x.first][x.second + 1] == mini && !pus[x.first][x.second+1])
                    d2.push_back({x.first, x.second + 1}), pus[x.first][x.second + 1] = 1;
            }
            d.clear();
            d = d2;
        }
        return 0;
    }
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j)
        {
            if(i != 1 || j != 1)
                dp[i][j] = 1000000;
            if(i-1)
                dp[i][j] = min(dp[i][j], dp[i-1][j]);
            if(j-1)
                dp[i][j] = min(dp[i][j], dp[i][j-1]);
            if(a[i][j] != 'a')
                dp[i][j]++;
            if(dp[i][j] <= k)
                mxlen = max(mxlen, i - 1 + j - 1 + 1);
        }
    for(int i = 1; i <= mxlen; ++i)
        cout << "a";
    deque<pair<int, int> >d;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j)
            if(dp[i][j] <= k && (i-1) + (j-1) + 1 == mxlen)
                d.push_back({i, j});
    while(!d.empty())
    {
        deque<pair<int, int> >d2;
        char mini = 'z' + 1;
        for(int i = 0; i < d.size(); ++i)
        {
            pair<int, int>x;
            x = d[i];
            if(x.first+1 <= n)
                mini = min(mini, a[x.first+1][x.second]);
            if(x.second+1 <= n)
                mini = min(mini, a[x.first][x.second + 1]);
        }
        if(mini == 'z' + 1)
            break;
        cout << mini;
        for(int i = 0; i < d.size(); ++i)
        {
            pair<int, int>x;
            x = d[i];
            if(x.first+1 <= n && a[x.first+1][x.second] == mini && !pus[x.first+1][x.second])
                d2.push_back({x.first+1, x.second}), pus[x.first+1][x.second] = 1;
            if(x.second+1 <= n && a[x.first][x.second + 1] == mini && !pus[x.first][x.second+1])
                d2.push_back({x.first, x.second + 1}), pus[x.first][x.second + 1] = 1;
        }
        d.clear();
        d = d2;
    }
    return 0;
}
