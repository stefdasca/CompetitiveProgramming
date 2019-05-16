#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
long long rand_seed()
{
	long long a = rng();
    return a;
}
int t;
int n;
string s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    for(; t; --t)
    {
        cin >> n;
        cin >> s;
        bool ok = 0;
        for(int i = 0; i + 10 < n; ++i)
            if(s[i] == '8')
                ok = 1;
        if(ok)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}
