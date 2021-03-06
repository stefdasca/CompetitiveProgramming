/*
        JOI 18-Candies

    Based on how the optimal solution looks for k and k+1 pieces taken, we can observe that there are two main cases.

    We either add some new number unused before(if possible), or turn xOxOxOx to OxOxOxO, where O = taken, x = untaken.

    We can simulate this by keeping the range of elements for each number present in the priority queue, and at each step
we take the best sum we can add, while also updating the ranges for the numbers adjacent to the chosen number.

*/
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

// #define fisier 1

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

priority_queue<pair<ll, int> >q;

int n, st[200002], dr[200002];

ll ans, v[200002];

bool pus[200002];

int main()
{

    #ifdef fisier
        ifstream f("input.in");
        ofstream g("output.out");
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 1; i <= n; ++i)
    {
        cin >> v[i];
        st[i] = i-1;
        dr[i] = i+1;
        q.push({v[i], i});
    }
    v[0] = v[n+1] = -(1LL<<60);
    for(int i = 1; i <= (n+1) / 2; ++i)
    {
        while(!q.empty() && pus[q.top().se])
            q.pop();
        pair<ll, int> tp = q.top();
        q.pop();
        ans += tp.fi;
        cout << ans << '\n';
        pus[st[tp.se]] = 1, pus[dr[tp.se]] = 1;
        v[tp.se] = v[st[tp.se]] + v[dr[tp.se]] - v[tp.se];
        q.push({v[tp.se], tp.se});
        st[tp.se] = st[st[tp.se]]; dr[st[tp.se]] = tp.se;
        dr[tp.se] = dr[dr[tp.se]]; st[dr[tp.se]] = tp.se;
    }
    return 0;
}
