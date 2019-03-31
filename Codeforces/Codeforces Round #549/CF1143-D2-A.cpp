#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
long long rand_seed()
{
	long long a = rng();
    return a;
}
int n, v[200002], nr0, nr1;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 1; i <= n; ++i)
    {
        cin >> v[i];
        if(v[i] == 0)
            ++nr0;
        else
            ++nr1;
    }
    for(int i = 1; i <= n; ++i)
    {
        if(v[i] == 0)
            --nr0;
        else
            --nr1;
        if(nr0 == 0 || nr1 == 0)
        {
            cout << i;
            return 0;
        }
    }
    return 0;
}

