#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#define mod 1000000007
using namespace std;
long long w, m, k;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    // shuffle(permutation.begin(), permutation.end(), rng);
    cin >> w >> m >> k;
    long long aa = 0;
    int nc = 0;
    while(aa < m)
        aa = aa * 10 + 9, ++nc;
    long long m2 = m;
    while(w)
    {
        if((aa - m + 1) <= w / k / nc)
        {
            w = w - k * (aa - m + 1) * nc;
            ++nc;
            m = aa + 1;
            aa = aa * 10 + 9;
        }
        else
        {
            m = m + w / k / nc;
            break;
        }
    }
    cout << m - m2;
    return 0;
}
