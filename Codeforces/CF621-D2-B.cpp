#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#define mod 1000000007
using namespace std;
int n;
bool is[1002][1002];
long long sol = 0;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    // shuffle(permutation.begin(), permutation.end(), rng);
    cin>>n;
    for(int i = 1; i <= n; ++i)
    {
        int x, y;
        cin >> x >> y;
        is[x][y] = 1;
    }
    for(int i = 1; i <= 1000; ++i)
    {
        int nr = 0;
        for(int j = 1, k = i; j <= 1000 && k <= 1000; ++j, ++k)
            nr += is[j][k];
        sol = sol + 1LL * nr * (nr-1)/2;
    }
    for(int i = 2; i <= 1000; ++i)
    {
        int nr = 0;
        for(int j = i, k = 1; j <= 1000 && k <= 1000; ++j, ++k)
            nr += is[j][k];
        sol = sol + 1LL * nr * (nr-1)/2;
    }
    for(int i = 1; i <= 1000; ++i)
    {
        int nr = 0;
        for(int j = 1, k = i; j <= 1000 && k; ++j, --k)
            nr += is[j][k];
        sol = sol + 1LL * nr * (nr-1)/2;
    }
    for(int i = 2; i <= 1000; ++i)
    {
        int nr = 0;
        for(int j = i, k = 1000; j <= 1000 && k; ++j, --k)
            nr += is[j][k];
        sol = sol + 1LL * nr * (nr-1)/2;
    }
    cout << sol;
    return 0;
}
