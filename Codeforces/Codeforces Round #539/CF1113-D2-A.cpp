#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
long long rand_seed()
{
	long long a = rng();
    return a;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a, b;
    cin >> a >> b;
    long long cost = min(a - 1, b);
    for(int i = 2; i <= a; ++i)
    {
        if(a - i > b - 1)
            cost += i;
    }
    cout << cost;
    return 0;
}

