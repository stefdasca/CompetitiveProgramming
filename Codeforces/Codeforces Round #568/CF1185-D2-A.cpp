#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
long long v[5], x;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> v[1] >> v[2] >> v[3] >> x;
    sort(v+1, v+4);
    int ans = max(0LL, x - (v[2] - v[1])) + max(0LL, x - (v[3] - v[2]));
    cout << ans;
    return 0;
}

