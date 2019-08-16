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
int n, m;
int v[100002];
multiset<int>s;
vector<int>tri[100002];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i = 1; i <= n; ++i)
        cin >> v[i], tri[m-1].push_back(i);
    for(int i = 1; i <= n; ++i)
    {
        int nr;
        cin >> nr;
        s.insert(nr);
    }
    for(int i = m-1; i >= 0; --i)
    {
        while(tri[i].size())
        {
            int nod = tri[i].back();
            tri[i].pop_back();
            if(i >= v[nod])
            {
                if(s.find(i - v[nod]) != s.end())
                {
                    cout << i << " ";
                    s.erase(s.lower_bound(i - v[nod]));
                }
                else
                {
                    if(v[nod] + *s.begin() < i)
                    {
                        multiset<int> ::iterator it = s.lower_bound(i - v[nod]);
                        if(it == s.end() || v[nod] + *it >= i)
                            --it;
                        tri[v[nod] + *it].push_back(nod);
                    }
                    else
                        tri[(v[nod] + *s.rbegin()) % m].push_back(nod);
                }
            }
            else
                if(s.find(m - v[nod] + i) != s.end())
                {
                    cout << i << " ";
                    s.erase(s.lower_bound(m - v[nod] + i));
                }
                else
                    tri[(v[nod] + *s.rbegin()) % m].push_back(nod);
        }
    }
    return 0;
}
