#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#define fi first
#define se second
#define pb push_back

using namespace std;

typedef long long ll;

ll n, l, r;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> l >> r;
    cout << 1LL * ((1<<l) - 1 + (n - l)) << " " << 1LL * ((1<<r) - 1 + (n - r) * (1<<(r-1)));
    return 0;
}
