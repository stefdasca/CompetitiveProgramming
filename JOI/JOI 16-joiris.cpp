/*

            JOI 16-joiris

    * Let's try to make all towers have the same reminder mod k. We can do this by a traversal from left to right and backwards,
using the following move, one or multiple times: Add a horizontal segment starting at the position i, then make every other tower
have a height at least equal to the height at which the horizontal segment will stand, using the vertical segments.

    * Because this is not guaranteed to work from the given starting position, we need to iterate through the possible values of
height[1] mod k, until we will either find a suitable one, or we run out of tries.

*/
#include<bits/stdc++.h>
using namespace std;
int n, k, nr;
int val[52], val2[52];
pair<int, int>ans[100002];
void proc(int poz, int difference)
{
    int maxi = 0;
    for(int i = poz; i <= poz + k - 1; ++i)
        maxi = max(maxi, val[i]);
    maxi += difference;
    for(int i = 1; i <= difference; ++i)
        ans[++nr] = {2, poz};
    for(int i = 1; i < poz; ++i)
    {
        while(val[i] < maxi)
        {
            val[i] += k;
            ans[++nr] = {1, i};
        }
        val[i] -= difference;
    }
    for(int i = poz + k; i <= n; ++i)
    {
        while(val[i] < maxi)
        {
            val[i] += k;
            ans[++nr] = {1, i};
        }
        val[i] -= difference;
    }
}
void tri()
{
    for(int dstart = 0; dstart < k; ++dstart)
    {
        nr = 0;
        for(int i = 1; i <= n; ++i)
            val[i] = val2[i];
        proc(1, dstart);
        for(int i = 2; i + k - 1 <= n; ++i)
            while(val[i] % k != val[i-1] % k)
                proc(i, 1);
        for(int i = n - k + 2; i >= k + 1; --i)
            while(val[i] % k != val[i-1] % k)
                proc(i - k, 1);
        int mx = val[1];
        bool bad = 0;
        for(int i = 2; i <= n; ++i)
        {
            mx = max(mx, val[i]);
            if(val[i] % k != val[i-1] % k)
                bad = 1;
        }
        for(int i = 1; i <= n; ++i)
        {
            while(val[i] < mx)
            {
                val[i] += k;
                ans[++nr] = {1, i};
            }
        }
        if(nr > 10000)
            bad = 1;
        if(!bad)
        {
            cout << nr << '\n';
            for(int i = 1; i <= nr; ++i)
                cout << ans[i].first << " " << ans[i].second << '\n';
            exit(0);
        }
    }
}
int main()
{
    cin >> n >> k;
    for(int i = 1; i <= n; ++i)
    {
        cin >> val[i];
        val2[i] = val[i];
    }
    tri();
    cout << -1;
    return 0;
}
