#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#define fi first
#define se second
#define pb push_back
#define pf push_front

using namespace std;

typedef long long ll;

string s;
ll ans, wu[1000002], wur[1000002];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> s;
    for(int i = 0; i + 1 < s.size(); ++i)
    {
        if(s[i] == 'v' && s[i+1] == 'v')
            wu[i]++, wur[i]++;
    }
    for(int i = 1; i < s.size(); ++i)
        wu[i] += wu[i-1];
    for(int i = s.size()-2; i >= 0; --i)
        wur[i] += wur[i+1];
    for(int i = 1; i < s.size(); ++i)
    {
        if(s[i] == 'o')
        {
            ans += 1LL * wu[i-1] * wur[i+1];
        }
    }
    cout << ans;
    return 0;
}

