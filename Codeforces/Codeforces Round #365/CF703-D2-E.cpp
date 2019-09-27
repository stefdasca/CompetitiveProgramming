#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#define fi first
#define se second
#define pb push_back
#define pf push_front
#define mod 1000000007

using namespace std;

typedef long long ll;

ll n, k;

pair<ll, ll> val[1012];

vector<ll>divi;
vector<int> dp[1012], fw[1012], nxt[1012], pozz[1012];
vector<ll> sum[1012];
vector<pair<ll, ll> >prim;
vector<ll>power[102];

ll put[102][65];

map<ll, ll> position;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;
    ll mnn = (1LL<<60);
    for(int i = 1; i <= n; ++i)
        cin >> val[i].fi, mnn = min(mnn, val[i].fi), val[i].se = i;
    sort(val + 1, val + n + 1);
    if(k == 1)
    {
        cout << 1 << '\n';
        for(int i = 1; i <= n; ++i)
            if(val[i].fi == mnn)
            {
                cout << val[i].se;
            }
        return 0;
    }
    for(ll i = 1; i * i <= k; ++i)
        if(k % i == 0)
        {
            divi.pb(i);
            if(i * i != k)
                divi.pb(k / i);
        }
    sort(divi.begin(), divi.end());
    for(ll i = 2; i * i <= k; ++i)
        if(k % i == 0)
        {
            prim.pb({i, 0});
            while(k % i == 0)
                prim.back().se++, k /= i;
        }
    if(k > 1)
        prim.pb({k, 1});
    for(int i = 0; i < divi.size(); ++i)
    {
        position[divi[i]] = i;
        ll nr = divi[i];
        for(int j = 0; j < prim.size(); ++j)
        {
            power[j].pb(0);
            while(nr % prim[j].fi == 0)
                power[j].back()++, nr /= prim[j].fi;
        }
    }
    for(int j = 0; j < prim.size(); ++j)
    {
        put[j][0] = 1;
        int poz = 1;
        while(1)
        {
            if((1LL<<60) / put[j][poz - 1] >= prim[j].fi)
                put[j][poz] = put[j][poz - 1] * prim[j].fi, ++poz;
            else
                break;
        }
    }
    for(int i = 0; i < n + 3; ++i)
    {
        dp[i].resize(divi.size()+3);
        fw[i].resize(divi.size()+3);
        sum[i].resize(divi.size()+3);
        nxt[i].resize(divi.size()+3);
        pozz[i].resize(divi.size()+3);
    }
    for(int j = 0; j <= n; ++j)
        for(int q = 1; q < divi.size(); ++q)
            dp[j][q] = (1LL<<20);
    vector<int>ans;
    for(int q = 1; q <= n; ++q)
    {
        vector<int>coe(prim.size());
        ll value = val[q].fi;
        for(int j = 0; j < prim.size(); ++j)
            while(val[q].fi % prim[j].fi == 0)
                ++coe[j], val[q].fi /= prim[j].fi;
        for(int j = divi.size() - 1; j >= 0; --j)
        {
            ll prod = 1;
            for(int k = 0; k < prim.size(); ++k)
                prod = prod * put[k][min(prim[k].se, power[k][j] + coe[k])];
            int new_poz = position[prod];
            if(new_poz == j)
                continue;
            if(dp[q - 1][j] + 1 < dp[q][new_poz] || dp[q - 1][j] + 1 == dp[q][new_poz] && sum[q - 1][j] + value < sum[q][new_poz])
            {
                dp[q][new_poz] = dp[q - 1][j] + 1;
                fw[q][new_poz] = j;
                pozz[q][new_poz] = q;
                sum[q][new_poz] = sum[q - 1][j] + value;
                nxt[q][new_poz] = val[q].se;
              //  cout << q << " " << new_poz << " " << val[q].se << '\n';
            }
        }
        for(int j = 0; j < divi.size(); ++j)
        {
            if(dp[q - 1][j] < dp[q][j] || dp[q - 1][j] == dp[q][j] && sum[q - 1][j] < sum[q][j])
            {
                dp[q][j] = dp[q-1][j];
                fw[q][j] = fw[q-1][j];
                sum[q][j] = sum[q-1][j];
                nxt[q][j] = nxt[q-1][j];
                pozz[q][j] = pozz[q-1][j];
            }
        }
        if(dp[q][divi.size() - 1] < dp[q-1][divi.size() - 1] || dp[q][divi.size() - 1] == dp[q-1][divi.size() - 1] && sum[q][divi.size() - 1] < sum[q-1][divi.size() - 1])
        {
            int counterr = dp[q][divi.size() - 1];
            ans.clear();
            int pz = q;
            int oo = divi.size() - 1;
            while(counterr)
            {
                pz = pozz[pz][oo];
               // cout << pz << " " << oo << " " << nxt[pz][oo] << '\n';
                ans.pb(nxt[pz][oo]);
                oo = fw[pz][oo];
                --pz;
                --counterr;
            }
        }
    }
    if(dp[n][divi.size() - 1] == (1<<20))
    {
        cout << -1;
        return 0;
    }
    cout << dp[n][divi.size() - 1] << '\n';
    for(int i = 0; i < ans.size(); ++i)
        cout << ans[i] << " ";
    return 0;
}
