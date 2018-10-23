#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#define mod 1000000007
using namespace std;
long long n, fib[102];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    // shuffle(permutation.begin(), permutation.end(), rng);
    cin>>n;
    fib[1] = 1;
    fib[2] = 1;
    int nr = 2;
    for(int i = 3; ; ++i)
    {
        fib[i] = fib[i-1] + fib[i-2];
        nr = i;
        if(fib[i] > n)
            break;
    }
    for(int i = 0; i <= nr; ++i)
        for(int j = 0; j <= nr; ++j)
            for(int k = 0; k <= nr; ++k)
                if(fib[i] + fib[j] + fib[k] == n)
                {
                    cout << fib[i] << " " << fib[j] << " " << fib[k] << '\n';
                    return 0;
                }
    cout << "I'm too stupid to solve this problem";
    return 0;
}
