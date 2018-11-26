#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
string s, t;
int nr0, nr1;
long long base = 100003, mod = 1000000007;
long long hsh[2000002], pw[2000002];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> s;
    cin >> t;
    for(int i = 0; i < s.size(); ++i)
        if(s[i] == '0')
            ++nr0;
        else
            ++nr1;
    pw[0] = 1;
    for(int i = 1; i <= t.size(); ++i)
        pw[i] = (pw[i-1] * base) % mod;
    for(int i = 0; i < t.size(); ++i)
    {
        if(i > 0)
            hsh[i] = hsh[i-1] * base;
        hsh[i] = (hsh[i] + (t[i] - 'a' + 1)) % mod;
    }
    vector<pair<int, int> >pos;
    for(int i = 1; i * nr0 < t.size(); ++i)
    {
        int diff = t.size() - i * nr0;
        if(diff % nr1 == 0)
            pos.push_back({i, diff / nr1});
    }
    int sol = 0;
    for(int i = 0; i < pos.size(); ++i)
    {
        long long hsha = 0, hshb = 0;
        bool seen1 = 0, seen2 = 0;
        int ax = 0;
        bool rau = 0;
        for(int j = 0; j < s.size(); ++j)
        {
            if(s[j] == '0')
            {
                if(!seen1)
                {
                    seen1 = 1;
                    hsha = hsh[ax + pos[i].first - 1];
                    if(ax > 0)
                        hsha = hsha - hsh[ax-1] * pw[pos[i].first] + mod * pw[pos[i].first];
                    hsha %= mod;
                }
                else
                {
                    long long predd = hsh[ax + pos[i].first - 1];
                    if(ax > 0)
                        predd = predd - hsh[ax-1] * pw[pos[i].first] + mod * pw[pos[i].first];
                    predd %= mod;
                    if(predd != hsha)
                    {
                        rau = 1;
                        break;
                    }
                }
                ax += pos[i].first;
            }
            else
            {
                if(!seen2)
                {
                    seen2 = 1;
                    hshb = hsh[ax + pos[i].second - 1];
                    if(ax > 0)
                        hshb = hshb - hsh[ax-1] * pw[pos[i].second] + mod * pw[pos[i].second];
                    hshb %= mod;
                }
                else
                {
                    long long predd = hsh[ax + pos[i].second - 1];
                    if(ax > 0)
                        predd = predd - hsh[ax-1] * pw[pos[i].second] + mod * pw[pos[i].second];
                    predd %= mod;
                    if(predd != hshb)
                    {
                        rau = 1;
                        break;
                    }
                }
                ax += pos[i].second;
            }
        }
        if(!rau && hsha != hshb)
            ++sol;
    }
    cout << sol;
    return 0;
}
