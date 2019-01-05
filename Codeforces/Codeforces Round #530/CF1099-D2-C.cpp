#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
string s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> s;
    int sn = 0, cd = 0;
    for(int j = 0; j < s.size(); ++j)
        if(s[j] == '*')
            ++sn;
        else
            if(s[j] == '?')
                ++cd;
    int k;
    int TL = s.size() - 2 * sn - 2 * cd;
    cin >> k;
    if(TL > k)
    {
        cout << "Impossible";
        return 0;
    }
    if(sn)
    {
        for(int j = 0; j < s.size(); ++j)
        {
            if(s[j] == '?' || s[j] == '*')
                continue;
            if(j + 1 < s.size() && s[j+1] == '?')
                continue;
            else
                if(j + 1 < s.size() && s[j+1] == '*')
                    while(TL < k)
                        cout << s[j], ++TL;
                else
                    cout << s[j];
        }
    }
    else
    {
        if(TL + cd < k)
        {
            cout << "Impossible";
            return 0;
        }
        for(int j = 0; j < s.size(); ++j)
        {
            if(s[j] == '?' || s[j] == '*')
                continue;
            if(j + 1 < s.size() && s[j+1] == '?')
                if(TL < k)
                    cout << s[j], ++TL;
                else
                    continue;
            else
                cout << s[j];
        }
    }
    return 0;
}
