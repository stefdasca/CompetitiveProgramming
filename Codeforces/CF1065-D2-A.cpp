/// the ginger empire has risen

#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#define mod 1000000007
#define fi first
#define se second
using namespace std;
int t;
long long s,a,b,c;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    // shuffle(permutation.begin(), permutation.end(), rng);
    cin>>t;
    for(int i = 1; i <= t; ++i)
    {
        cin >> s >> a >> b >> c;
        long long xx = s / (a*c);
        long long sol = xx * (a+b);
        s %= (a*c);
        sol += s/c;
        cout <<sol << '\n';
    }
    return 0;
}
