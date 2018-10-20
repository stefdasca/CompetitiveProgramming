#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#define mod 1000000007
#define fi first
#define se second
using namespace std;
int n, m, sp[2002][2002], mat[2002][2002];
long long sol, ans;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    // shuffle(permutation.begin(), permutation.end(), rng);
    cin>>n>>m;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
        {
            char x;
            cin >> x;
            if(x == '#')
                sp[i][j] = 1, mat[i][j] = 1;
            sp[i][j] = sp[i][j] + sp[i-1][j] + sp[i][j-1] - sp[i-1][j-1];
        }
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= m; ++j)
        {
            int pos = j;
            while(pos <= m && mat[i][pos] == 0)
            {
                int b = i;
                int e = n;
                int sol = 0;
                while(b <= e)
                {
                    int mid = (b+e)/2;
                    if(sp[mid][pos] - sp[mid][j-1] - sp[i-1][pos] + sp[i-1][j-1] == 0)
                        sol = mid, b = mid + 1;
                    else
                        e = mid - 1;
                }
                ans = ans + 1LL * (sol - i + 1) * (sol - i + 2) / 2 * (pos - j + 1);
                ++pos;
            }
        }
    }
    cout << ans;
    return 0;
}
