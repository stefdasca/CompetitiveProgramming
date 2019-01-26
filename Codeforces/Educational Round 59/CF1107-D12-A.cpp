#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int t;
string s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    for(int i = 1; i <= t; ++i)
    {
        int n;
        cin >> n;
        cin >> s;
        if(n == 2)
        {
            if(s[0] >= s[1])
            {
                cout << "NO\n";
            }
            else
            {
                cout << "YES\n";
                cout << 2 << '\n';
                cout << s[0] << " ";
                for(int i = 1; i < s.size(); ++i)
                    cout << s[i];
                cout << '\n';
            }
        }
        else
        {
            cout << "YES\n";
            cout << 2 << '\n';
            cout << s[0] << " ";
            for(int i = 1; i < s.size(); ++i)
                cout << s[i];
            cout << '\n';
        }
    }
    return 0;
}

