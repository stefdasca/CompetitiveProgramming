/// 2222 by 1 february, thx

#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int n, m;
int frq[100002];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    int gd = 0;
    for(int i = 1; i <= m; ++i)
    {
        int nr;
        cin >> nr;
        if(frq[nr] == 0)
            ++gd;
        frq[nr]++;
        if(gd == n)
        {
            cout << 1;
            for(int j = 1; j <= n; ++j)
            {
                frq[j]--;
                if(frq[j] == 0)
                    --gd;
            }
        }
        else
            cout << 0;
    }
    return 0;
}


