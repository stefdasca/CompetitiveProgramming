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

int main()
{
    int real = 0;
    cout << "? ";
    for(int i = 0; i <= 99; ++i)
        cout << i << " ";
    cout << endl;
    int ans;
    cin >> ans;
    vector<int>biti;
    for(int i = 7; i <= 13; ++i)
        if((ans & (1<<i)))
            real += (1<<i), biti.push_back(i);
    cout << "? ";
    for(int i = 1; i <= 100; ++i)
        cout << ((i << 7)|1) << " ";
    cout << endl;
    cin >> ans;
    for(int i = 1; i <= 6; ++i)
        if((ans & (1<<i)))
            real += (1<<i);
    if((ans & 1) == 0)
        real++;
    cout << "! " << real;
    return 0;
}

