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
int n, k, m;
vector<int>v[250002], st[250002];
bool viz[250002];
int de[250002], tt[250002];
vector<int>fru;
void dfs(int dad, int nod)
{
    viz[nod] = 1;
    bool le = 1;
    for(int i = 0; i < v[nod].size(); ++i)
    {
        int vecin = v[nod][i];
        if(vecin == dad)
            continue;
        if(!viz[vecin])
        {
            le = 0;
            tt[vecin] = nod;
            st[nod].pb(vecin);
            st[vecin].pb(nod);
            de[vecin] = de[nod] + 1;
            dfs(nod, vecin);
        }
    }
    if(de[nod] >= (n/k + (n%k > 0)))
    {
        cout << "PATH\n";
        cout << de[nod] << '\n';
        int z = nod;
        while(z)
        {
            cout << z << " ";
            z = tt[z];
        }
        exit(0);
    }
    if(le)
        fru.pb(nod);
}
bool trii(int a, int b)
{
    vector<int>za;
    vector<int>zb;
    while(a != b)
    {
        if(de[a] >= de[b])
            za.push_back(a), a = tt[a];
        else
            zb.push_back(b), b = tt[b];
    }
    za.push_back(a);
    if((za.size() + zb.size()) % 3 == 0)
        return 0;
    cout << (za.size() + zb.size()) << '\n';
    for(int i = 0; i < za.size(); ++i)
        cout << za[i] << " ";
    while(!zb.empty())
        cout << zb.back() << " ", zb.pop_back();
    cout << '\n';
    return 1;
}
bool tri(int c, int a, int b)
{
    vector<int>za;
    vector<int>zb;
    za.push_back(c);
    while(a != b)
    {
        if(de[a] >= de[b])
            za.push_back(a), a = tt[a];
        else
            zb.push_back(b), b = tt[b];
    }
    za.push_back(a);
    if((za.size() + zb.size()) % 3 == 0)
        return 0;
    cout << (za.size() + zb.size()) << '\n';
    for(int i = 0; i < za.size(); ++i)
        cout << za[i] << " ";
    while(!zb.empty())
        cout << zb.back() << " ", zb.pop_back();
    cout << '\n';
    return 1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> k;
    for(int i = 1; i <= m; ++i)
    {
        int a, b;
        cin >> a >> b;
        v[a].pb(b);
        v[b].pb(a);
    }
    de[1] = 1;
    dfs(0, 1);
    cout << "CYCLES\n";
    for(int i = 0; i < k; ++i)
    {
        int aa = 0, bb = 0;
        for(int j = 0; j < v[fru[i]].size(); ++j)
        {
            int va = v[fru[i]][j];
            if(tt[fru[i]] == va)
                continue;
            if(!aa)
                aa = va;
            else
                bb = va;
        }
        if(trii(fru[i], aa))
            continue;
        if(trii(fru[i], bb))
            continue;
        if(tri(fru[i], aa, bb))
            continue;
    }
    return 0;
}
