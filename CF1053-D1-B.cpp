#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#define mod 1000000007
#define fi first
#define se second
using namespace std;
long long n;
long long nrr[300002];
long long nro[300002];
long long nre[300002];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    // shuffle(permutation.begin(), permutation.end(), rng);
    cin>>n;
    long long msk = 0;
    long long sol = 0;
    nre[0] = 1;
    for(long long i = 1; i <= n; ++i)
    {
        long long nr;
        cin >> nr;
        for(long long j = 0; j <= 62; ++j)
            if(nr & (1LL<<j))
                ++msk, nrr[i]++;
        nre[i] = nre[i-1];
        nro[i] = nro[i-1];
        if(msk % 2 == 0)
            nre[i]++;
        else
            nro[i]++;
        long long mx = nrr[i];
        long long sum = nrr[i];
        for(long long j = i - 1; j >= 1; --j)
        {
            sum += nrr[j];
            mx = max(mx, nrr[j]);
            if(sum % 2 == 0 && mx * 2 <= sum)
                ++sol;
            if(sum >= 130)
            {
                if(j <= 1)
                    break;
                if(sum % 2 == 1 && msk % 2 == 1) // bun
                    sol += nro[j-2];
                if(sum % 2 == 0 && msk % 2 == 1) // bun
                    sol += nro[j-2];
                if(sum % 2 == 1 && msk % 2 == 0) // bun
                    sol += nre[j-2];
                if(sum % 2 == 0 && msk % 2 == 0) // bun
                    sol += nre[j-2];
                break;
            }
        }
    }
    cout << sol;
    return 0;
}
