#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
long long a, b, c;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> a >> b >> c;
    long long len = 2 * c;
    len = len + 1LL * min(a, b) * 2;
    long long x = min(a, b);
    a -= x;
    b -= x;
    if(a || b)
        ++len;
    cout << len;
    return 0;
}

