#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int n;
string a, b;
int lt;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(; n; --n)
    {
        cin >> a;
        cin >> b;
        int x = 0;
        int y = 0;
        bool rau = 0;
        lt = -1;
        while(x < a.size() && y < b.size())
        {
            if(x < a.size() && y < b.size() && a[x] != b[y])
            {
                rau = 1;
                break;
            }
            int aa = x;
            int bb = y;
            while(aa < a.size() && a[aa] == a[x])
                ++aa;
            while(bb < b.size() && b[bb] == b[y])
                ++bb;
            if(aa - x > bb - y)
            {
                rau = 1;
                break;
            }
            x = aa;
            y = bb;
        }
        if(x < a.size() || y < b.size())
            rau = 1;
        if(rau == 1)
            cout << "NO\n";
        else
            cout << "YES\n";
    }
    return 0;
}

