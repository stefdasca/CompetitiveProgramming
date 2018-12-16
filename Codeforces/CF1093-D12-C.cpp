/// be happy!

#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
long long n, v[100002], sol[200002];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 1; i <= n / 2; ++i)
        cin >> v[i];
    sol[n] = v[1];
    for(int i = 2; i <= n / 2; ++i)
    {
        sol[i] = sol[i-1];
        v[i] -= sol[i-1];
        sol[n - i + 1] = min(v[i], sol[n - i + 2]);
        v[i] -= sol[n - i + 1];
        sol[i] += v[i];
    }
    for(int i = 1; i <= n; ++i)
        cout << sol[i] << " ";
    return 0;
}
