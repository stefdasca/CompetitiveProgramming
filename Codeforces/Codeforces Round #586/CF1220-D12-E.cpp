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

int n, m, nr, start;
int val[200002];
vector<int>v[200002], sol[200002];
bool viz[200002];
int niv[200002], low[200002];
deque<int>d;
int mch[200002];
ll chainsum[200002];

vector<int>dfstree[200002];

void dfs(int dad, int nod)
{
    viz[nod] = 1;
    low[nod] = niv[nod];
    d.push_back(nod);
    for(int i = 0; i < v[nod].size(); ++i)
    {
        int vecin = v[nod][i];
        if(vecin == dad)
            continue;
        if(viz[vecin])
        {
            mch[nod]++;
            low[nod] = min(low[nod], niv[vecin]);
            continue;
        }
        niv[vecin] = niv[nod] + 1;
        dfstree[nod].pb(vecin);
        dfstree[vecin].pb(nod);
        dfs(nod, vecin);
        mch[nod] += mch[vecin];
        chainsum[nod] = max(chainsum[nod], chainsum[vecin]);
        low[nod] = min(low[nod], low[vecin]);
        if(low[vecin] >= niv[nod])
        {
            nr++;
            int lst;
            do
            {
                sol[nr].push_back(d.back());
                lst = d.back();
                d.pop_back();
            }while(!d.empty() && lst != vecin);
            sol[nr].push_back(nod);
        }
    }
    chainsum[nod] += val[nod];
}

ll ans_max = 0, maxBFR;
bool gods[200002];
void bfr(int nod)
{
    deque<int>d;
    d.pb(nod);
    while(!d.empty())
    {
        int nod = d[0];
        gods[nod] = 1;
        d.pop_front();
        if(!mch[nod])
            maxBFR = max(maxBFR,  chainsum[nod]);
        else
        {
            ans_max += val[nod];
            for(int i = 0; i < dfstree[nod].size(); ++i)
            {
                int vecin = dfstree[nod][i];
                if(gods[vecin])
                    continue;
                d.pb(vecin);
                gods[vecin] = 1;
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i = 1; i <= n; ++i)
        cin >> val[i];
    for(int i = 1; i <= m; ++i)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    cin >> start;
    dfs(0, start);
    bfr(start);
    cout << ans_max + maxBFR << '\n';
    return 0;
}

