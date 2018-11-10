/// Never do the same mistake twice

#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int s, n;
int a[1002];
int b[1002];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> s;
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    for(int i = 1; i <= n; ++i)
        cin >> b[i];
    if(a[1] == 0)
    {
        cout << "NO";
        return 0;
    }
    if(a[s] == 1)
    {
        cout << "YES";
        return 0;
    }
    if(b[s] == 0)
    {
        cout << "NO";
        return 0;
    }
    for(int j = s+1; j <= n; ++j)
        if(a[j] == 1 && b[j] == 1)
        {
            cout << "YES";
            return 0;
        }
    cout << "NO";
    return 0;
}
