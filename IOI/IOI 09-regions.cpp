/*

                IOI 09-regions

    We can use sqrt decomposition to solve this problem. Let's precompute all the answers for the best min(r, sqrt(r)) regions and for the other
regions, we can use binary search to compute the answer, based on the dfs order.

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

// #define fisier

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

int n, r, q, sr[25002], st[200002], dr[200002], reg[200002], m, nd[200002], sz[25002];

pair<int, int> bst[25002];

int iz[25002];

vector<int> v[200002];

vector<int> ap[25002];

int wh[1002];
int ans[1002][25002];
int crr = 0;

int above[1002];
void dfs(int nod)
{
    for(int i = 1; i <= min(r, 500); ++i)
        ans[i][reg[nod]] += above[i];
    above[iz[reg[nod]]]++;
    for(int i = 0; i < v[nod].size(); ++i)
    {
        int vecin = v[nod][i];
        dfs(vecin);
    }
    above[iz[reg[nod]]]--;
}

void dfs2(int nod)
{
    ++m;
    st[nod] = m;
    nd[m] = nod;
    ap[reg[nod]].pb(m);
    for(int i = 0; i < v[nod].size(); ++i)
    {
        int vecin = v[nod][i];
        dfs2(vecin);
    }
    dr[nod] = m;
}

int cb(int area, int mx)
{
    int st = 0;
    int dr = ap[area].size() - 1;
    int ans = -1;
    while(st <= dr)
    {
        int mid = (st + dr) / 2;
        if(ap[area][mid] <= mx)
            ans = mid, st = mid + 1;
        else
            dr = mid - 1;
    }
    return (ans + 1);
}
int solve(int ra, int rb)
{
    int ans = 0;
    for(int i = 0; i < ap[ra].size(); ++i)
    {
        int nod = nd[ap[ra][i]];
        ans += cb(rb, dr[nod]) - cb(rb, st[nod] - 1);
    }
    return ans;
}
int main()
{

    #ifdef fisier
        ifstream f("input.in");
        ofstream g("output.out");
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> r >> q;
    for(int i = 1; i <= n; ++i)
    {
        if(i > 1)
        {
            int tt;
            cin >> tt >> reg[i];
            v[tt].pb(i);
        }
        else
            cin >> reg[i];
        sz[reg[i]]++;
    }
    for(int i = 1; i <= r; ++i)
        bst[i] = {sz[i], i};
    sort(bst + 1, bst + r + 1);
    for(int i = r; i >= max(1, r - 499); --i)
    {
        m = 0;
        ++crr;
        iz[bst[i].se] = crr;
        wh[crr] = bst[i].se;
    }
    dfs(1);
    dfs2(1);
    for(int i = 1; i <= q; ++i)
    {
        int a, b;
        cin >> a >> b;
        if(iz[a])
            cout << ans[iz[a]][b] << endl;
        else
            cout << solve(a, b) << endl;
    }
    return 0;
}
