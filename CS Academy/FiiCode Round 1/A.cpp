#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
long long rand_seed()
{
	long long a = rng();
    return a;
}
long long a, b, m;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> a >> b >> m;
    long long aa = a / m;
    long long bb = b / m;
    if(aa == bb)
        cout << b % m;
    else
        cout << m - 1;
    return 0;
}

