#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int t;
long long a, b;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    for(int i = 1; i <= t; ++i)
    {
        cin >> a >> b;
        long long prd = 9 * (a - 1) + b;
        cout << prd << '\n';
    }
    return 0;
}


