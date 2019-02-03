#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
long long n, k, a, b;
int v[100002];
int cb(long long val)
{
    int st = 1;
    int dr = k;
    int ans = 0;
    while(st <= dr)
    {
        int mid = (st + dr) / 2;
        if(v[mid] <= val)
            ans = mid, st = mid + 1;
        else
            dr = mid - 1;
    }
    return ans;
}
long long rec(long long st, long long dr)
{
    long long aa = cb(dr) - cb(st - 1);
    if(aa == 0)
        return a;
    if(st == dr)
        return aa * b;
    long long mid = (st + dr) / 2;
    long long bb = rec(st, mid) + rec(mid + 1, dr);
    return min(bb, b * aa * (dr - st + 1));
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k >> a >> b;
    for(int i = 1; i <= k; ++i)
        cin >> v[i];
    sort(v+1, v+k+1);
    cout << rec(1, (1<<n)) << '\n';
    return 0;
}

