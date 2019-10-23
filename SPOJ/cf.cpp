/*
                    SPOJ TREEISO

    * We will implement the algorithm described in this paper - http://wwwmayr.in.tum.de/konferenzen/Jass08/courses/1/smal/Smal_Paper.pdf

    * Firstly, we are going to find the center(s) of the tree using BFS.
    * If the array of degrees or the number of centers isn't equal, then the answer is NO.
    * Then, we will try every pair of centers and check whether the hash of the roots are equal. If we found one such pair, then we will print YES.
Otherwise, we will print NO.

*/
#include<bits/stdc++.h>
#define god dimasi5eks
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

int t, n;

ll P[200102];

vector<int>v[2][200002];
vector<int>centri[3];

bool dii[200002];
int phi[2][200002];
int bfs(int plc, int nod)
{
    for(int i = 1; i <= n; ++i)
        dii[i] = 0;
    deque<int>d;
    d.pb(nod);
    dii[nod] = 1;
    while(!d.empty())
    {
        int nodd = d[0];
        d.pop_front();
        for(int i = 0; i < v[plc][nodd].size(); ++i)
        {
            int vecin = v[plc][nodd][i];
            if(dii[vecin] == 0)
            {
                dii[vecin] = 1;
                phi[plc][vecin] = nodd;
                d.pb(vecin);
            }
        }
        if(d.empty())
            return nodd;
    }
}
int sz[2][200002];
int dfs(int plc, int dad, int nod)
{
    sz[plc][nod] = 1;
    vector<pair<int, int> >hsh;
    for(int i = 0; i < v[plc][nod].size(); ++i)
    {
        int vecin = v[plc][nod][i];
        if(vecin == dad)
            continue;
        hsh.pb({dfs(plc, nod, vecin), vecin});
        sz[plc][nod] += sz[plc][vecin];
    }
    sort(hsh.begin(), hsh.end());
    int hshh = 5, pot = 1;
    for(int i = 0; i < hsh.size(); ++i)
    {
        pair<int, int> hs = hsh[i];
		hshh = add(hshh, mul(hs.fi, P[pot]));
		pot += 2 * sz[plc][hs.se];
    }
    hshh = add(hshh, mul(11, P[pot]));
    return hshh;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    P[0] = 1;
	for (int i = 1; i <= 200010; ++i)
		P[i] = mul(P[i-1], 257);
    cin >> t;
    for(; t; --t)
    {
        cin >> n;
        int d[2][2];
        for(int k = 0; k <= 1; ++k)
        {
            for(int i = 1; i < n; ++i)
            {
                int a, b;
                cin >> a >> b;
                v[k][a].pb(b);
                v[k][b].pb(a);
            }
            d[k][0] = bfs(k, 1);
            d[k][1] = bfs(k, d[k][0]);
            vector<int> diam;
			while (1)
            {
				diam.pb(d[k][1]);
				if (d[k][1] == d[k][0])
                    break;
				d[k][1] = phi[k][d[k][1]];
			}
			int len = diam.size();
			centri[k].pb(diam[len/2]);
			if (len%2 == 0)
                centri[k].pb(diam[len/2-1]);
        }
        vector<int>aa, bb;
        for(int i = 1; i <= n; ++i)
            aa.pb(v[0][i].size()), bb.pb(v[1][i].size());
        sort(aa.begin(), aa.end());
        sort(bb.begin(), bb.end());
        if(aa != bb)
            cout << "NO\n";
        else
            if(centri[0].size() != centri[1].size())
                cout << "NO\n";
            else
            {
                bool ok = 0;
                int val = dfs(1, 0, centri[1][0]);
                for(int j = 0; j < centri[0].size(); ++j)
                {
                    if(dfs(0, 0, centri[0][j]) == val)
                        ok = 1;
                }
                if(ok)
                    cout << "YES\n";
                else
                    cout << "NO\n";
            }
        centri[0].clear();
        centri[1].clear();
        for(int i = 1; i <= n; ++i)
        {
            v[0][i].clear();
            v[1][i].clear();
        }
    }
    return 0;
}
