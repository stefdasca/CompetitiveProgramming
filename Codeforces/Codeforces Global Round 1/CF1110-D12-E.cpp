#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int n;
int a[100002], b[100002];
int c[100002], d[100002];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    for(int i = 1; i <= n; ++i)
        cin >> b[i];
    if(a[1] != b[1] || a[n] != b[n])
    {
        cout << "No";
        return 0;
    }
    for(int i = 1; i < n; ++i)
        c[i] = a[i] - a[i+1];
    for(int i = 1; i < n; ++i)
        d[i] = b[i] - b[i+1];
    sort(c + 1, c + n);
    sort(d + 1, d + n);
    for(int i = 1; i <= n-1; ++i)
        if(c[i] != d[i])
        {
            cout << "No";
            return 0;
        }
    cout << "Yes";
    return 0;
}

