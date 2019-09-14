#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#define fi first
#define se second
#define pb push_back
#define pf push_front
#define mod 1000000007

using namespace std;

typedef long long ll;


int add(int a, int b)
{
    ll x = a+b;
    if(x >= mod)
        x -= mod;
    if(x < 0)
        x += mod;
    return x;
}
ll mul(ll a, ll b)
{
    return (a*b) % mod;
}

ll pw(ll a, ll b)
{
    ll ans = 1;
    while(b)
    {
        if(b & 1)
            ans = (ans * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return ans;
}
int n, q, v[200002], pus[200002], ans;
vector<int>ff[200002];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> q;
    for(int i = 1; i <= n; ++i)
        cin >> v[i], ff[v[i]].pb(i);
    for(int i = 1; i <= n; ++i)
    {
        if(pus[i])
            continue;
        int st = i, dr = i;
        int poz = 0;
        set<int>cul;
        while(st <= dr)
        {
            ++poz;
            if(!pus[st])
            {
                cul.insert(v[st]);
                for(int j = 0; j < ff[v[st]].size(); ++j)
                {
                    int vec = ff[v[st]][j];
                    dr = max(dr, vec);
                    pus[vec] = 1;
                }
            }
            ++st;
        }
        int mmm = 0;
        set<int> ::iterator it;
        for(it = cul.begin(); it != cul.end(); ++it)
        {
            int BFR = *it;
            mmm = max(mmm, (int)ff[BFR].size());
        }
        ans = ans + poz - mmm;
    }
    cout << ans;
    return 0;
}

