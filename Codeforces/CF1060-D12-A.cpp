#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#define mod 1000000007
#define fi first
#define se second
using namespace std;
int n;
string s;
int nr8;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    // shuffle(permutation.begin(), permutation.end(), rng);
    cin>>n;
    cin>>s;
    for(int i = 0; i < n; ++i)
        if(s[i] == '8')
            ++nr8;
    cout << min(n/11, nr8);
    return 0;
}
