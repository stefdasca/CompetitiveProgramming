#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#define fi first
#define se second
#define pb push_back
#define pf push_front
#define mod 1000000007

using namespace std;

typedef long long ll;

int n;
struct punct
{
    int x, y, z;
    int pi;
};
punct v[50002];
bool cmp(punct a, punct b)
{
    if(a.x == b.x && a.y == b.y)
        return a.z < b.z;
    if(a.x == b.x)
        return a.y < b.y;
    return a.x < b.x;
}

vector<int>rem;

int ct;
pair<int, int> ans[50002];

vector<int>poz;
void solve()
{
    vector<int>ordine;
    bool dir = 0;
    bool ignore = 0;
    vector<int>rms;
    for(int i = 0; i < poz.size(); )
    {
        int j = i;
        vector<int>BFR;
        while(j < poz.size() && v[poz[j]].y == v[poz[i]].y)
        {
            BFR.pb(poz[j]);
            ++j;
        }
        i = j;
        while(BFR.size() >= 2)
        {
            int a = BFR.back();
            BFR.pop_back();
            int b = BFR.back();
            BFR.pop_back();
            ans[++ct] = {v[a].pi, v[b].pi};
        }
        for(int q = 0; q < BFR.size(); ++q)
            ordine.pb(BFR[q]);
    }
    if(ordine.size() % 2 == 1)
    {
        rem.pb(ordine.back());
        ordine.pop_back();
    }
    for(int i = 0; i < ordine.size(); i += 2)
        ans[++ct] = {v[ordine[i]].pi, v[ordine[i+1]].pi};
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 1; i <= n; ++i)
    {
        cin >> v[i].x >> v[i].y >> v[i].z;
        v[i].pi = i;
    }
    sort(v+1, v+n+1, cmp);
    for(int i = 1; i <= n;)
    {
        poz.clear();
        int j = i;
        while(j <= n && v[i].x == v[j].x)
            poz.pb(j), ++j;
        solve();
        i = j;
    }
    for(int i = 0; i < rem.size(); i += 2)
        ans[++ct] = {v[rem[i]].pi, v[rem[i+1]].pi};
    for(int i = 1; i <= ct; ++i)
        cout << ans[i].fi << " " << ans[i].se << '\n';
    return 0;
}
