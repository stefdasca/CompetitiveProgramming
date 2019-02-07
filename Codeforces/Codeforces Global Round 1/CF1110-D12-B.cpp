#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int n, m, k;
int v[100002];
int dif[100002];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> k;
    for(int i = 1; i <= n; ++i)
        cin >> v[i];
    for(int i = 1; i < n; ++i)
        dif[i] = v[i+1] - v[i];
    sort(dif + 1, dif + n);
    int len = n;
    for(int i = 1; i <= n - k; ++i)
        len = len + dif[i] - 1;
    cout << len;
    return 0;
}

