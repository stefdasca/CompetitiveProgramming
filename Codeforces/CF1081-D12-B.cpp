/// be happy!

#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int n;
struct str
{
    int pi, nr;
};
str v[200002];
bool cmp(str a, str b)
{
    return a.nr < b.nr;
}
int ans[200002];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> v[i].nr, v[i].pi = i;
    sort(v+1, v+n+1, cmp);
    int hatt = 0;
    hatt = 1;
    for(int i = 1; i <= n; ++i)
    {
        int p2 = i;
        int am = n - v[i].nr;
        while(p2 - i < am && p2 <= n && v[p2].nr == v[i].nr)
            ++p2;
        if(p2 - i < am)
        {
            cout << "Impossible";
            return 0;
        }
        for(int j = i; j < p2; ++j)
            ans[v[j].pi] = hatt;
        ++hatt;
        i = p2 - 1;
    }
    cout << "Possible\n";
    for(int i = 1; i <= n; ++i)
        cout << ans[i] << " ";
    return 0;
}

