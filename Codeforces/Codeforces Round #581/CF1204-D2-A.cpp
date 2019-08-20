#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#define fi first
#define se second
#define pb push_back

using namespace std;

typedef long long ll;

string s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> s;
    if(s.size() == 1)
    {
        cout << 0;
        return 0;
    }
    int ans = 0;
    for(int i = 1; i <= s.size(); i += 2)
        ans++;
    if(s.size() % 2 == 1)
    {
        int ss = 0;
        for(int j = 0; j < s.size(); ++j)
            ss += (s[j] - '0');
        if(ss == 1)
            --ans;
    }
    cout << ans;
    return 0;
}
