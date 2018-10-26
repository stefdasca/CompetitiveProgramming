#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#define mod 1000000007
using namespace std;
int n;
int pos[200005];
int pp;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    // shuffle(permutation.begin(), permutation.end(), rng);
    cin>>n;
    for(int i = 1; i <= n; ++i)
    {
        int x;
        cin >> x;
        pos[x] = i;
    }
    for(int i = 1; i <= n; ++i)
    {
        int q;
        cin >> q;
        if(pos[q] > pp)
        {
            cout << pos[q] - pp << " ";
            pp = pos[q];
        }
        else
            cout << 0 << " ";
    }
    return 0;
}
