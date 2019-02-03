#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
string s, t;
bool v[30];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    v[0] = v[4] = v[('i' - 'a')] = 1;
    v[('o' - 'a')] = 1;
    v[('u' - 'a')] = 1;
    cin >> s;
    cin >> t;
    if(s.size() != t.size())
    {
        cout << "No";
        return 0;
    }
    for(int i = 0; i < s.size(); ++i)
    {
        int a = s[i] - 'a';
        int b = t[i] - 'a';
        if(v[a] != v[b])
        {
            cout << "No";
            return 0;
        }
    }
    cout << "Yes";
    return 0;
}

