#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#define mod 1000000007
using namespace std;
long long k, b, n, t;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    // shuffle(permutation.begin(), permutation.end(), rng);
    cin >> k >> b >> n >> t;
    long long nr = 1;
    for(int i = 1; i <= n; ++i)
    {
        nr = nr * k + b;
        if(nr >= t)
        {
            if(nr == t)
                cout << n - i;
            else
                cout << n - i + 1;
            return 0;
        }
    }
    cout << 0;
    return 0;
}
