#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#define mod 1000000007
using namespace std;
long long n, t;
long long v[200002];
struct arr
{
    int pos, nr;
};
arr vv[200002];
bool cmp(arr a, arr b)
{
    return a.nr < b.nr;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    // shuffle(permutation.begin(), permutation.end(), rng);
    cin>>n>>t;
    long long sum = 0;
    long long sol = 0;
    for(int i = 1; i <= n; ++i)
        cin >> v[i], sum += v[i], vv[i] = {i, v[i]};
    sort(vv+1, vv+n+1, cmp);
    int pp = n;
    while(t)
    {
        sol = sol + (t / sum) * pp;
        t %= sum;
        for(int i = 1; i <= n; ++i)
            if(t >= v[i])
                sol++, t-= v[i];
        while(t < vv[pp].nr)
            sum -= vv[pp].nr, --pp;
        if(sum == 0)
            break;
    }
    cout << sol;
    return 0;
}
