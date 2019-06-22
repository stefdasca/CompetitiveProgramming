#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int n, ans;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    ans = 1;
    for(int i = 2; i <= n; i++)
        ans += (i-1) * 4;
    cout << ans;
    return 0;
}

