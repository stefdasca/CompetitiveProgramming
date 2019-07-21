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

int n, m, k;
int aint[12][12][800002];
int lst[800002], fi[800002];
int lazy[800002];
string s;

void build(int nod, int st, int dr)
{
    if(st == dr)
    {
        lst[nod] = s[dr] - 'a';
        fi[nod] = s[st] - 'a';
        return;
    }
    int mid = (st+dr) >> 1;
    build(nod << 1, st, mid);
    build(nod << 1|1, mid+1, dr);
    for(int i = 0; i < k; ++i)
        for(int j = 0; j < k; ++j)
            aint[i][j][nod] = aint[i][j][nod << 1] + aint[i][j][nod << 1|1];
    fi[nod] = fi[nod << 1];
    lst[nod] = lst[nod << 1|1];
    aint[lst[nod << 1]][fi[nod << 1|1]][nod]++;
}
void propagate(int nod, int st, int dr)
{
    if(!lazy[nod])
        return;
    for(int i = 0; i < k; ++i)
        for(int j = 0; j < k; ++j)
            aint[i][j][nod] = 0;
    aint[lazy[nod] - 1][lazy[nod] - 1][nod] = dr - st;
    fi[nod] = lst[nod] = lazy[nod] - 1;
    if(st != dr)
    {
        lazy[nod<<1] = lazy[nod];
        lazy[nod<<1|1] = lazy[nod];
    }
    lazy[nod] = 0;
}

void update(int nod, int st, int dr, int L, int R, int val)
{
    if(L <= st && dr <= R)
        lazy[nod] = val;
    if(lazy[nod])
        propagate(nod, st, dr);
    if(dr < L || st > R)
        return;
    if(L <= st && dr <= R)
        return;
    int mid = (st + dr) / 2;
    update(nod << 1, st, mid, L, R, val);
    update(nod << 1|1, mid+1, dr, L, R, val);
    for(int i = 0; i < k; ++i)
        for(int j = 0; j < k; ++j)
            aint[i][j][nod] = aint[i][j][nod << 1] + aint[i][j][nod << 1|1];
    fi[nod] = fi[nod << 1];
    lst[nod] = lst[nod << 1|1];
    aint[lst[nod << 1]][fi[nod << 1|1]][nod]++;
}
int pz[12];
int qu(string s)
{
    for(int i = 0; i < s.size(); ++i)
        pz[s[i] - 'a'] = i;
    int ans = 1;
    for(int i = 0; i < k; ++i)
        for(int j = 0; j < k; ++j)
            if(pz[i] >= pz[j])
                ans += aint[i][j][1];
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> k;
    cin >> s;
    s = ' ' + s;
    build(1, 1, n);
    for(int i = 1; i <= m; ++i)
    {
        int tip;
        cin >> tip;
        if(tip == 1)
        {
            int st, dr;
            char p;
            cin >> st >> dr >> p;
            update(1, 1, n, st, dr, (p - 'a' + 1));
        }
        else
        {
            string s;
            cin >> s;
            cout << qu(s) << '\n';
        }
    }
    return 0;
}
