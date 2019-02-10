#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int x, y, z;
int a, b, c;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> x >> y >> z;
    cin >> a >> b >> c;
    if(a < x)
    {
        cout << "NO";
        return 0;
    }
    a -= x;
    if(a + b < y)
    {
        cout << "NO";
        return 0;
    }
    int sum = a + b + c - y;
    if(sum >= z)
    {
        cout << "YES";
    }
    else
        cout << "NO";
    return 0;
}

