#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#define fi first
#define se second
using namespace std;
int n;
long long v[502], scos[502];
long long nnn;
map<long long, long long>n4;
map<long long, long long>n3;
map<long long, long long>mp;
long long gcd(long long a, long long b)
{
    long long c;
    while(b)
    {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}
bool isprime(int x)
{
    for(int i = 2; i*i <= x; ++i)
        if(x % i == 0)
            return 0;
    return 1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    // shuffle(permutation.begin(), permutation.end(), rng);
    cin>>n;
    long long Nmax = 2LL * (1LL<<60);
    for(long long i = 1; i * i * i * i <= Nmax; ++i)
        n4[1LL * i * i * i * i] = i;
    for(long long i = 1; i * i * i <= Nmax; ++i)
        n3[1LL * i * i * i] = i;
    for(int i = 1; i <= n; ++i)
    {
        long long x;
        cin >> x;
        v[i] = x;
        bool gg = 0;
        if(n4[x]) // n^4
        {
            mp[n4[x]] += 4;
            gg = 1;
            scos[i] = 1;
        }
        if(gg)
            continue;
        if(n3[x]) // n^3
        {
            mp[n3[x]] += 3;
            gg = 1;
            scos[i] = 1;
        }
        if(gg)
            continue;
        long long xx = (int)sqrt(x);
        if(xx * xx == x)  // n^2, n prim
        {
            if(isprime(xx))
            {
                mp[xx] += 2;
                gg = 1;
                scos[i] = 1;
            }
        }
    }
    for(int i = 1; i <= n; ++i)
    {
        for(int j = i+1; j <= n; ++j)
        {
            if(v[i] == v[j])
                continue;
            long long plm = gcd(v[i], v[j]);
            if(plm != 1)
            {
                if(!scos[i])
                {
                    mp[plm] ++;
                    mp[v[i] / plm] ++;
                    scos[i] = 1;
                    for(int jj = i+1;jj <= n; ++jj)
                        if(v[jj] == v[i] && !scos[jj])
                        {
                             mp[plm] ++;
                             mp[v[i] / plm] ++;
                             scos[jj] = 1;
                        }
                }
                if(!scos[j])
                {
                    mp[plm] ++;
                    mp[v[j] / plm] ++;
                    scos[j] = 1;
                    for(int jj = j+1;jj <= n; ++jj)
                        if(v[jj] == v[j] && !scos[jj])
                        {
                             mp[plm] ++;
                             mp[v[j] / plm] ++;
                             scos[jj] = 1;
                        }
                }
            }
        }
    }
    long long sol = 1;
    for(int i = 1; i <= n; ++i)
        if(!scos[i])
        {
            int pp = 1;
            for(int j = i; j <= n; ++j)
                if(v[j] == v[i])
                    pp ++, scos[j] = 1;
            sol = (sol * pp * pp) % 998244353;
        }
    map<long long, long long> ::iterator it;
    for(it = mp.begin(); it != mp.end(); ++it)
        sol = (sol * 1LL * (it->second+1)) % 998244353;
    cout << sol;
    return 0;
}
