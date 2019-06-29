#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int n;
int frq[100005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 1; i <= n; ++i)
    {
        int nr;
        cin >> nr;
        frq[nr]++;
    }
    int ss = 0;
    int ans = 0;
    for(int i = 1; i <= 100000; ++i)
    {
        ss += frq[i];
        if(ss + ss == n)
            ++ans;
    }
    cout << ans;
    return 0;
}
