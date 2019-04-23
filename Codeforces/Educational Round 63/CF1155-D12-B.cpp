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
    s = ' ' + s;
    int nr = 0;
    for(int i = 1; i <= n - 10; ++i)
        if(s[i] == '8')
            ++nr;
    int tt = (n - 11) / 2;
    if(nr > tt)
        cout << "YES";
    else
        cout << "NO";
    return 0;
}

