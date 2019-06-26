#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int q;
int n, k;
int v[102];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> q;
    for(; q; --q)
    {
        cin >> n >> k;
        for(int i = 1; i <= n; ++i)
            cin >> v[i];
        sort(v+1, v+n+1);
        if(v[1] + k < v[n] - k)
            cout << -1 << '\n';
        else
            cout << v[1] + k << '\n';
    }
    return 0;
}

