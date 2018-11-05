#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
long long n, x, y;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    cin >> x >> y;
    long long xa = x + y - 2;
    long long xb = (n - x) + (n - y);
    if(xa <= xb)
        cout << "White";
    else
        cout << "Black";
    return 0;
}
