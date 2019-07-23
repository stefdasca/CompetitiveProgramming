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

int n;
int v[100002];

struct str{int a, b, c;};

vector<str>op;
int dp[(1<<14)];
str fw[(1<<14)];
int bst[(1<<14)];
bool tri(int st, int dr)
{
    memset(dp, 0, sizeof(dp));
    memset(fw, 0, sizeof(fw));
    memset(bst, -1, sizeof(bst));
    dp[0] = 1;
    deque<int>d;
    d.pb(0);
    while(!d.empty())
    {
        int nod = d[0];
        int nod2 = nod;
        for(int i = 0; i <= 13; ++i)
        {
            if(nod2 & (1<<i))
                nod2 ^= (1<<i);
            if(bst[nod2] == -1)
                bst[nod2] = nod;
            else
                if(dp[nod] < dp[bst[nod2]])
                    bst[nod2] = nod;
        }
        d.pop_front();
        for(int i = st; i <= dr; ++i)
            for(int dif = 1; i + 2 * dif <= dr; ++dif)
            {
                int new_val = nod;
                new_val ^= (1<<(i - st));
                new_val ^= (1<<((i + dif) - st));
                new_val ^= (1<<((i + dif + dif) - st));
                if(!dp[new_val])
                {
                    dp[new_val] = dp[nod] + 1;
                    fw[new_val] = {i, i+dif, i+dif+dif};
                    d.pb(new_val);
                }
            }
    }
    int msk = 0;
    for(int i = st; i <= dr; ++i)
        msk += v[i] * (1<<(i-st));
    if(!dp[msk])
        return 0;
    while(msk != 0)
    {
        op.pb(fw[msk]);
        int aa = fw[msk].a-st, bb = fw[msk].b-st, cc = fw[msk].c-st;
        msk ^= (1<<aa);
        msk ^= (1<<bb);
        msk ^= (1<<cc);
    }
    return 1;
}
void tri2(int st, int msk)
{
    while(msk != 0)
    {
        str pp = fw[msk];
        pp.a += (st - 1), pp.b += (st-1), pp.c += (st-1);
        v[pp.a] ^= 1, v[pp.b] ^= 1, v[pp.c] ^= 1;
        op.pb(pp);
        int aa = fw[msk].a-1, bb = fw[msk].b-1, cc = fw[msk].c-1;
        msk ^= (1<<aa);
        msk ^= (1<<bb);
        msk ^= (1<<cc);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> v[i];
    tri(1, 14);
    op.clear();
    while(n - 6 >= 8)
    {
        if(!v[n])
        {
            --n;
            continue;
        }
        int msk = 0;
        for(int i = n; i >= n-5; --i)
            msk += v[i] * (1LL<<(13+i-n));
        tri2(n - 13, bst[msk]);
    }
    if(!tri(1, n))
    {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    cout << op.size() << '\n';
    for(int i = 0; i < op.size(); ++i)
        cout << op[i].a << " " << op[i].b << " " << op[i].c << '\n';
    return 0;
}
