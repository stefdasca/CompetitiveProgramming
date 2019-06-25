#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int t;
struct segmente
{
    int poz, tip, pi;
};
segmente v[200002];
int care[100002];
bool cmp(segmente a, segmente b)
{
    return a.poz < b.poz;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    for(; t; --t)
    {
        int n;
        cin >> n;
        int ct = 0;
        for(int i = 1; i <= n; ++i)
        {
            int a, b;
            cin >> a >> b;
            v[++ct] = {a, 0, i};
            v[++ct] = {b, 1, i};
        }
        sort(v+1, v+ct+1, cmp);
        int sc = 0;
        bool gg = 0;
        for(int i = 1; i <= ct;)
        {
            if(v[i].poz > v[i-1].poz)
            {
                int j = i;
                while(v[j].poz == v[i].poz)
                {
                    if(v[j].tip == 0)
                        care[v[j].pi] = 1, ++sc;
                    else
                        --sc;
                    ++j;
                }
                if(sc == 0 && j != ct + 1)
                {
                    gg = 1;
                    break;
                }
                i = j;
            }
        }
        if(gg == 0)
        {
            cout << -1 << '\n';
            for(int i = 1; i <= n; ++i)
                care[i] = 0;
            continue;
        }
        for(int i = 1; i <= n; ++i)
            if(care[i] == 1)
                cout << 1 << " ";
            else
                cout << 2 << " ";
        cout << '\n';
        for(int i = 1; i <= n; ++i)
            care[i] = 0;
    }
    return 0;
}
