/// 2222 by 1 february, thx

#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int n, v[1002];
bool gg[1002];
int cost[1002];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> v[i];
    int mini = (1<<30);
    for(int i = 1; i <= 1000; ++i)
    {
        int c = 0;
        for(int j = 1; j <= n; ++j)
            c += min(abs(v[j] - i), min(abs(v[j] - (i - 1)), abs(v[j] - (i + 1))));
        cost[i] = c;
        mini = min(mini, c);
    }
    for(int i = 1; i <= 1000; ++i)
        if(cost[i] == mini)
        {
            cout << i << " " << mini;
            return 0;
        }
    return 0;
}


