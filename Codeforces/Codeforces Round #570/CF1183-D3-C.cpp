#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int q;
long long k, n, a, b;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> q;
    for(; q; --q)
    {
        cin >> k >> n >> a >> b;
        if(k <= n * b)
            cout << -1 << '\n';
        else
        {
            k -= (n * b);
            k--;
            cout << min(n, k / (a - b)) << '\n';
        }
    }
    return 0;
}

