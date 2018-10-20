#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#define mod 1000000007
#define fi first
#define se second
using namespace std;
int n, m;
int arr[100002], arr2[100002];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    // shuffle(permutation.begin(), permutation.end(), rng);
    cin>>n>>m;
    for(int i = 1; i <= n; ++i)
        cin >> arr[i];
    for(int i = 1; i <= m; ++i)
        cin >> arr2[i];
    sort(arr + 1, arr + n + 1);
    sort(arr2 + 1, arr2 + m + 1);
    if(n == m)
    {
        int sol = 0;
        for(int i = 1; i <= n; ++i)
            sol = max(sol, abs(arr[i] - arr2[i]));
        cout << sol << '\n';
    }
    else
    {
        int b = 0;
        int e = 1000000000;
        int sol = -1;
        while(b <= e)
        {
            int mid = (b+e)/2;
            int mtch = 0;
            if(n < m)
            {
                int pos = 1;
                for(int i = 1; i <= m; ++i)
                    if(abs(arr[pos] - arr2[i]) <= mid && pos <= n)
                        ++pos, ++mtch;
            }
            else
            {
                int pos = 1;
                for(int i = 1; i <= n; ++i)
                    if(abs(arr2[pos] - arr[i]) <= mid && pos <= m)
                        ++pos, ++mtch;
            }
            if(mtch == min(n, m))
                sol = mid, e = mid - 1;
            else
                b = mid + 1;
        }
        cout << sol << '\n';
    }
    return 0;
}
