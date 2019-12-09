#include<bits/stdc++.h>
#define god dimasi5eks
#pragma GCC optimize("O3")
#define fi first
#define se second
#define pb push_back
#define pf push_front
#define mod 1000000009
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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
long long rand_seed()
{
    long long a = rng();
    return a;
}
int n;
map<int, pair<int, int> > pos;
map<pair<int, int>, int> id;
vector<set<int> > p, ch;
bool canrem(int i)
{
    int ok = 1;
    for(auto j : p[i])
        ok &= (ch[j].size() > 1);
    return ok;
}
void rem(int i)
{
    for(auto j : p[i])
        ch[j].erase(i);
    for(auto j : ch[i])
        p[j].erase(i);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    p.resize(n);
    ch.resize(n);
    for (int x, y, i = 0; i < n; i++)
    {
        cin >> y >> x;
        pos[i] = {x, y};
        id[{x, y}] = i;
    }
    for(int i = 0; i < n; i++)
    {
        int x = pos[i].fi, y = pos[i].se;
        for(int z = -1; z < 2; z++)
        {
            if(id.count({x+1, y+z}))
                p[i].insert(id[{x+1, y+z}]);
            if(id.count({x-1, y+z}))
                ch[i].insert(id[ {x-1, y+z}]);
        }
    }
    set<int> can;
    for(int i = 0; i < n; i++)
    {
        int x = pos[i].first, y = pos[i].second;
        if(canrem(i))
            can.insert(i);
    }
    ll ans = 0;
    for(int i = 0; i < n; i++)
    {
        int j;
        if(i % 2 == 0)
            j = *can.rbegin();
        else
            j = *can.begin();
        ans = mul(ans, n);
        ans = add(ans, j);
        int x = pos[j].fi;
        int y = pos[j].se;
        rem(j);
        can.erase(j);
        id.erase(pos[j]);
        for(int z = -2; z < 3; z++)
        {
            if(id.count({x, y+z}))
                can.erase(id[{x, y+z}]);
            if(id.count({x-1, y+z}))
                can.erase(id[{x-1, y+z}]);
        }
        for(int z = -2; z < 3; z++)
        {
            if(id.count({x, y+z}) && canrem(id[ {x, y+z}]))
                can.insert(id[{x, y+z}]);
            x--;
            if(id.count({x, y+z}) && canrem(id[ {x, y+z}]))
                can.insert(id[{x, y+z}]);
            x++;
        }
    }
    cout << ans;
    return 0;
}
