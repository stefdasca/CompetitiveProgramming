/// Never do the same mistake twice

#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
long long n;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    long long sol = 0;
    while(n)
    {
        if(n % 2 == 0)
        {
            sol += n/2;
            break;
        }
        bool gg = 0;
        for(long long i = 2; i * i <= n; ++i)
            if(n % i == 0)
            {
                gg = 1;
                ++sol;
                n -= i;
                break;
            }
        if(!gg)
        {
            ++sol;
            break;
        }
    }
    cout << sol;
    return 0;
}
