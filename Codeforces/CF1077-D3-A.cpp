/// Never do the same mistake twice

#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int t;
long long a, b, k;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    for(int i = 1; i <= t; ++i)
    {
        cin >> a >> b >> k;
        cout << a * (k/2 + k%2) - b * (k/2) << '\n';;
    }
    return 0;
}

