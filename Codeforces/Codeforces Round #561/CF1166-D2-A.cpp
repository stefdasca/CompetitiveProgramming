#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
long long rand_seed()
{
	long long a = rng();
    return a;
}
int n;
int frq[28];
string s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 1; i <= n; ++i)
    {
        cin >> s;
        frq[s[0] - 'a']++;
    }
    int ans = 0;
    for(int i = 0; i <= 25; ++i)
    {
        int a = frq[i]/2 + frq[i]%2;
        int b = frq[i]/2;
        ans = ans + (a * (a-1)) / 2;
        ans = ans + (b * (b-1)) / 2;
    }
    cout << ans;
    return 0;
}
