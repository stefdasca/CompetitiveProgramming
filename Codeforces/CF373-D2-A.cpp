#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#define mod 1000000007
using namespace std;
int k, frq[12];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    // shuffle(permutation.begin(), permutation.end(), rng);
    cin >> k;
    for(int i = 1; i <= 16; ++i)
    {
        char c;
        cin >> c;
        if(c != '.')
            frq[(c - '0')]++;
    }
    for(int i = 1; i <= 9; ++i)
        if(frq[i] > 2*k)
        {
            cout << "NO";
            return 0;
        }
    cout << "YES";
    return 0;
}
