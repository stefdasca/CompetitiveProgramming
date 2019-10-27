/// the ginger empire has risen

#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#define mod 1000000007
#define fi first
#define se second
using namespace std;
long long n, k, frq[200002], mn;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    // shuffle(permutation.begin(), permutation.end(), rng);
    cin >> n >> k;
    for(int i = 1; i <= n; ++i)
    {
        long long nr;
        cin >> nr;
        if(i == 1)
            mn = nr;
        else
            mn = min(mn, nr);
        frq[nr]++;
    }
    long long sum = 0;
    long long cost = 0;
    long long sol = 0;
    for(int i = 200000; i > mn; --i)
    {
        sum += frq[i];
        if(sum + cost <= k)
            cost += sum;
        else
        {
            ++sol;
            cost = sum;
        }
    }
    if(cost > 0)
        sol++;
    cout << sol;
    return 0;
}
