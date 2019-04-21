#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
long long rand_seed()
{
	long long a = rng();
    return a;
}
int fr;
string s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> s;
    for(int i = 0; i < s.size(); ++i)
        fr += (s[i] == 'a');
    int mxl = 2*fr - 1;
    cout << min(mxl, (int)s.size());
    return 0;
}

