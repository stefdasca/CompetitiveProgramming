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
deque<int>d;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    while(n)
    {
        d.push_front(n%10);
        n /= 10;
    }
    long long ans = 1;
    for(int i = 1; i < d.size(); ++i)
        ans *= 9;
    long long pr = 1;
    for(int i = 0; i < d.size(); ++i)
    {
        long long pr2 = pr;
        for(int dg = (i == 0); dg < d[i] + ((i + 1) == d.size()); ++dg)
        {
            pr2 = pr;
            pr2 *= dg;
            for(int j = i+1; j < d.size(); ++j)
                pr2 *= 9;
            ans = max(ans, pr2);
        }
        pr *= d[i];
    }
    cout << ans;
    return 0;
}

