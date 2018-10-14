#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#define mod 1000000007
#define fi first
#define se second
using namespace std;
int v[5];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    // shuffle(permutation.begin(), permutation.end(), rng);
    cin >> v[1] >> v[2] >> v[3];
    sort(v+1, v+4);
    int sol = 0;
    while(1)
    {
        if(v[3] >= v[2] + v[1])
            ++sol, ++v[1];
        else
            break;
        sort(v+1, v+4);
    }
    cout << sol;
    return 0;
}
