/// Goodbye until the day we meet again

#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
long long n, k;
string s, t;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;
    cin >> s;
    cin >> t;
    int i = 0;
    long long ans = 0;
    long long unaffected = 1;
    long long dif = n;
    while(dif)
    {
        if(s[i] == t[i])
            unaffected = unaffected * 2 - 1;
        if(s[i] > t[i])
            unaffected = unaffected * 2 - 2;
        if(s[i] < t[i])
            unaffected = unaffected * 2;
        ans += min(k, unaffected);
        if(unaffected > 10 * k)
            unaffected = 5 * k;
        ++i;
        --dif;
    }
    cout << ans;
    return 0;
}
