#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
long long rand_seed()
{
	long long a = rng();
    return a;
}
int n, a, x, b, y;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> a >> x >> b >> y;
    for(int i = 1; i <= 100000; ++i)
    {
        ++a;
        if(a > n)
            a = 1;
        --b;
        if(b == 0)
            b = n;
        if(a == b)
        {
            cout << "YES";
            return 0;
        }
        if(a == x || b == y)
            break;
    }
    cout << "NO";
    return 0;
}
