#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
long long rand_seed()
{
	long long a = rng();
    return a;
}
int n, m;
int maga[52][10002];
int frq[10002];
int vv[10002];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> m >> n;
    int mn = n+1;
    for(int i = 1; i <= m; ++i)
    {
        cin >> maga[i][0];
        for(int j = 1; j <= maga[i][0]; ++j)
            cin >> maga[i][j];
        sort(maga[i] + 1, maga[i] + maga[i][0] + 1);
    }
    for(int i = 1; i <= m; ++i)
        for(int j = i+1; j <= m; ++j)
        {
            bool ok = 0;
            for(int a = 1, b = 1; a <= maga[i][0] && b <= maga[j][0]; )
                if(maga[i][a] == maga[j][b])
                {
                    ok = 1;
                    break;
                }
                else
                    if(maga[i][a] < maga[j][b])
                        ++a;
                    else
                        ++b;
            if(!ok)
            {
                cout << "impossible";
                return 0;
            }
        }
    cout << "possible";
    return 0;
}

