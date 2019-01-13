/// 2222 by 1 february, thx

#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
long long n, r;
double pi = 3.141592653589793;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> r;
    double vall = (180.0000) /(0.0000 + n) * pi;
    vall /= 180.0000;
    double ans = r * sin(vall);
    ans = ans/(1 - sin(vall));
    cout << fixed << setprecision(12) << ans<< '\n';
    return 0;
}

