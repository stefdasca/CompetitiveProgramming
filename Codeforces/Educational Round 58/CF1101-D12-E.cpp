#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int q;
int maxmini = 0;
int maxmaxi = 0;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> q;
    for(int i = 1; i <= q; ++i)
    {
        char c;
        int a, b;
        cin >> c >> a >> b;
        if(a > b)
            swap(a, b);
        if(c == '+')
        {
            maxmini = max(maxmini, a);
            maxmaxi = max(maxmaxi, b);
        }
        else
            if(maxmini > a || maxmaxi > b)
                cout << "NO\n";
            else
                cout << "YES\n";
    }
    return 0;
}
