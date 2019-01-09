/// 2222 by 1 february, thx

#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int n;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    if(n % 4 == 0 || n % 4 == 3)
    {
        cout << 0;
        return 0;
    }
    cout << 1;
    return 0;
}
