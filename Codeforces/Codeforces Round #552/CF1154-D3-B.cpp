#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;
int n, v[101], frq[102], v2[102];
int main()
{

    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> v[i], v2[i] = v[i];
        frq[v[i]] = 1;
    }
    sort(v + 1, v + n + 1);
    if(v[1] == v[n])
    {
        cout << 0;
        return 0;
    }
    int distinct = 0;
    for(int i = 1; i <= 100; ++i)
        distinct += frq[i];
    if(distinct == 2)
    {
        if((v[n] - v[1]) % 2 == 0)
            cout << (v[n] - v[1]) / 2 << '\n';
        else
            cout << (v[n] - v[1]) << '\n';
        return 0;
    }
    for(int i = 0; i <= 200; ++i)
    {
        bool ok = 1;
        for(int j = 1; j <= n; ++j)
            v2[j] = v[j];
        for(int j = 1; j <= n; ++j)
            if(v2[j] == v[1])
                v2[j] += i;
            else
                if(v2[j] == v[n] && v[n] != v[1])
                    v2[j] -= i;
        for(int j = 2; j <= n; ++j)
            if(v2[j] != v2[j-1])
                ok = 0;
        if(ok)
        {
            cout << i;
            return 0;
        }
    }
    cout << -1;
    return 0;
}
