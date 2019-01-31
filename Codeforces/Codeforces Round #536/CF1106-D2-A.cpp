#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int n;
char a[510][510];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> (a[i] + 1);
    long long ans = 0;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j)
        {
            if(a[i][j] != 'X')
                continue;
            if(a[i - 1][j - 1] == 'X' && a[i+1][j - 1] == 'X' && a[i-1][j+1] == 'X' && a[i+1][j+1] == 'X')
                ++ans;
        }
    cout << ans;
    return 0;
}

