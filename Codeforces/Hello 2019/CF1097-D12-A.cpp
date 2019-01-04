/// Never do the same mistake twice

#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
string a;
string b, c, d, e, f;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> a;
    cin >> b;
    cin >> c;
    cin >> d;
    cin >> e;
    cin >> f;
    if(a[0] == b[0] || a[0] == c[0] || a[0] == d[0] || a[0] == e[0] || a[0] == f[0])
        cout << "YES";
    else
        if(a[1] == b[1] || a[1] == c[1] || a[1] == d[1] || a[1] == e[1] || a[1] == f[1])
            cout << "YES";
        else
            cout << "NO";
    return 0;
}
