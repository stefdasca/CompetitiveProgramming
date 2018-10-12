#include<bits/stdc++.h>
using namespace std;
ifstream f("incurcatura.in");
ofstream g("incurcatura.out");
int p;
int n, a, b;
map<int, int>mp[100002];
map<int, int> ::iterator it;
int mod[100002];
int main()
{
    f >> p;
    f >> n;
    for(int i = 1; i <= n; ++i)
    {
        int x;
        f >> x;
        for(int j = 1; j <= x; ++j)
        {
            int nr;
            f >> nr;
            mp[i][nr] = 1;
        }
    }
    for(int i = 1; i <= n; ++i)
    {
        for(it = mp[i].begin(); it != mp[i].end(); ++it)
        {
            int q = it->first;
            if(!mp[q][i])
                mod[i]++, mod[q]++;
        }
    }
    int mx = 0;
    for(int i = 1; i <= n; ++i)
        if(mod[i] > mod[mx])
            mx = i;
    a = mx;
    if(p == 1)
    {
        g << a;
        return 0;
    }
    for(int i = 1; i <= n; ++i)
    {
        for(it = mp[i].begin(); it != mp[i].end(); ++it)
        {
            int q = it->first;
            if(!mp[q][i] && (q == mx || i == mx))
                mod[i]--, mod[q]--;
        }
    }
    for(int i = 1; i <= n; ++i)
        if(mod[i] > mod[mx])
            mx = i;
    b = mx;
    if(a > b)
        g << b << " " << a;
    else
        g << a << " " << b;
    return 0;
}
