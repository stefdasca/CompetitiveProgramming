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
string s;
int frq[28];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    cin >> s;
    for(int i = 0; i < n; ++i)
        frq[(s[i] - 'a')]++;
    for(int i = 100000; i >= 0; --i)
    {
        if(frq[('o' - 'a')] >= i && frq[('n' - 'a')] >= i && frq[('e' - 'a')] >= i)
        {
            frq[('o' - 'a')] -= i;
            frq[('n' - 'a')] -= i;
            frq[('e' - 'a')] -= i;
            if(frq['z' - 'a'] == frq['e' - 'a'] && frq['e' - 'a'] == frq['r' - 'a'] && frq['r' - 'a'] == frq['o' - 'a'])
            {
                for(int j = 1; j <= i; ++j)
                    cout << 1 << " ";
                for(int j = 1; j <= frq[('z' - 'a')]; ++j)
                    cout << 0 << " ";
                return 0;
            }
            frq[('e' - 'a')] += i;
            frq[('n' - 'a')] += i;
            frq[('o' - 'a')] += i;
        }
    }
    return 0;
}

