/// Goodbye until the day we meet again

#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
long long s, n, v[10002];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> s;
    for(int i = 1; i <= n; ++i)
        cin >> v[i];
    sort(v+1, v+n+1, greater<int>());
    for(int i = 1; i <= n; ++i)
    {
        if(s == 0)
            break;
        long long dif = (v[i] - v[i+1]);
        long long pot = dif * i;
        if(s > pot)
            s -= pot;
        else
        {
            v[i] -= s / i;
            if(s % i > 0)
                --v[i];
            cout << min(v[n], v[i]);
            return 0;
        }
    }
    if(s > 0)
    {
        cout << -1;
        return 0;
    }
    return 0;
}
