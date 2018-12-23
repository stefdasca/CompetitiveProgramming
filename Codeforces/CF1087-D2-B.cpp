/// Never do the same mistake twice

#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
long long n, k;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long mini = (1LL<<60);
    cin >> n >> k;
    for(int i = 1; i < k; ++i)
    {
        if(n % i != 0)
            continue;
        long long potential = (n / i) * k + i;
        mini = min(mini, potential);
    }
    cout << mini;
    return 0;
}

