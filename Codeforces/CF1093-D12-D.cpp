/// be happy!

#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#define mod 998244353
using namespace std;
long long t, n, m;
vector<int>v[300002];
bool gg = 1;
bool viz[300002];
int bip[300002];
long long pw(long long b, long long ex)
{
    long long ans = 1;
    while(ex)
    {
        if(ex & 1)
            ans = (ans * b) % mod;
        b = (b * b) % mod;
        ex >>= 1;
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    for(int i = 1; i <= t; ++i)
    {
        for(int j = 1; j <= n; ++j)
            v[j].clear(), viz[j] = 0, bip[j] = 0;
        cin >> n >> m;
        for(int j = 1; j <= m; ++j)
        {
            int a, b;
            cin >> a >> b;
            v[a].push_back(b);
            v[b].push_back(a);
        }
        gg = 1;
        long long ans = 1;
        for(int j = 1; j <= n; ++j)
        {
            if(!viz[j])
            {
                deque<int>d;
                d.push_back(j);
                viz[j] = 1;
                bip[j] = 1;
                int b1 = 1;
                int b2 = 0;
                while(!d.empty())
                {
                    int nod = d[0];
                    d.pop_front();
                    for(int q = 0; q < v[nod].size(); ++q)
                    {
                        int vecin = v[nod][q];
                        if(!viz[vecin])
                        {
                            bip[vecin] = 3 - bip[nod];
                            viz[vecin] = 1;
                            if(bip[vecin] == 1)
                                ++b1;
                            else
                                ++b2;
                            d.push_back(vecin);
                        }
                        else
                            if(bip[vecin] == bip[nod])
                                gg = 0;
                    }
                }
                long long aaz = (1LL * pw(2, b2) + 1LL * pw(2, b1));
                aaz %= mod;
                ans = ans * aaz;
                ans %= mod;
            }
        }
        if(gg)
            cout << ans << '\n';
        else
            cout << 0 << '\n';
    }
    return 0;
}
