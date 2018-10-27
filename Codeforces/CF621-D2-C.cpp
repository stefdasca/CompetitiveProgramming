#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#define mod 1000000007
using namespace std;
int n, p;
struct x
{
    int a, b;
};
x v[100003];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    // shuffle(permutation.begin(), permutation.end(), rng);
    cin>>n>>p;
    for(int i = 1; i <= n; ++i)
        cin >> v[i].a >> v[i].b;
    v[n+1] = v[1];
    long double sol = 0.00000;
    for(int i = 1; i <= n; ++i)
    {
        long long cate = (v[i].b / p) - (v[i].a / p) + ((v[i].a % p) == 0);
        long long cate2 = (v[i+1].b / p) - (v[i+1].a / p) + ((v[i+1].a % p) == 0);
        long double chancea = (0.0000 + cate) / (0.0000 + v[i].b - v[i].a + 1.0000);
        long double chanceb = (0.0000 + cate2) / (0.0000 + v[i+1].b - v[i+1].a + 1.0000);
        sol = sol + (1.00000 - (1.00000 - chancea) * (1.00000 - chanceb)) * 2000.0000;
    }
    cout << fixed << setprecision(10) << sol;
    return 0;
}
