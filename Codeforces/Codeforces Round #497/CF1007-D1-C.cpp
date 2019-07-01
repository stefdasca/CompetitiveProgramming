#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

typedef long long ll;

ll n;
map<pair<ll, ll>, int>mp;
int query(ll a, ll b)
{
    if(a > n || b > n)
        return 3;
    if(mp.find({a, b}) != mp.end())
        return mp[{a, b}];
    cout << a << " " << b << endl;
    int ans;
    cin >> ans;
    if(ans == 0)
        exit(0);
    mp[{a, b}] = ans;
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    ll a = 1, b = 1, ta = 1, tb = 1;
    int x = 0, y = 0;
    while(1)
    {
        int ans = query(a, b);
        if(ans == 1)
        {
            ta = a;
            a += (1LL<<x);
            ++x;
        }
        if(ans == 2)
        {
            tb = b;
            b += (1LL<<y);
            ++y;
        }
        if(ans == 3)
        {
            if(a != ta)
                --x;
            if(b != tb)
                --y;
            a = ta;
            b = tb;
            x = max(x-1, 0);
            y = max(y-1, 0);
        }
    }
    return 0;
}

