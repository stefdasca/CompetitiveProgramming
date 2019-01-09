/// 2222 by 1 february, thx

#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

int n, k, v[5002], frq[5002], col[5002];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;
    for(int i = 1; i <= n; ++i)
        cin >> v[i], frq[v[i]]++;
    for(int i = 1; i <= 5000; ++i)
        if(frq[i] > k)
        {
            cout << "NO\n";
            return 0;
        }
    int q = 1;
    for(int i = 1; i <= 5000; ++i)
    {
        for(int j = 1; j <= n; ++j)
            if(v[j] == i)
            {
                col[j] = q, ++q;
                if(q > k)
                    q = 1;
            }
    }
    cout << "YES\n";
    for(int i = 1; i <= n; ++i)
        cout << col[i] << " ";
    return 0;
}
