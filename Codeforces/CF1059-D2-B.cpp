#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#define mod 1000000007
#define fi first
#define se second
using namespace std;
int n, m;
char a[1012][1012];
bool gg[1012][1012];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    // shuffle(permutation.begin(), permutation.end(), rng);
    cin >> n >> m;
    for(int i = 1; i <= n; ++i)
        cin >> (a[i]+1);
    for(int i = 2; i < n; ++i)
        for(int j = 2; j < m; ++j)
        {
            int qx = 1;
            for(int aa = i-1; aa <= i+1; ++aa)
                for(int b = j-1; b <= j+1; ++b)
                {
                    if(aa == i && b == j)
                        continue;
                    if(a[aa][b] != '#')
                        qx = 0;
                }
            if(qx)
                for(int aa = i-1; aa <= i+1; ++aa)
                    for(int b = j-1; b <= j+1; ++b)
                    {
                        if(aa == i && b == j)
                            continue;
                        gg[aa][b] = 1;
                    }
        }
    bool b = 1;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            if(a[i][j] == '#' && !gg[i][j])
                b = 0;
    if(b == 0)
        cout << "NO";
    else
        cout << "YES";
    return 0;
}
