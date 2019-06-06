#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int t;
long long n, k;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    for(; t; --t)
    {
        cin >> n >> k;
        long long ans = 0;
        while(n)
        {
            ans += n%k;
            n -= n%k;
            if(!n)
                break;
            ++ans;
            n /= k;
        }
        cout << ans << '\n';
    }
    return 0;
}

