#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#define fi first
#define se second
#define pb push_back
#define pf push_front
#define mod 998244353

using namespace std;

typedef long long ll;

ll add(ll a, ll b)
{
    ll x = a+b;
    if(x >= mod)
        x -= mod;
    return x;
}
ll mul(ll a, ll b)
{
    return (a*b) % mod;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int>v;
    for(int i = 1; i <= n; i++)
    {
        int nr;
        cin >> nr;
        v.push_back(nr);
    }
    int pz = -1;
    for(int i = 0; i < n; ++i)
        if(v[i] == n)
            pz = i;
    int st = pz-1;
    int dr = pz+1;
    int nec = n-1;
    while(st >= 0 || dr < n)
    {
        if(st < 0)
        {
            if(v[dr] == nec)
                ++dr, --nec;
            else
                return cout << "NO", 0;
        }
        else
            if(dr == n)
            {
                if(v[st] == nec)
                    --st, --nec;
                else
                    return cout << "NO", 0;
            }
            else
            {
                if(v[dr] == nec)
                    ++dr, --nec;
                else
                    if(v[st] == nec)
                        --st, --nec;
                    else
                        return cout << "NO", 0;
            }
    }
    cout << "YES";
    return 0;
}
