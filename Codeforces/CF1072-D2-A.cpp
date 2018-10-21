#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#define mod 1000000007
using namespace std;
int n,m,k;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    // shuffle(permutation.begin(), permutation.end(), rng);
    cin>>n>>m>>k;
    int ans = 0;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            if(min(min(n-i, m-j), min(i-1, j-1)) % 2 == 0 && min(min(n-i, m-j), min(i-1, j-1)) <= 2*(k-1))
                ++ans;
    cout << ans;
    return 0;
}
