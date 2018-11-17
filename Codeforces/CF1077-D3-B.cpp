/// Never do the same mistake twice

#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int n, v[102], k;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> v[i];
    for(int i = 2; i < n; ++i)
        if(v[i] == 0 && v[i-1] == 1 && v[i+1] == 1)
            v[i+1] = 0, ++k;
    cout << k;
    return 0;
}

