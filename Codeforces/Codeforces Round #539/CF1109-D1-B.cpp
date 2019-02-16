#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
long long rand_seed()
{
	long long a = rng();
    return a;
}
string s;
int frq[28];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> s;
    for(int i = 0; i < s.size(); ++i)
        frq[s[i] - 'a']++;
    for(int i = 0; i <= 25; ++i)
        if(frq[i] >= s.size() - 1)
        {
            cout << "Impossible";
            return 0;
        }
    if(s.size() % 2 == 0)
    {
        for(int i = 0; i < s.size(); ++i)
        {
            string p;
            for(int j = i+1; j < s.size(); ++j)
                p += s[j];
            for(int j = 0; j <= i; ++j)
                p += s[j];
            if(p != s)
            {
                bool ok = 1;
                for(int j = 0; j < p.size(); ++j)
                    if(p[j] != p[p.size() - j - 1])
                        ok = 0;
                if(ok)
                {
                    cout << 1;
                    return 0;
                }
            }
        }
    }
    int mini = 10000;
    for(int coe = s.size() / 2 - 1; coe >= 0; --coe)
    {
        int ans = 0;
        string x;
        for(int i = 0; i < s.size() / 2 - coe; ++i)
            x += s[i];
        string y;
        for(int i = s.size() / 2 + coe + s.size() % 2; i < s.size(); ++i)
            y += s[i];
        if(x == y)
            continue;
        if(coe != 0 || s.size() % 2 == 1)
            ans += 2;
        else
            ans++;
        mini = min(mini, ans);
    }
    cout << mini;
    return 0;
}
