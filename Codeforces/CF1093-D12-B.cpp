/// be happy!

#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int t;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    for(int i = 1; i <= t; ++i)
    {
        string s;
        cin >> s;
        sort(s.begin(), s.end());
        if(s[0] == s.back())
        {
            cout << -1 << '\n';
        }
        else
            cout << s << '\n';
    }
    return 0;
}
