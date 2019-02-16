#include<bits/stdc++.h>
using namespace std;
ifstream f("sabin.in");
ofstream g("sabin.out");
int n, k, m, p, q;
struct siruri
{
    string s;
};
siruri v[20002][16], v2[30002];
struct queries
{
    int sz, pi, s;
    int v[16];
    int ans;
};
queries qq[20002];
unordered_map<string, int>mp;
int main()
{
    f >> n >> k >> m >> p >> q;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= k; ++j)
            f >> v[i][j].s;
    for(int i = 1; i <= n; ++i)
    {
        string s;
        for(int j = 0; j < p; ++j)
        {
            for(int z = 1; z <= k; ++z)
                s += v[i][z].s[j];
            mp[s]++;
        }
    }
    for(int i = 1; i <= m; ++i)
        f >> v2[i].s;
    for(int i = 1; i <= q; ++i)
    {
        f >> qq[i].sz;
        for(int j = 1; j <= k; ++j)
            f >> qq[i].v[j];
        string s;
        int aa = 0, bb = 0;
        for(int j = 0; j < qq[i].sz; ++j)
            for(int pp = 1; pp <= k; ++pp)
                s += v2[qq[i].v[pp]].s[j];
        if(qq[i].sz == 0)
            aa = n;
        else
            aa = mp[s];
        if(qq[i].sz < p)
            for(int pp = 1; pp <= k; ++pp)
                s += v2[qq[i].v[pp]].s[qq[i].sz];
        bb = mp[s];
        g << aa - bb << '\n';
    }
    return 0;
}
