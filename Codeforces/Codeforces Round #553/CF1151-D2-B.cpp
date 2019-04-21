#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
long long rand_seed()
{
	long long a = rng();
    return a;
}
int n, m, a[502][502];
int cta[502];
int anss[502];
bool pus[502];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            cin >> a[i][j];
    for(int i = 9; i >= 0; --i)
    {
        int nr = 0;
        memset(cta, 0, sizeof(cta));
        for(int j = 1; j <= n; ++j)
            for(int k = 1; k <= m; ++k)
                if((a[j][k] & (1<<i)))
                    ++cta[j];
        int la = 0;
        for(int j = 1; j <= n; ++j)
            if(cta[j] == m)
                ++la;
        if(la % 2 == 0)
            for(int j = 1; j <= n; ++j)
                if(cta[j] != m && cta[j])
                {
                    ++la;
                    break;
                }
        if(la % 2 == 1)
        {
            cout << "TAK\n";
            la = 0;
            for(int j = 1; j <= n; ++j)
                if(cta[j] == m)
                    anss[j] = 1, ++la, pus[j] = 1;
            if(la % 2 == 0)
                for(int j = 1; j <= n; ++j)
                    if(!pus[j] && cta[j] != m && cta[j] > 0)
                    {
                        pus[j] = 1;
                        ++la;
                        for(int q = 1; q <= m; ++q)
                            if((a[j][q] & (1<<i)))
                                anss[j] = q;
                        break;
                    }
            for(int j = 1; j <= n; ++j)
            {
                if(pus[j])
                    continue;
                for(int q = 1; q <= m; ++q)
                    if(!(a[j][q] & (1<<i)))
                        anss[j] = q;
            }
            for(int j = 1; j <= n; ++j)
                cout << anss[j] << " ";
            return 0;
        }
    }
    cout << "NIE";
    return 0;
}
