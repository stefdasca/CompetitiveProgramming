#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int n;
int fr[1002];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 1; i <= n; ++i)
    {
        int px;
        cin >> px;
        for(int j = 1; j <= px; ++j)
        {
            int nr;
            cin >> nr;
            fr[nr]++;
        }
    }
    for(int i = 1; i <= 100; ++i)
        if(fr[i] == n)
            cout << i << " ";
    return 0;
}
