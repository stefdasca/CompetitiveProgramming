#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
long long rand_seed()
{
	long long a = rng();
    return a;
}
long long n, x, y;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> x >> y;
    if(n >= x)
    {
        cout << x - 1;
        return 0;
    }
    long long mx = 0;
    for(int i = 0; i < x; ++i)
    {
        long long sum = 0;
        if(i + n - 1 < x)
        {
            sum = sum + 1LL * (i + n - 1) * (i + n) / 2;
            sum = sum - 1LL * (i - 1) * i / 2;
            if(sum == y)
                mx = max(mx, i + n - 1);
        }
        else
        {
            sum = sum + 1LL * ((x - 1) * x) / 2;
            sum = sum - 1LL * (i - 1) * i / 2;
            long long rm = n - (x - i);
            sum += rm * (rm - 1) / 2;
            if(sum == y)
                mx = max(mx, x - 1);
        }
    }
    cout << mx;
    return 0;
}

