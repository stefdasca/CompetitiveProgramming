/// Never do the same mistake twice

#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int n, k;
int fr[200002];
int arr[200002];
bool check(int cati)
{
    int qq = 0;
    for(int i = 1; i <= 200000; ++i)
        qq += fr[i] / cati;
    if(qq >= k)
        return 1;
    return 0;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;
    for(int i = 1; i <= n; ++i)
        cin >> arr[i], fr[arr[i]]++;
    int b = 1;
    int e = n / k;
    int ans = 1;
    while(b <= e)
    {
        int mid = (b + e) / 2;
        if(check(mid))
            ans = mid, b = mid + 1;
        else
            e = mid - 1;
    }
    int qa = 0;
    for(int i = 1; i <= 200000; ++i)
    {
        if(qa == k)
            return 0;
        while(fr[i] >= ans && qa < k)
            cout << i << " ", ++qa, fr[i] -= ans;
    }
    return 0;
}

