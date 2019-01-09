/// 2222 by 1 february, thx

#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

int n, v[200002];
bool viz[200002];
map<int, int>fi;
map<int, int>la;
long long ans = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 1; i <= n; ++i)
    {
        cin >> v[i];
        if(fi.find(v[i]) == fi.end())
            fi[v[i]] = i;
        la[v[i]] = i;
    }
    for(int i = 1; i <= n; ++i)
        if(!viz[i])
        {
            if(ans == 0)
                ans = 1;
            else
                ans = (ans * 2) % 998244353;
            int ult = la[v[i]];
            for(int j = i; j <= ult; ++j)
                viz[j] = 1, ult = max(ult, la[v[j]]);
        }
    cout << ans;
    return 0;
}
