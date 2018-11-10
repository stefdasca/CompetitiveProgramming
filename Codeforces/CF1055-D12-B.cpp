/// Never do the same mistake twice

#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int n, m, s;
int len[100002];
bool bg[100002];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> s;
    for(int i = 1; i <= n; ++i)
        cin >> len[i];
    int ans = 0;
    for(int i = 1; i <= n; ++i)
        if(len[i] > s)
        {
            if(!bg[i-1])
                ++ans;
            bg[i] = 1;
        }
    for(int i = 1; i <= m; ++i)
    {
        int tip;
        cin >> tip;
        if(tip == 0)
        {
            cout << ans << '\n';
        }
        else
        {
            int a, b;
            cin >> a >> b;
            if(!bg[a])
            {
                len[a] += b;
                if(len[a] > s)
                {
                    if(bg[a-1] && bg[a+1])
                        --ans;
                    else
                        if(bg[a-1] || bg[a+1]);
                        else
                            ++ans;
                    bg[a] = 1;
                }
            }
        }
    }
    return 0;
}
