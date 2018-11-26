#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
long long n, m;
long long nra[1002], nrb[1002];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    long long ans = 0;
    for(int i = 1; i <= m; ++i)
    {
        nra[i] = n / m + (n % m >= i);
        nrb[i] = nra[i];
    }
    nra[0] = nra[m];
    nrb[0] = nrb[m];
    for(int i = 0; i < m; ++i)
        for(int j = 0; j < m; ++j)
            if((i * i + j * j) % m == 0)
                ans += nra[i] * nrb[j];
    cout << ans;
    return 0;
}
