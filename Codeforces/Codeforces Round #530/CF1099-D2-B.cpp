#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int n;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    long long ans = 0;
    long long aa = (int)sqrt(n);
    ans = aa;
    if(aa * aa >= n)
        cout << ans * 2;
    else
        if((aa + 1) * aa >= n)
            cout << 2*ans + 1;
        else
            cout << 2*ans + 2;
    return 0;
}

