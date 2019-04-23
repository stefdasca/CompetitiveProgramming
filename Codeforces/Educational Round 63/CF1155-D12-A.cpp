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
string s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    cin >> s;
    for(int i = 1; i < n; ++i)
        if(s[i] < s[i-1])
        {
            cout << "YES\n";
            cout << i << " " << i+1 << '\n';
            return 0;
        }
    cout << "NO";
    return 0;
}

