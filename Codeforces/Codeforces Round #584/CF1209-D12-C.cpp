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
int t, n;
string s;
vector<int>dg[11];
int col[200002];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    for(; t; --t)
    {
        cin >> n;
        cin >> s;
        for(int j = 0; j < n; ++j)
            dg[(s[j] - '0')].pb(j+1);
        int mxx = 0;
        int pus2 = -1;
        for(int j = 0; j <= 9; ++j)
        {
            if(j == 0)
            {
                for(int i = 0; i < dg[0].size(); ++i)
                {
                    col[dg[0][i]] = 1;
                    mxx = max(mxx, dg[0][i]);
                }
            }
            else
            {
                for(int i = 0; i < dg[j].size(); ++i)
                {
                    if(dg[j][i] < mxx || (pus2 != -1 && pus2 < j))
                    {
                        if(pus2 == -1)
                            pus2 = j;
                        col[dg[j][i]] = 2;
                    }
                    else
                        col[dg[j][i]] = 1, mxx = dg[j][i];
                }
            }
        }
        string ss;
        bool rau = 0;
        for(int j = 1; j <= n; ++j)
            if(col[j] == 1)
                ss += s[j-1];
        for(int j = 1; j <= n; ++j)
            if(col[j] == 2)
                ss += s[j-1];
        for(int j = 1; j < n; ++j)
            if(ss[j] < ss[j-1])
                rau = 1;
        if(rau == 1)
        {
            cout << "-\n";
        }
        else
        {
            for(int j = 1; j <= n; ++j)
                cout << col[j];
            cout << '\n';
        }
        for(int j = 1; j <= n; ++j)
            col[j] = 0;
        for(int j = 0; j <= 9; ++j)
            dg[j].clear();
    }
    return 0;
}
