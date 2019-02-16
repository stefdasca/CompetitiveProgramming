#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
long long rand_seed()
{
	long long a = rng();
    return a;
}
int n, v[300002], xorr[300002], xorl[300002];
map<int, int>par, impar;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> v[i];
    for(int i = 1; i <= n; ++i)
        xorr[i] = xorr[i-1] ^ v[i];
    long long ans = 0;
    par[0]++;
    for(int i = 1; i <= n; ++i)
    {
        if(i % 2 == 0)
        {
            ans += par[xorr[i]];
            par[xorr[i]]++;
        }
        else
        {
            ans += impar[xorr[i]];
            impar[xorr[i]]++;
        }
    }
    cout << ans;
    return 0;
}

