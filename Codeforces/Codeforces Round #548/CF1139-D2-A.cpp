#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int n;
string s;
long long ans;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    cin >> s;
    for(int i = 0; i < n; ++i)
    {
        if((s[i] - '0') % 2 == 0)
            ans += (i+1);
    }
    cout << ans;
    return 0;
}

