/*

    * Let's observe that it's always optimal to put sails next to rows with the least number of sails.

    * Let's also observe that the order in which the masts stay doesn't matter, so we will sort them in increasing order
of their height.

    * Now that we found those two observations, we can keep a proper data structure which keeps the row array in decreasing order.
The right data structure for this subproblem is either fenwick tree or segment tree. Then we can simply use binary search to find the
bounds of updates to keep the array sorted and we are set.

    * For more details about the approach I previously mentioned, you can read (https://csacademy.com/contest/round-41/task/candles/solution/).

*/
#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#define fi first
#define se second
#define pb push_back
#define pf push_front
#define mod 1000000007

using namespace std;

typedef long long ll;

struct hei
{
    int h, ct;
};
hei v[100002];
bool cmp(hei a, hei b)
{
    if(a.h == b.h)
        return a.ct > b.ct;
    return a.h < b.h;
}
int n, aib[100002];
ll ans = 0;
void update(int nod, int val)
{
    for(; nod <= 100000; nod += (nod & (-nod)))
        aib[nod] += val;
}
int compute(int nod)
{
    int ans = 0;
    for(; nod; nod -= (nod & (-nod)))
        ans += aib[nod];
    return ans;
}
ll gauss(int n)
{
    return 1LL * n * (n-1) / 2;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> v[i].h >> v[i].ct;
    sort(v+1, v+n+1, cmp);
    for(int i = 1; i <= n; ++i)
    {
        int r = v[i].h;
        int val = compute(r - v[i].ct + 1);
        int st = 1;
        int dr = r - v[i].ct;
        int pz = r - v[i].ct + 1;
        while(st <= dr)
        {
            int mid = (st + dr) / 2;
            if(compute(mid) == val)
                pz = mid, dr = mid - 1;
            else
                st = mid + 1;
        }
        st = r - v[i].ct + 2;
        dr = r;
        int anss = st;
        while(st <= dr)
        {
            int mid = (st + dr) / 2;
            if(compute(mid) == val)
                anss = mid + 1, st = mid + 1;
            else
                dr = mid - 1;
        }
        update(anss, 1);
        update(r+1, -1);
        v[i].ct -= (r - anss + 1);
        update(pz, 1);
        update(pz + v[i].ct, -1);
    }
    for(int i = 1; i <= 100000; ++i)
        ans += gauss(compute(i));
    cout << ans;
    return 0;
}
