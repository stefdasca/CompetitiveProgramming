#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
long long n, m, ta, tb, k;
long long fa[200002], fb[200002];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> ta >> tb >> k;
    for(long long i = 1; i <= n; ++i)
        cin >> fa[i];
    for(long long i = 1; i <= m; ++i)
        cin >> fb[i];
    long long pa = min(k, n);
    long long pb = k - pa;
    long long ans = 0;
    while(pa >= 0)
    {
        if(pa == n || pb == m)
        {
            cout << -1;
            return 0;
        }
        long long bst = fa[pa + 1] + ta;
        long long fib = 1;
        long long dd = m;
        long long bbb = -1;
        while(fib <= dd)
        {
            long long mid = (fib + dd) / 2;
            if(fb[mid] >= bst)
                bbb = mid, dd = mid - 1;
            else
                fib = mid + 1;
        }
        if(bbb == -1)
        {
            cout << -1;
            return 0;
        }
        long long st = bbb + pb;
        long long dr = m;
        long long aa = -1;
        while(st <= dr)
        {
            long long mid = (st + dr) / 2;
            if(fb[mid] >= bst)
                aa = mid, dr = mid - 1;
            else
                st = mid + 1;
        }
        if(aa == -1)
        {
            cout << -1;
            return 0;
        }
        ans = max(ans, fb[aa] + tb);
        --pa;
        ++pb;
    }
    cout << ans;
    return 0;
}

