/// Will it all end?

#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int n;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    long long ans = 0;
    for(int i = 2; i <= n; ++i)
        for(int j = i * 2; j <= n; j += i)
            ans += (j/i) * 4;
    cout << ans;
    return 0;
}
