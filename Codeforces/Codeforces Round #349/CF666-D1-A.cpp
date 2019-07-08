#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

typedef long long ll;

string s;
map<string, int>mp;
bool can2[10002];
bool can3[10002];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> s;
    if(s.size() >= 2)
        can2[s.size() - 2] = 1;
    if(s.size() >= 3)
        can3[s.size() - 3] = 1;
    for(int i = s.size() - 4; i >= 0; --i)
    {
        if(can3[i+2])
            can2[i] = 1;
        else
        {
            if(can2[i+2])
            {
                string ss, s2;
                ss += s[i];
                ss += s[i+1];
                s2 += s[i+2];
                s2 += s[i+3];
                if(ss != s2)
                    can2[i] = 1;
            }
        }
        if(can2[i+3])
            can3[i] = 1;
        else
        {
            if(can3[i+3])
            {
                string ss, s2;
                ss += s[i];
                ss += s[i+1];
                ss += s[i+2];
                s2 += s[i+3];
                s2 += s[i+4];
                s2 += s[i+5];
                if(ss != s2)
                    can3[i] = 1;
            }
        }
    }
    for(int i = 5; i + 1 < s.size(); ++i)
    {
        string ss;
        ss += s[i];
        ss += s[i+1];
        if(can2[i])
            mp[ss] = 1;
        if(i + 2 == s.size())
            continue;
        ss += s[i+2];
        if(can3[i])
            mp[ss] = 1;
    }
    cout << mp.size() << '\n';
    for(map<string, int> ::iterator it = mp.begin(); it != mp.end(); ++it)
        cout << it -> first << '\n';
    return 0;
}

