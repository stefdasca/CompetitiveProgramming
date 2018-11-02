#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#define mod 1000000007
using namespace std;
int n;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    // shuffle(permutation.begin(), permutation.end(), rng);
    cin>>n;
    for(int i = 1; i <= 4; ++i)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        if(a + c <= n || a + d <= n)
        {
            int x1 = a;
            int x2 = n - a;
            cout << i << " " << x1 << " " << x2 << '\n';
            return 0;
        }
        if(b + c <= n || b + d <= n)
        {
            int x1 = b;
            int x2 = n - b;
            cout << i << " " << x1 << " " << x2 << '\n';
            return 0;
        }
    }
    cout << -1;
    return 0;
}
