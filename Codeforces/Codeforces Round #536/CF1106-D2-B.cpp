#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int n, m;
long long nr[100002], cost[100002], ord[100002];
bool cmp(int a, int b)
{
    if(cost[a] == cost[b])
        return a < b;
    return cost[a] < cost[b];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i = 1; i <= n; ++i)
        cin >> nr[i];
    for(int i = 1; i <= n; ++i)
        cin >> cost[i];
    for(int i = 1; i <= n; ++i)
        ord[i] = i;
    sort(ord + 1, ord + n + 1, cmp);
    int pz = 1;
    for(int i = 1; i <= m; ++i)
    {
        while(pz <= n && nr[ord[pz]] == 0)
            ++pz;
        long long tip, cat;
        cin >> tip >> cat;
        long long cc = 0;
        cc += 1LL * min(cat, nr[tip]) * cost[tip];
        int mini = min(cat, nr[tip]);
        cat -= mini;
        nr[tip] -= mini;
        while(cat)
        {
            while(pz <= n && nr[ord[pz]] == 0)
                pz++;
            if(pz > n)
                break;
            mini = min(cat, nr[ord[pz]]);
            cat -= mini;
            nr[ord[pz]] -= mini;
            cc += 1LL * mini * cost[ord[pz]];
        }
        if(cat)
            cout << 0 << '\n';
        else
            cout << cc << '\n';
    }
    return 0;
}

