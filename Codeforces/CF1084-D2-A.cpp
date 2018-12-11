/// Goodbye until the day we meet again

#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int n, v[102];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> v[i];
    int mini = (1<<30);
    for(int i = 1; i <= n; ++i)
    {
        int pos = 0;
        for(int j = 1; j <= n; ++j)
        {
            pos += abs(i - j) * v[j];
            pos += (j - 1) * v[j];
            pos += (i - 1) * v[j];
            pos += (i - 1) * v[j];
            pos += (j - 1) * v[j];
            pos += abs(i - j) * v[j];
        }
        mini = min(mini, pos);
    }
    cout << mini;
    return 0;
}
