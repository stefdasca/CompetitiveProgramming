#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#define mod 1000000007
#define fi first
#define se second
using namespace std;
int n, l, a;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    // shuffle(permutation.begin(), permutation.end(), rng);
    cin>>n>>l>>a;
    int sol = 0;
    int lst = 0;
    for(int i = 1; i <= n; ++i)
    {
        int aa, b;
        cin >> aa >> b;
        sol += (aa-lst) / a;
        lst = aa + b;
    }
    sol += (l - lst) / a;
    cout << sol;
    return 0;
}
