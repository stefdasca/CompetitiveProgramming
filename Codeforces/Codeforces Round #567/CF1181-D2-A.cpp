#include<bits/stdc++.h>
#pragma gcc optimize("O3")
using namespace std;
long long a, b, c;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> a >> b >> c;
    long long ans = a/c + b/c;
    a %= c;
    b %= c;
    if(a + b >= c)
    {
        if(a <= b)
            cout << ans + 1 << " " << c - b;
        else
            cout << ans + 1 << " " << c - a;
    }
    else
        cout << ans << " " << 0;
    return 0;
}
