#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int n;
int v[2002];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    int s = 0;
    for(int i = 1; i <= 2 * n; ++i)
        cin >> v[i], s += v[i];
    sort(v + 1, v + 2 * n + 1);
    int ss = 0;
    for(int i = 1; i <= n; ++i)
        ss += v[i];
    if(s - ss == ss)
        cout << -1;
    else
    {
        for(int i = 1; i <= 2 * n; ++i)
            cout << v[i] << " ";
    }
    return 0;
}

