/**    Rose's very long and elaborated template    **/


#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#define mod 1000000007
#define fi first
#define se second
using namespace std;
int n;
long long a, b;
bool prim(long long x)
{
    if(x == 1)
        return 1;
    for(long long i = 2; i * i <= x; ++i)
        if(x % i == 0)
            return 0;
    return 1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    // shuffle(permutation.begin(), permutation.end(), rng);
    cin>>n;
    for(int i = 1; i <= n; ++i)
    {
        cin >> a >> b;
        long long aa = (a-b);
        long long aa2 = (b+a);
        if(aa != 1 && aa2 != 1)
        {
            cout << "NO" << '\n';
            continue;
        }
        if(!prim(aa) || !prim(aa2))
        {
            cout << "NO" << '\n';
            continue;
        }
        cout << "YES\n";
    }
    return 0;
}
