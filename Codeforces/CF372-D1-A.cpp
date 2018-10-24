#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#define mod 1000000007
using namespace std;
int n, v[500002];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    // shuffle(permutation.begin(), permutation.end(), rng);
    cin>>n;
    for(int i = 1; i <= n; ++i)
        cin >> v[i];
    sort(v+1, v+n+1);
    int sol = n;
    int jj = n/2 + n%2;
    for(int i = 1; i <= n/2; ++i)
    {
        while(jj <= n && v[i] + v[i] > v[jj])
            ++jj;
        if(jj > n)
            break;
        ++jj;
        --sol;
    }
    cout << sol;
    return 0;
}
