#include<bits/stdc++.h>
#define god dimasi5eks
#pragma GCC optimize("O3")
#define fi first
#define se second
#define pb push_back
#define pf push_front
#define mod 1000000007
#define dancila 3.14159265359
#define eps 1e-9

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

ll hsh[1000002];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    s = ' ' + s;
    for(int i = 1; i < s.size(); ++i)
        hsh[i] = (hsh[i-1] * 10 + (s[i] - '0')) % mod;
    int n = s.size() - 1;
    int len1, len2;
    for(int len3 = 1; len3 <= n; ++len3)
    {
        ll hsh3 = hsh[s.size() - 1] - mul(hsh[s.size() - len3 - 1], pw(10, len3)) + mod;
        hsh3 %= mod;
        // len2 = len3 - 1, len1 = n - len3 - len2
        len2 = len3 - 1;
        len1 = n - len3 - len2;
        if(len1 + len2 + len3 == n && len1 <= len3 && len2 <= len3 && len1 > 0 && len2 > 0 && len3 > 0)
            if((s[1] != '0' || len1 == 1) && (s[len1 + 1] != '0' || len2 == 1) && (s[len1 + len2 + 1] != '0' || len3 == 1))
            {
                ll hsh2 = hsh[s.size() - len3 - 1] - mul(hsh[s.size() - len3 - len2 - 1], pw(10, len2)) + mod;
                hsh2 %= mod;
                ll hsh1 = hsh[s.size() - len3 - len2 - 1];
                if((hsh1 + hsh2) % mod == hsh3)
                {
                    for(int i = 1; i <= len1; ++i)
                        cout << s[i];
                    cout << "+";
                    for(int i = len1 + 1; i <= len1 + len2; ++i)
                        cout << s[i];
                    cout << "=";
                    for(int i = len1 + len2 + 1; i <= n; ++i)
                        cout << s[i];
                    return 0;
                }
            }
        // len2 = len3, len1 = n - len3 - len2
        len2 = len3;
        len1 = n - len3 - len2;
        if(len1 + len2 + len3 == n && len1 <= len3 && len2 <= len3 && len1 > 0 && len2 > 0 && len3 > 0)
            if((s[1] != '0' || len1 == 1) && (s[len1 + 1] != '0' || len2 == 1) && (s[len1 + len2 + 1] != '0' || len3 == 1))
            {
                ll hsh2 = hsh[s.size() - len3 - 1] - mul(hsh[s.size() - len3 - len2 - 1], pw(10, len2)) + mod;
                hsh2 %= mod;
                ll hsh1 = hsh[s.size() - len3 - len2 - 1];
                if((hsh1 + hsh2) % mod == hsh3)
                {
                    for(int i = 1; i <= len1; ++i)
                        cout << s[i];
                    cout << "+";
                    for(int i = len1 + 1; i <= len1 + len2; ++i)
                        cout << s[i];
                    cout << "=";
                    for(int i = len1 + len2 + 1; i <= n; ++i)
                        cout << s[i];
                    return 0;
                }
            }
        // len1 = len3 - 1, len2 = n - len3 - len1
        len1 = len3 - 1;
        len2 = n - len3 - len1;
        if(len1 + len2 + len3 == n && len1 <= len3 && len2 <= len3 && len1 > 0 && len2 > 0 && len3 > 0)
            if((s[1] != '0' || len1 == 1) && (s[len1 + 1] != '0' || len2 == 1) && (s[len1 + len2 + 1] != '0' || len3 == 1))
            {
                ll hsh2 = hsh[s.size() - len3 - 1] - mul(hsh[s.size() - len3 - len2 - 1], pw(10, len2)) + mod;
                hsh2 %= mod;
                ll hsh1 = hsh[s.size() - len3 - len2 - 1];
                if((hsh1 + hsh2) % mod == hsh3)
                {
                    for(int i = 1; i <= len1; ++i)
                        cout << s[i];
                    cout << "+";
                    for(int i = len1 + 1; i <= len1 + len2; ++i)
                        cout << s[i];
                    cout << "=";
                    for(int i = len1 + len2 + 1; i <= n; ++i)
                        cout << s[i];
                    return 0;
                }
            }
        // len1 = len3, len2 = n - len3 - len1
        len1 = len3;
        len2 = n - len3 - len1;
        if(len1 + len2 + len3 == n && len1 <= len3 && len2 <= len3 && len1 > 0 && len2 > 0 && len3 > 0)
            if((s[1] != '0' || len1 == 1) && (s[len1 + 1] != '0' || len2 == 1) && (s[len1 + len2 + 1] != '0' || len3 == 1))
            {
                ll hsh2 = hsh[s.size() - len3 - 1] - mul(hsh[s.size() - len3 - len2 - 1], pw(10, len2)) + mod;
                hsh2 %= mod;
                ll hsh1 = hsh[s.size() - len3 - len2 - 1];
                if((hsh1 + hsh2) % mod == hsh3)
                {
                    for(int i = 1; i <= len1; ++i)
                        cout << s[i];
                    cout << "+";
                    for(int i = len1 + 1; i <= len1 + len2; ++i)
                        cout << s[i];
                    cout << "=";
                    for(int i = len1 + len2 + 1; i <= n; ++i)
                        cout << s[i];
                    return 0;
                }
            }
    }
    return 0;
}
