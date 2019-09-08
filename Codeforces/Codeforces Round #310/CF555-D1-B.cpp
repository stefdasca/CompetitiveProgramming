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
pair<ll, ll> coord[200002], poduri[200002];
ll difmin[200002], difmax[200002];
int n, m, x[200002];
bool cmp(int a, int b)
{
    return difmin[a] < difmin[b];
}
int pod[200002];
struct cmp2
{
    bool operator()(int a, int b)
    {
        return difmax[a] > difmax[b];
    }
};
priority_queue<int, vector<int>, cmp2>q;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i = 1; i <= n; ++i)
        cin >> coord[i].fi >> coord[i].se;
    for(int i = 1; i <= m; ++i)
    {
        cin >> poduri[i].fi;
        poduri[i].se = i;
    }
    sort(poduri + 1, poduri + m + 1);
    for(int i = 1; i < n; ++i)
    {
        difmin[i] = coord[i+1].fi - coord[i].se;
        difmax[i] = coord[i+1].se - coord[i].fi;
        x[i] = i;
    }
    sort(x+1, x+n, cmp);
    int rsp = 0;
    int pz = 1;
    for(int i = 1; i <= m; ++i)
    {
        while(pz <= (n-1) && difmin[x[pz]] <= poduri[i].fi)
            q.push(x[pz]), ++pz;
        if(q.empty())
            continue;
        if(difmax[q.top()] >= poduri[i].fi)
        {
            int nod = q.top();
            ++rsp;
            q.pop();
            pod[nod] = poduri[i].se;
        }
    }
    if(rsp == n-1)
    {
        cout << "Yes\n";
        for(int i = 1; i <= n-1; ++i)
            cout << pod[i] << " ";
    }
    else
    {
        cout << "No\n";
    }
    return 0;
}

