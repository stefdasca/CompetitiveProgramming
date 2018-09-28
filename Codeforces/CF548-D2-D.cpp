#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#define mod 1000000007
#define fi first
#define se second
using namespace std;
int n;
int v[200002];
deque<int>d;
int st[200002];
int dr[200002];
int mx[200002];
int prmx[200002];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    // shuffle(permutation.begin(), permutation.end(), rng);
    cin>>n;
    for(int i = 1; i <= n; ++i)
        cin >> v[i];
    for(int i = 1; i <= n; ++i)
    {
        while(!d.empty() && v[i] <= v[d.back()])
            d.pop_back();
        if(!d.size())
            st[i] = 0;
        else
            st[i] = d.back();
        d.push_back(i);
    }
    d.clear();
    for(int i = n; i >= 1; --i)
    {
        while(!d.empty() && v[i] <= v[d.back()])
            d.pop_back();
        if(!d.size())
            dr[i] = n+1;
        else
            dr[i] = d.back();
        d.push_back(i);
    }
    for(int i = 1; i <= n; ++i)
    {
        int sz = dr[i] - st[i] - 1;
        if(v[i] >= mx[sz])
            mx[sz] = v[i];
    }
    for(int i = n; i >= 1; --i)
        prmx[i] = max(prmx[i+1], mx[i]);
    for(int i = 1; i <= n; ++i)
        cout << prmx[i] << " ";
    return 0;
}
