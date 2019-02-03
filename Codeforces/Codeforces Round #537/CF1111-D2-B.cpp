#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int n, k, m;
int v[100002];
bool check(double mx)
{
    long long summ = 0;
    long long nr = 0;
    int op = m;
    for(int i = n; i >= 1; --i)
    {
        ++nr;
        summ += v[i];
        int xx = min(k, max(0, op - (i - 1)));
        summ += xx;
        op -= xx;
        double rapp = (0.0000 + summ) / (0.00000 + nr);
        if(rapp >= mx && op >= (i - 1))
            return 1;

    }
    return 0;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k >> m;
    for(int i = 1; i <= n; ++i)
        cin >> v[i];
    sort(v+1, v+n+1);
    double s = 0.00000;
    double d = 1000000000.000000;
    double ans = 0.0000;
    for(int i = 1; i <= 500; ++i)
    {
        double midd = (s + d) * 0.5000000;
        if(check(midd))
            ans = midd, s = midd;
        else
            d = midd;
    }
    cout << fixed << setprecision(15) << ans;
    return 0;
}

