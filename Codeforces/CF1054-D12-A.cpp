#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#define mod 1000000007
#define fi first
#define se second
using namespace std;
int x, y, z, t1, t2, t3;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    // shuffle(permutation.begin(), permutation.end(), rng);
    cin>>x>>y>>z>>t1>>t2>>t3;
    int tscari = abs(x-y) * t1;
    int tlift = abs(x-z) * t2 + 2 * t3 + abs(x-y) * t2 + t3;
    if(tlift <= tscari)
        cout << "YES";
    else
        cout << "NO";
    return 0;
}
