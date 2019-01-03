/// Never do the same mistake twice

#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
long long n, m, v[100002], nw[100002];
bool check(long long timp)
{
    for(int i = 1; i <= n; ++i)
        nw[i] = v[i];
    int lft = m-1;
    long long tl = timp - 1;
    for(int i = 1; i <= n; ++i)
    {
        while(nw[i] != 0)
        {
            long long mn = min(tl, nw[i]);
            nw[i] -= mn;
            tl -= mn;
            if(tl == 0 && nw[i] != 0)
            {
                --lft;
                tl = timp - i;
                if(tl <= 0)
                    return 0;
                if(lft < 0)
                    return 0;
            }
        }
        if(i == n)
            break;
        --tl;
        if(tl <= 0)
        {
            --lft;
            tl = timp - (i+1);
            if(tl <= 0)
                return 0;
            if(lft < 0)
                return 0;
        }
    }
    if(lft >= 0)
        return 1;
    return 0;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i = 1; i <= n; ++i)
        cin >> v[i];
    while(v[n] == 0)
        --n;
    long long st = 0;
    long long dr = (1LL<<60);
    long long ans = dr;
    while(st <= dr)
    {
        long long mid = (st + dr) / 2;
        if(check(mid))
            ans = mid, dr = mid - 1;
        else
            st = mid + 1;
    }
    cout << ans;
    return 0;
}

