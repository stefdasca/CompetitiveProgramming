#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int b, k;
int v[100002];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> b >> k;
    int rest = 0;
    int p = 1;
    for(int i = 1; i <= k; ++i)
        cin >> v[i];
    for(int i = k; i >= 1; --i)
    {
        long long z = 1LL * v[i] * p;
        z %= 2;
        rest = (rest + z) % 2;
        p = (p * b) % 2;
    }
    if(rest == 1)
        cout << "odd";
    else
        cout << "even";
    return 0;
}

