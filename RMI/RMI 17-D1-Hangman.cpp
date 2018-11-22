#include<bits/stdc++.h>
using namespace std;
int t;
int n, k;
struct siruri
{
    string s;
};
siruri v[30002];
bool gg[30002];
long long base = 1000000007;
long long p100003[1002];
void solvennk()
{
    for(int i = 1; i <= n; ++i)
    {
        for(int j = i+1; j <= n; ++j)
        {
            int cd = 0;
            for(int q = 0; q < k; ++q)
                if(v[i].s[q] != v[j].s[q])
                    cd++;
            if(cd <= 2)
                gg[i] = gg[j] = 1;
        }
    }
}
void solvenkk()
{
    if(k <= 2)
    {
        for(int i = 1; i <= n; ++i)
            gg[i] = 1;
        return;
    }
    unordered_map<long long, int>mp;
    long long anss[30002];
    for(int i = 1; i <= n; ++i)
    {
        long long hsh = 0;
        for(int j = 0; j < k; ++j)
            hsh = (hsh * base + (v[i].s[j] - 'a'));
        anss[i] = hsh;
        mp[hsh]++;
    }
    /// check identical strings
    for(int i = 1; i <= n; ++i)
    {
        long long hsh = anss[i];
        if(mp[hsh] >= 2)
            gg[i] = 1;
    }
    /// check strings different by 1 letter
    for(int i = 0; i < k; ++i)
    {
        mp.clear();
        for(int r = 1; r <= n; ++r)
        {
            long long hsh = anss[r] - p100003[k - i - 1] * (v[r].s[i] - 'a');
            mp[hsh]++;
        }
        for(int r = 1; r <= n; ++r)
        {
            long long hsh = anss[r] - p100003[k - i - 1] * (v[r].s[i] - 'a');
            if(mp[hsh] >= 2)
                gg[r] = 1;
        }
     }
    /// check strings different by 2 letters
    for(int i = 0; i < k; ++i)
        for(int j = i + 1; j < k; ++j)
        {
            mp.clear();
            for(int r = 1; r <= n; ++r)
            {
                long long hsh = anss[r] - p100003[k - i - 1] * (v[r].s[i] - 'a');
                hsh = hsh - p100003[k - j - 1] * (v[r].s[j] - 'a');
                mp[hsh]++;
            }
            for(int r = 1; r <= n; ++r)
            {
                long long hsh = anss[r] - p100003[k - i - 1] * (v[r].s[i] - 'a');
                hsh = hsh - p100003[k - j - 1] * (v[r].s[j] - 'a');
                if(mp[hsh] >= 2)
                    gg[r] = 1;
            }
        }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    p100003[0] = 1;
    for(int i = 1; i <= 1000; ++i)
        p100003[i] = (p100003[i-1] * base);
    cin >> t;
    for(; t; --t)
    {
        cin >> n >> k;
        memset(gg, 0, sizeof(gg));
        for(int i = 1; i <= n; ++i)
            cin >> v[i].s;
        if(n * n * k <= n * k * k)
            solvennk();
        else
            solvenkk();
        for(int i = 1; i <= n; ++i)
            cout << gg[i];
        cout << '\n';
    }
    return 0;
}

