#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while(1)
    {
        string s;
        cin >> s;
        if(s[0] == 'e')
            return 0;
        if(s[0] == 'm')
            return 0;
        int st = 0;
        int p = -1;
        for(int i = 0; i <= 29; ++i)
        {
            cout << "? " << (1<<i) << " " << (1<<(i+1)) << endl;
            char q;
            cin >> q;
            if(q == 'x')
            {
                p = i;
                st = (1<<i);
                break;
            }
        }
        if(p == 0)
        {
            cout << "? " << 2 << " " << 3 << endl;
            char q;
            cin >> q;
            if(q == 'x')
                cout << "! " << 1 << endl;
            else
                cout << "! " << 2 << endl;
            continue;
        }
        int x = st;
        int smm = -1;
        for(int i = p - 1; i >= 0; --i)
        {
            cout << "? " << x << " " << x + (1<<i) << endl;
            char q;
            cin >> q;
            if(q == 'y')
                x += (1<<i);
        }
        cout << "! " << x + 1 << endl;
    }
    return 0;
}
