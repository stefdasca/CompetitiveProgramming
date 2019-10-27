/// the ginger empire has risen

#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#define mod 1000000007
#define fi first
#define se second
using namespace std;
long long a, b;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    // shuffle(permutation.begin(), permutation.end(), rng);
    cin >> a >> b;
    if(b == 0)
    {
        cout << a << " " << a << '\n';
        return 0;
    }
    long long nec = (a/2 + a%2);
    int sol = a;
    for(long long i = 1; i <= b; ++i)
    {
        if(sol >= 2)
            sol -= 2;
        else
            --sol;
        if(sol == 0)
            break;
    }
    cout << sol << " ";
    long long gauss = 1;
    while(gauss * (gauss-1) / 2 < b)
        ++gauss;
    cout << max(0LL, a - gauss);
    return 0;
}
