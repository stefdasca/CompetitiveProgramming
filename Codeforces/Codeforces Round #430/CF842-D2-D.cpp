#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int n, q, frq[1000005];
int cb(int st, int dr)
{
    int ans = 0;
    int op = (st > 0) * frq[st - 1];
    int ps = st;
    while(st <= dr)
    {
        int mid = (st + dr) / 2;
        if(frq[mid] - op == mid - ps + 1)
            st = mid + 1;
        else
            dr = mid - 1, ans = mid;
    }
    return ans;
}
int xorsum = 0;
int tri(int nr)
{
    int st = nr;
    int dr = nr;
    int cr = 0;
    while(1)
    {
        if(frq[dr] - (st > 0) * frq[st-1] != dr - st + 1)
        {
            if(st == dr)
                return st;
            return tri(nr ^ (1<<(cr-1)));
        }
        if(xorsum & (1<<cr))
            st -= (1<<cr);
        else
            dr += (1<<cr);
        ++cr;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> q;
    for(int i = 1; i <= n; ++i)
    {
        int nr;
        cin >> nr;
        frq[nr] = 1;
    }
    for(int i = 1; i <= 1000001; i++)
        frq[i] += frq[i-1];
    for(int i = 1; i <= q; ++i)
    {
        int nr;
        cin >> nr;
        xorsum ^= nr;
        if(xorsum == 0)
            cout << cb(0, 1000001) << '\n';
        else
        {
            int st = xorsum;
            int dr = xorsum;
            int cr = 0;
            cout << (tri(xorsum) ^ xorsum) << '\n';

        }
    }
    return 0;
}
