#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#define mod 1000000007
using namespace std;
int n;
int sum, maxi;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    // shuffle(permutation.begin(), permutation.end(), rng);
    cin>>n;
    for(int i = 1; i <= n; ++i)
    {
        int nr;
        cin >> nr;
        sum += nr;
        maxi = max(maxi, nr);
    }
    while(1)
    {
        int nra = sum;
        int nrb = n*maxi - nra;
        if(nrb > nra)
        {
            cout << maxi;
            return 0;
        }
        ++maxi;
    }
    return 0;
}
