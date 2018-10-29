#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#define mod 1000000007
using namespace std;
int n;
int pos[1002];
int ggg[1002];
int dif[1002];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    // shuffle(permutation.begin(), permutation.end(), rng);
    cin>>n;
    int pp = 0;
    for(int i = 1; i <= n; ++i)
        cin >> pos[i], dif[i] = pos[i] - pos[i-1];
    for(int i = 1; i <= n; ++i)
    {
        bool gg = 1;
        for(int j = i+1; j <= n; ++j)
            if(dif[j] != dif[j-i])
                gg = 0;
        if(gg)
            ++pp, ggg[i] = 1;
    }
    cout << pp << '\n';
    for(int i = 1; i <= n; ++i)
        if(ggg[i])
            cout << i << " ";
    return 0;
}
