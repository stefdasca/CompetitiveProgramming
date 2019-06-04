#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int n, v[100002], so[100002];
int no, ne;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 1; i <= n; ++i)
    {
        cin >> v[i], so[i] = v[i];
        if(v[i] % 2 == 1)
            ++no;
        else
            ++ne;
    }
    sort(so + 1, so + n + 1);
    if(no == n || ne == n)
    {
        for(int i = 1; i <= n; ++i)
            cout << v[i] << " ";
    }
    else
    {
        for(int i = 1; i <= n; ++i)
            cout << so[i] << " ";
    }
    return 0;
}

