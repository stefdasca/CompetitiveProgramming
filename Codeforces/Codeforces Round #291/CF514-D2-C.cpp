#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
long long n, m;
map<long long, int>mp[600002];
long long p31[600002];
long long mod = 1000000000000000003LL;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i = 1; i <= n; ++i)
    {
        string s;
        cin >> s;
        long long hsh = 0;
        for(int j = 0; j < s.size(); ++j)
        {
            hsh = hsh * 5 + (s[j] - 'a' + 1);
            hsh %= mod;
        }
        mp[s.size()][hsh] = 1;
    }
    p31[0] = 1;
    for(int i = 1; i <= 600000; ++i)
        p31[i] = (p31[i-1] * 5) % mod;
    for(int i = 1; i <= m; ++i)
    {
        string s;
        cin >> s;
        long long hsh = 0;
        for(int j = 0; j < s.size(); ++j)
        {
            hsh = hsh * 5 + (s[j] - 'a' + 1);
            hsh %= mod;
        }
        bool gg = 0;
        for(int j = 0; j < s.size(); ++j)
        {
            int vv = (s[j] - 'a') + 1;
            for(int k = 1; k <= 3; ++k)
            {
                if(vv == k)
                    continue;
                long long old_hsh = hsh;
                old_hsh += (k - vv) * p31[s.size() - j - 1];
                while(old_hsh < 0)
                    old_hsh += mod;
                old_hsh %= mod;
                if(mp[s.size()][old_hsh])
                    gg = 1;
            }
        }
        if(gg)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}
