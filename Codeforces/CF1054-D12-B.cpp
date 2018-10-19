#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#define mod 1000000007
#define fi first
#define se second
using namespace std;
int n;
int v[100002];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    // shuffle(permutation.begin(), permutation.end(), rng);
    cin>>n;
    for(int i = 1; i <= n; ++i)
        cin >> v[i];
    if(v[1] != 0)
    {
        cout << 1;
        return 0;
    }
    int mn = 0;
    for(int i = 2; i <= n; ++i)
    {
        if(v[i] <= mn + 1)
            mn = max(mn, v[i]);
        else
        {
            cout << i;
            return 0;
        }
    }
    cout << -1;
    return 0;
}
