#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#define mod 1000000007
using namespace std;
long long n, b, k, x;
long long frq[12];
map<long long, long long>care;
vector<long long>v[1002];
long long Rose = 0;
long long pw(long long b, long long ex)
{
    long long sol = 1;
    while(ex)
    {
        if(ex & 1)
            sol = (sol * b)%x;
        b = (b*b)%x;
        ex >>= 1;
    }
    return sol;
}
void divide(long long nr)
{
    if(care.find(nr) != care.end())
        return;
    if(nr == 1)
    {
        ++Rose;
        care[nr] = Rose;
        for(long long i = 0; i < x; ++i)
            v[Rose].push_back(0);
        for(long long i = 1; i <= 9; ++i)
            v[Rose][i % x] += frq[i];
        return;
    }
    divide(nr/2 + nr%2);
    divide(nr/2);
    ++Rose;
    care[nr] = Rose;
    for(long long i = 0; i < x; ++i)
        v[Rose].push_back(0);
    long long p10 = pw(10, nr/2);
    for(long long i = 0; i < x; ++i)
    {
        long long nrest = (1LL * i * p10)%x;
        long long c1 = care[nr/2 + nr%2];
        long long c2 = care[nr/2];
        for(long long j = 0; j < x; ++j)
            v[Rose][(nrest + j)%x] = (v[Rose][(nrest + j)%x] + v[c1][i] * v[c2][j])%mod;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    // shuffle(permutation.begin(), permutation.end(), rng);
    cin >> n >> b >> k >> x;
    for(long long i = 1; i <= n; ++i)
    {
        long long nr;
        cin >> nr;
        frq[nr]++;
    }
    divide(b);
    cout << v[care[b]][k] << '\n';
    return 0;
}
