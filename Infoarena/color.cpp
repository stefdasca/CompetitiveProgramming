#include<bits/stdc++.h>
using namespace std;
ifstream f("color.in");
ofstream g("color.out");
int n, s;
long long q[4002], ans, ans2;
int main()
{
    f >> n >> s;
    for(int i = 1; i <= s; ++i)
    {
        int a, b;
        f >> a >> b;
        ++q[a], ++q[b];
    }
    ans = 1LL * n * (n-1) * (n-2) / 6;
    for(int i = 1; i <= n; ++i)
        ans2 += 1LL * q[i] * (n - 1 - q[i]);
    g << ans - ans2/2;
    return 0;
}
