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
char vv[] = {'a', 'e', 'i', 'o', 'u'};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    string s;
    for(int i = 5; i <= n; ++i)
        if(n % i == 0 && n / i >= 5)
        {
            for(int j = 1; j <= n/i; ++j)
            {
                int st = (j - 1) % 5;
                for(int p = 1; p <= i; ++p)
                {
                    s += vv[st];
                    st++;
                    st %= 5;
                }
            }
            cout << s;
            return 0;
        }
    cout << -1;
    return 0;
}

