/// Never do the same mistake twice

#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int n;
int v[20];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> v[i];
    for(int i = 0; i < (1<<n); ++i)
    {
        int sum = 0;
        for(int j = 1; j <= n; ++j)
            if(i & (1<<(j-1)))
                sum += v[j];
            else
                sum -= v[j];
        if(sum < 0)
            sum *= -1;
        if(sum % 360 == 0)
        {
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
    return 0;
}
