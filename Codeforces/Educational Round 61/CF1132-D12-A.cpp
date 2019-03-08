#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
long long rand_seed()
{
	long long a = rng();
    return a;
}
long long a, b, c, d;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> a >> b >> c >> d;
    long long diff = 2 * a;
    if(c && diff == 0)
    {
        cout << 0;
        return 0;
    }
    diff -= 2 * d;
    if(diff == 0)
    {
        cout << 1;
        return 0;
    }
    cout << 0;
    return 0;
}

