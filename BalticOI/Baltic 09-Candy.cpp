/*
        Baltic 09-Candy

    In an optimal assignment of wagons to candies, two paths will never cross.

    Therefore, we will sort the candies in increasing order of the sum of position+time, and run LIS on the resulted array.


*/
#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;

int n;
pair<int, int>arr[100002];

vector<int> wagon;
struct ans
{
    int x, t, poz;
};
ans vans[100002];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 1; i <= n; ++i)
    {
        int x, t;
        cin >> x >> t;
        arr[i] = {x + t, -x + t};
    }
    sort(arr + 1, arr + n + 1);
    for(int i = 1; i <= n; ++i)
    {
        int a = arr[i].fi, b = -arr[i].se;
        int pos = lower_bound(wagon.begin(), wagon.end(), b) - wagon.begin();
        if(pos == wagon.size())
            wagon.push_back(b);
        else
            wagon[pos] = b;
        vans[i] = {(a + b) / 2, (a - b) / 2, pos + 1};
    }
    cout << wagon.size() << '\n';
    for(int i = 1; i <= n; ++i)
        cout << vans[i].x << " " << vans[i].t << " " << vans[i].poz << '\n';
    return 0;
}
