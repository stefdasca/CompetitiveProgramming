#include<bits/stdc++.h>
using namespace std;
int n, k;
int frq[28];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;
    string s;
    cin >> s;
    for(int j = 0; j < n; ++j)
        frq[s[j] - 'A']++;
    sort(frq, frq + 26);
    long long ans = 0;
    for(int j = 25; j >= 0; --j)
        ans += 1LL * min(k, frq[j]) * min(k, frq[j]), k -= min(k, frq[j]);
    cout << ans;
    return 0;
}
