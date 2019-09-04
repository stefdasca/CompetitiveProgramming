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
bool rau[200002];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    cin >> s;
    if(n % 2 == 1)
    {
        cout << "No";
        return 0;
    }
    int dif = 0;
    bool xz = 0;
    for(int i = 0; i < s.size(); ++i)
    {
        if(s[i] == ')' && !dif)
        {
            rau[i] = 1;
            xz = 1;
            break;
        }
        if(s[i] == '(')
            ++dif;
        else
            --dif;
    }
    if(dif == 0 && !xz)
    {
        cout << "Yes";
        return 0;
    }
    if(!xz && dif > 0)
    {
        cout << "No";
        return 0;
    }
    dif = 0;
    for(int i = 0; i < s.size(); ++i)
    {
        if(rau[i])
            continue;
        if(s[i] == '(')
            ++dif;
        else
            --dif;
        if(dif < 0)
        {
            cout << "No";
            return 0;
        }
    }
    if(dif == 1)
    {
        cout << "Yes";
        return 0;
    }
    cout << "No";
    return 0;
    return 0;
}
