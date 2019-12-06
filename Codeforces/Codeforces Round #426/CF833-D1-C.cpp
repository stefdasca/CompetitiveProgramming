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

vector<int> L, R;

int n;

int ans = 0;

int num[10];
int keep[10];

bool any(int l, int r)
{
    if(l > r)
        return 0;
    for(int i = l; i <= r; i++)
        if(num[i])
            return 1;
    return 0;
}

bool dfs(int pos, bool lf, bool rf)
{
    if(pos == n)
        return 1;
    int l = L[pos], r = R[pos];
    if(lf & rf)
    {
        if(l == r)
        {
            if(num[l])
            {
                num[l]--;
                if(dfs(pos + 1, 1, 1))
                    return 1;
                num[l]++;
            }
            return 0;
        }

        if(any(l + 1, r - 1))
            return 1;
        if(num[l])
        {
            num[l]--;
            if(dfs(pos + 1, 1, 0))
                return 1;
            num[l]++;
        }

        if(num[r])
        {
            num[r]--;
            if(dfs(pos + 1, 0, 1))
                return 1;
            num[r]++;
        }

        return 0;
    }
    else if(lf)
    {
        if(any(l + 1, 9))
            return 1;
        if(num[l])
        {
            num[l]--;
            if(dfs(pos + 1, 1, 0))
                return 1;
            num[l]++;
        }
        return 0;
    }
    else if(rf)
    {
        if(any(0, r - 1))
            return 1;
        if(num[r])
        {
            num[r]--;
            if(dfs(pos + 1, 0, 1))
                return 1;
            num[r]++;
        }
        return 0;
    }
    return 0;
}

void go(int n, int sum)
{
    if(n == 10)
    {
        memcpy(num, keep, sizeof keep);
        num[0] += sum;
        if(dfs(0, 1, 1))
            ans++;
        return;
    }
    for(int i = 0; i <= sum; i++)
    {
        keep[n] = i;
        go(n + 1, sum - i);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll l, r;
    cin >> l >> r;
    if(l == r)
    {
        cout << 1;
        return 0;
    }
    for(; l; l /= 10)
        L.push_back(l % 10);
    for(; r; r /= 10)
        R.push_back(r % 10);
    n = R.size();
    while(L.size() < n)
        L.push_back(0);
    reverse(L.begin(), L.end());
    reverse(R.begin(), R.end());
    go(1, n);
    cout << ans << endl;
    return 0;
}
