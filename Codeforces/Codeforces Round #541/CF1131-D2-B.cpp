#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
long long rand_seed()
{
	long long a = rng();
    return a;
}
int n;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    int ans = 1;
    int prv1 = 0, prv2 = 0;
    for(int i = 1; i <= n; ++i)
    {
        int a, b;
        cin >> a >> b;
        if(a == prv1 && b == prv2)
            continue;
        if(prv1 == prv2)
        {
            ans += min(a - prv1, b - prv2);
        }
        else
        {
            if(prv1 > prv2)
                ans += max(0, 1 + min(a - prv1, b - prv1));
            else
                ans += max(0, 1 + min(a - prv2, b - prv2));
        }
        prv1 = a;
        prv2 = b;
    }
    cout << ans;
    return 0;
}

