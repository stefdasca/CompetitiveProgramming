/// Never do the same mistake twice

#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int n;
string s;
bool eq;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    cin >> s;
    for(int i = 0; i + 1 < s.size(); ++i)
        if(s[i] != s[i+1])
            eq = 1;
    long long ans = 0;
    long long n = s.size();
    if(eq == 0)
    {
        ans = 1LL * (n + 1) * n / 2;
        cout << ans % 998244353 << '\n';
        return 0;
    }
    if(s[0] == s[n-1])
    {
        int lenst = 0;
        while(s[lenst] == s[0])
            ++lenst;
        int lendr = n-1;
        while(s[lendr] == s[n-1])
            --lendr;
        lendr = (n - 1) - lendr;
        ans = 1LL * (lenst + 1) * (lendr + 1);
        ans %= 998244353;
        cout << ans;
        return 0;
    }
    int lenst = 0;
    while(s[lenst] == s[0])
        ++lenst;
    int lendr = n-1;
    while(s[lendr] == s[n-1])
        --lendr;
    lendr = (n - 1) - lendr;
    ans = lenst + lendr + 1;
    cout << ans % 998244353;
    return 0;
}
