/*
    Sort the elements in ascending order and at first,
drop 1 from each element and drop maximum value too.
If maximum value is still bigger than the previous value, drop the difference
s
*/

#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
long long n, h, sum;
long long arr[100002];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> h;
    long long mx = 0;
    for(int i = 1; i <= n; ++i)
        cin >> arr[i], sum += arr[i], mx = max(mx, arr[i]);
    sort(arr + 1, arr + n + 1);
    long long kpt = 0;
    for(int i = n; i >= 1; --i)
    {
        ++kpt;
        arr[i] = min(arr[i], mx);
        --arr[i];
        --mx;
        if(mx > arr[i-1])
            kpt += (arr[i] - arr[i-1]), mx = arr[i-1];
    }
    cout << sum - kpt;
    return 0;
}
