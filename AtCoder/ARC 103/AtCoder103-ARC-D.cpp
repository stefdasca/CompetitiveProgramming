/*
        ARC103-D

    * It can be proved using induction that we can build a robot arm using lengths equal to powers of two.

    * Therefore, k <= 35 is good enough to ensure our success.

    * At each step, we will assign directions to the modes for the each position according to the parity of the last bit.
*/

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

int n;
pair<int, int> p[1002];
vector<ll> d;
vector<string> s(1002, "");
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> p[i].fi >> p[i].se;
    if((p[1].fi & 1) == (p[1].se & 1))
    {
        d.push_back(1);
        for(int i = 1; i <= n; i++)
        {
            s[i].push_back('U');
            p[i].se--;
        }
    }
    ll step = 1;
    while(step < (1LL << 33))
    {
        d.push_back(step);
        for(int i = 1; i <= n; i++)
        {
            if((p[i].fi & 1) == (p[i].se & 1))
            {
                cout << -1 << '\n';
                return 0;
            }
            if (p[i].fi & 1)
            {
                if (((p[i].fi - 1) & 2) != (p[i].se & 2))
                {
                    p[i].fi--;
                    s[i].pb('R');
                }
                else
                {
                    p[i].fi++;
                    s[i].pb('L');
                }
            }
            else
            {
                if (((p[i].se - 1) & 2) != (p[i].fi & 2))
                {
                    p[i].se--;
                    s[i].pb('U');
                }
                else
                {
                    p[i].se++;
                    s[i].pb('D');
                }
            }
            p[i].fi /= 2;
            p[i].se /= 2;
        }
        step <<= 1;
    }
    d.push_back(step);
    for (int i = 1; i <= n; i++)
    {
        if(p[i].fi == 1)
            s[i].pb('R');
        else
            if(p[i].fi == -1)
                s[i].pb('L');
            else
                if(p[i].se == 1)
                    s[i].pb('U');
                else
                    s[i].pb('D');
    }
    int m = d.size();
    cout << m << '\n';
    for (int i = 0; i < m; i++)
        cout << d[i] << " ";
    cout << '\n';
    for (int i = 1; i <= n; i++)
        cout << s[i] << '\n';
    return 0;
}

