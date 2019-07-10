/// HopelessCoder

#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int n;
int v[105];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> v[i];
    v[n+1] = 1001;
    int ans = 0;
    for(int i = 1; i <= n; ++i)
    {
        if(v[i] - v[i-1] > 1)
            continue;
        int q = i;
        while(v[q] - v[q-1] == 1 && v[q+1] - v[q] == 1)
            ++q;
        ans = max(ans, q - i);
    }
    cout << ans;
    return 0;
}
