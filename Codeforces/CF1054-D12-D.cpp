#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#define mod 1000000007
#define fi first
#define se second
using namespace std;
int n, k;
int v[200002];
int xorr[200002];
map<int, int>x;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    // shuffle(permutation.begin(), permutation.end(), rng);
    cin>>n>>k;
    for(int i = 1; i <= n; ++i)
        cin >> v[i];
    int mx = (1<<k) - 1;
    x[0] = 1;
    long long solmax = 1LL * n * (n+1)/2;
    for(int i = 1; i <= n; ++i)
    {
        int aa = xorr[i-1] ^ v[i];
        int bb = xorr[i-1] ^ (v[i] ^ mx);
        if(x[aa] > x[bb])
        {
            xorr[i] = bb, solmax -= x[bb];
        }
        else
        {
            xorr[i] = aa;
            solmax -= x[aa];
        }
        x[xorr[i]]++;
    }
    cout << solmax;
    return 0;
}
