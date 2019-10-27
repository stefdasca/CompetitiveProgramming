#include<bits/stdc++.h>
#define god dimasi5eks
#pragma GCC optimize("O3")
#define fi first
#define se second
#define pb push_back
#define pf push_front
#define mod 1000000007

using namespace std;

typedef long long ll;

int n, k;
vector<int>v[1000002];
int lvl[1000002], mnlvl[1000002], nrmax[1000002];
void dfslvl(int nod)
{
    if(!v[nod].size())
    {
        mnlvl[nod] = lvl[nod] - k;
        nrmax[nod] = 1;
        return;
    }
    mnlvl[nod] = (1<<30);
    for(int i = 0; i < v[nod].size(); ++i)
    {
        int vecin = v[nod][i];
        lvl[vecin] = lvl[nod] + 1;
        dfslvl(vecin);
        if(mnlvl[vecin] <= lvl[nod])
        {
            nrmax[nod] += nrmax[vecin];
            mnlvl[nod] = min(mnlvl[nod], mnlvl[vecin]);
        }
    }
}
int ans[1000002];
void solve(int nod)
{
    ans[nod] = (v[nod].size() == 0);
    for(int i = 0; i < v[nod].size(); ++i)
    {
        int vecin = v[nod][i];
        solve(vecin);
        int val = nrmax[nod];
        if(mnlvl[vecin] <= lvl[nod])
            val -= nrmax[vecin];
        ans[nod] = max(ans[nod], val + ans[vecin]);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;
    int lv = 0;
    for(int i = 2; i <= n; ++i)
    {
        int nr;
        cin >> nr;
        v[nr].pb(i);
    }
    dfslvl(1);
    solve(1);
    cout << ans[1];
    return 0;
}
